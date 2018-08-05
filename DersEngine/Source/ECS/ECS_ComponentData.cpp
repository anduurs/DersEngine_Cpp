#include "ECS/ECS_ComponentData.h"

namespace DersEngine
{
	namespace ECS
	{
		Array<std::tuple<ComponentCreateFunction, ComponentFreeFunction, size_t>>* BaseComponentData::componentTypes;

		u32 BaseComponentData::RegisterComponentType(ComponentCreateFunction createfn,
			ComponentFreeFunction freefn, size_t size)
		{
			if (!componentTypes)
			{
				componentTypes = new Array<std::tuple<ComponentCreateFunction, ComponentFreeFunction, size_t>>();
			}

			u32 componentID = componentTypes->size();
			componentTypes->emplace_back(std::tuple<ComponentCreateFunction, ComponentFreeFunction, size_t>(createfn, freefn, size));
			return componentID;
		}
	}
}