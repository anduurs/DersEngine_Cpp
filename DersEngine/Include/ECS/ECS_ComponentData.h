#pragma once

#include "Core/Types.h"
#include "Core/DataStructures/Array.h"
#include <tuple>

namespace DersEngine
{
	namespace ECS
	{
		struct BaseComponentData;

		using EntityHandle			  = void*;
		using ComponentCreateFunction = u32 (*)(Array<u8>& memory, EntityHandle entity, BaseComponentData* comp);
		using ComponentFreeFunction	  = void(*)(BaseComponentData* comp);

		#define NULL_ENTITY_HANDLE nullptr

		struct BaseComponentData
		{
		public:
			static u32 RegisterComponentType(ComponentCreateFunction createfn, 
				ComponentFreeFunction freefn, size_t size);
			EntityHandle entity = NULL_ENTITY_HANDLE;

			inline static ComponentCreateFunction GetTypeCreateFunction(u32 id)
			{
				return std::get<0>((*componentTypes)[id]);
			}

			inline static ComponentFreeFunction GetTypeFreeFunction(u32 id)
			{
				return std::get<1>((*componentTypes)[id]);
			}

			inline static size_t GetTypeSize(u32 id)
			{
				return std::get<2>((*componentTypes)[id]);
			}

			inline static bool IsTypeValid(u32 id)
			{
				return id < componentTypes->size();
			}
		private:
			static Array<std::tuple<ComponentCreateFunction, ComponentFreeFunction, size_t>>* componentTypes;
		};

		template<typename T>
		struct ComponentData : public BaseComponentData
		{
			static const ComponentCreateFunction CREATE_FUNCTION;
			static const ComponentFreeFunction FREE_FUNCTION;
			static const u32 ID;
			// size of the component in bytes
			static const size_t SIZE;
		};

		template<typename T>
		u32 CreateComponent(Array<u8>& memory, EntityHandle entity, BaseComponentData* comp)
		{
			u32 index = memory.size();
			memory.resize(index + Component::SIZE);
			T* component = new(&memory[index]) T(*(T*)comp);
			component->entity = entity;
			return index;
		}

		template<typename T>
		void FreeComponent(BaseComponentData* comp)
		{
			Component* component = (T*)comp;
			component->~Component();
		}

		template<typename T>
		const u32 ComponentData<T>::ID(BaseComponentData::RegisterComponentType(CreateComponent<T>, FreeComponent<T>, sizeof(T)));

		template<typename T>
		const size_t ComponentData<T>::SIZE(sizeof(T));

		template<typename T>
		const ComponentCreateFunction ComponentData<T>::CREATE_FUNCTION(CreateComponent<T>);

		template<typename T>
		const ComponentFreeFunction ComponentData<T>::FREE_FUNCTION(FreeComponent<T>);


		// EXAMPLE USAGE
		struct TestComponentData : public ComponentData<TestComponentData>
		{
			float x;
			float y;
		};
	}
}