#include "ECS/ECS_Manager.h"

namespace DersEngine
{
	namespace ECS
	{
		ECSManager::ECSManager()
		{

		}

		ECSManager::~ECSManager()
		{
			for (auto it = m_Components.begin(); it != m_Components.end(); ++it)
			{
				size_t typeSize = BaseComponentData::GetTypeSize(it->first);
				ComponentFreeFunction freefn = BaseComponentData::GetTypeFreeFunction(it->first);

				for (u32 i = 0; i < it->second.size(); i += typeSize)
				{
					freefn((BaseComponentData*)&it->second[i]);
				}
			}

			for (u32 i = 0; i < m_Entities.size(); i++)
			{
				delete m_Entities[i];
			}
		}

		EntityHandle ECSManager::CreateEntity(BaseComponentData** components, const u32* componentIDs, size_t numOfComponents)
		{
			Entity* newEntity = new Entity();
			EntityHandle handle = (EntityHandle)newEntity;

			// Create the components for this entity
			for (u32 i = 0; i < numOfComponents; i++)
			{
				u32 componentID = componentIDs[i];

				if (!BaseComponentData::IsTypeValid(componentID))
				{
					DEBUG_LOG("ECS", LOG_ERROR, "'%u' is not a valid component type.", componentID);
					delete newEntity;
					return NULL_ENTITY_HANDLE;
				}

				AddComponentInternal(handle, newEntity->second, componentID, components[i]);
			}

			newEntity->first = m_Entities.size();
			m_Entities.emplace_back(newEntity);

			return handle;
		}

		void ECSManager::RemoveEntity(EntityHandle handle)
		{
			ComponentsArray& entityComponents = HandleToEntity(handle);

			for (u32 i = 0; i < entityComponents.size(); i++)
			{
				DeleteComponent(entityComponents[i].first, entityComponents[i].second);
			}

			u32 destIndex = HandleToEntityIndex(handle);
			u32 srcIndex  = m_Entities.size() - 1;

			delete m_Entities[destIndex];

			// Copy the entity from the end of the list to the dest index which now has been cleared
			m_Entities[destIndex] = m_Entities[srcIndex];
			// Update the entity index since it no longer is the last entity
			m_Entities[destIndex]->first = destIndex;
			// Then remove the last entity which has been safely copied to the dest index
			m_Entities.pop_back();
		}

		void ECSManager::UpdateSystems(ECSSystemList& systems, float deltaTime)
		{
			Array<BaseComponentData*> componentParams;
			Array<Array<u8>*> componentArrays;
	
			for (int i = 0; i < systems.Size(); i++)
			{
				const Array<u32> componentTypes = systems[i]->GetComponentTypes();

				if (componentTypes.size() == 1)
				{
					size_t typeSize = BaseComponentData::GetTypeSize(componentTypes[0]);
					Array<u8>& components = m_Components[componentTypes[0]];

					for (u32 j = 0; j < components.size(); j += typeSize)
					{
						BaseComponentData* component = (BaseComponentData*)&components[j];
						systems[i]->UpdateComponents(deltaTime, &component);
					}
				}
				else
				{
					UpdateSystemWithMultipleComponents(*systems[i], systems, deltaTime, componentTypes, componentParams, componentArrays);
				}
			}
		}

		void ECSManager::DeleteComponent(u32 componentID, u32 index)
		{
			Array<u8>& array = m_Components[componentID];
			ComponentFreeFunction freefn = BaseComponentData::GetTypeFreeFunction(componentID);
			size_t typeSize = BaseComponentData::GetTypeSize(componentID);
			u32 srcIndex = array.size() - typeSize;

			BaseComponentData* srcComponent  = (BaseComponentData*)&array[srcIndex];
			BaseComponentData* destComponent = (BaseComponentData*)&array[index];

			freefn(destComponent);

			if (index == srcIndex)
			{
				array.resize(srcIndex);
				return;
			}

			memcpy(destComponent, srcComponent, typeSize);

			ComponentsArray& srcComponents = HandleToEntity(srcComponent->entity);

			for (u32 i = 0; i < srcComponents.size(); i++)
			{
				if (componentID == srcComponents[i].first && srcIndex == srcComponents[i].second)
				{
					srcComponents[i].second = index;
					break;
				}
			}

			array.resize(srcIndex);
		}

