#pragma once

#include "ECS_ComponentData.h"
#include "ECS_System.h"
#include "Core/DataStructures/Map.h"
#include "Core/Common.h"
#include <cstring>
#include "MathLibrary/MathUtil.h"

namespace DersEngine
{
	namespace ECS
	{
		class ECSManager
		{
			using ComponentID = u32;
			using ComponentIndex = u32;
			using EntityID = u32;
			using ComponentsArray = Array<std::pair<ComponentID, ComponentIndex>>;
			using Entity = std::pair<EntityID, ComponentsArray>;

		public:
			ECSManager();
			~ECSManager();

			// Entity functions
			EntityHandle CreateEntity(BaseComponentData** components, const u32* componentIDs, size_t numOfComponents);

			void RemoveEntity(EntityHandle handle);

			template<class ...Args>
			EntityHandle CreateEntity(Args&... args)
			{
				Array<BaseComponentData*> components = { args... };
				Array<u32> componentIDs;

				for (int i = 0; i < components.size(); i++)
				{
					componentIDs.emplace_back(components[i]::ID);
				}
				
				return CreateEntity(components, componentIDs, components.size());
			}

			// Component functions
			template<class T>
			inline void AddComponent(EntityHandle entity, T* component)
			{
				AddComponentInternal(entity, HandleToEntity(entity), T::ID, component);
			}

			template<class T>
			inline bool RemoveComponent(EntityHandle entity)
			{
				return RemoveComponentInternal(entity, T::ID);
			}

			template<class T>
			inline BaseComponentData* GetComponent(EntityHandle entity)
			{
				return (T*) GetComponentInternal(HandleToEntity(entity), m_Components[T::ID], T::ID);
			}

			// System functions
			void UpdateSystems(ECSSystemList& systems, float deltaTime);

		private:
			Map<u32, Array<u8>> m_Components;
			Array<Entity*> m_Entities;

			void DeleteComponent(u32 componentID, u32 index);

			bool RemoveComponentInternal(EntityHandle handle, u32 componentID);

			void AddComponentInternal(EntityHandle handle, ComponentsArray& entityComponents, 
				u32 componentID, BaseComponentData* component);

			BaseComponentData* GetComponentInternal(ComponentsArray& entityComponents, Array<u8>& array, u32 componentID);

			void UpdateSystemWithMultipleComponents(BaseSystem& system, ECSSystemList& systems, float deltaTime,
				const Array<u32>& componentTypes, Array<BaseComponentData*>& componentParams, Array<Array<u8>*>& componentArrays);

			u32 FindLeastCommonComponent(const Array<u32>& componentTypes, const Array<u32>& componentFlags);

			inline Entity* HandleToRawType(EntityHandle handle)
			{
				return (Entity*)handle;
			}

			inline u32 HandleToEntityIndex(EntityHandle handle)
			{
				return HandleToRawType(handle)->first;
			}

			inline ComponentsArray& HandleToEntity(EntityHandle handle)
			{
				return HandleToRawType(handle)->second;
			}
		};
	}
}