		bool ECSManager::RemoveComponentInternal(EntityHandle handle, u32 componentID)
		{
			ComponentsArray& entityComponents = HandleToEntity(handle);

			for (u32 i = 0; i < entityComponents.size(); i++)
			{
				if (componentID == entityComponents[i].first)
				{
					DeleteComponent(componentID, entityComponents[i].second);
					u32 srcIndex  = entityComponents.size() - 1;
					u32 destIndex = i;
					entityComponents[destIndex] = entityComponents[srcIndex];
					entityComponents.pop_back();
					return true;
				}
			}

			return false;
		}

		void ECSManager::AddComponentInternal(EntityHandle handle, ComponentsArray& entityComponents, u32 componentID, BaseComponentData* component)
		{
			ComponentCreateFunction createfn = BaseComponentData::GetTypeCreateFunction(componentID);

			std::pair<u32, u32> newPair;
			newPair.first = componentID;
			newPair.second = createfn(m_Components[componentID], handle, component);
			entityComponents.emplace_back(newPair);
		}

		BaseComponentData* ECSManager::GetComponentInternal(ComponentsArray& entityComponents, Array<u8>& array, u32 componentID)
		{
			for (const auto& component : entityComponents)
			{
				if (component.first == componentID)
				{
					return (BaseComponentData*)&array[component.second];
				}
			}

			return nullptr;
		}

		void ECSManager::UpdateSystemWithMultipleComponents(BaseSystem& system, ECSSystemList& systems, float deltaTime,
				const Array<u32>& componentTypes, Array<BaseComponentData*>& componentParams, Array<Array<u8>*>& componentArrays)
		{
			const Array<u32>& componentFlags = system.GetComponentFlags();

			componentParams.resize(Maths::MaxInt(componentParams.size(), componentTypes.size()));
			componentArrays.resize(Maths::MaxInt(componentArrays.size(), componentTypes.size()));

			for (const auto& componentType : componentTypes)
			{
				componentArrays.emplace_back(&m_Components[componentType]);
			}

			u32 minSizeIndex = FindLeastCommonComponent(componentTypes, componentFlags);

			size_t typeSize = BaseComponentData::GetTypeSize(componentTypes[minSizeIndex]);
			Array<u8>& array = *componentArrays[minSizeIndex];

			for (u32 i = 0; i < array.size(); i += typeSize)
			{
				componentParams[minSizeIndex] = (BaseComponentData*)&array[i];
				ComponentsArray& entityComponents = HandleToEntity(componentParams[minSizeIndex]->entity);

				bool isValid = true;

				for (int j = 0; j < componentTypes.size(); j++)
				{
					if (j == minSizeIndex)
					{
						continue;
					}

					componentParams[j] = GetComponentInternal(entityComponents, *componentArrays[j], componentTypes[j]);

					if (!componentParams[j] && (componentFlags[j] & BaseSystem::FLAG_OPTIONAL) == 0)
					{
						isValid = false;
						break;
					}
				}

				if (isValid)
				{
					system.UpdateComponents(deltaTime, &componentParams[minSizeIndex]);
				}
			}
		}

		u32 ECSManager::FindLeastCommonComponent(const Array<u32>& componentTypes, const Array<u32>& componentFlags)
		{
			u32 minSize  = (u32)-1;
			u32 minIndex = (u32)-1;

			for (u32 i = 0; i < componentTypes.size(); i++)
			{
				if ((componentFlags[i] & BaseSystem::FLAG_OPTIONAL) != 0)
				{
					continue;
				}

				size_t typeSize = BaseComponentData::GetTypeSize(componentTypes[i]);
				u32 size = m_Components[componentTypes[i]].size() / typeSize;

				if (size <= minSize)
				{
					minSize  = size;
					minIndex = i;
				}
			}

			return minIndex;
		}
	}
}