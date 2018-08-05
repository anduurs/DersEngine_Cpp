#pragma once

#include "ECS_ComponentData.h"
#include "Core/DataStructures/Array.h"

namespace DersEngine
{
	namespace ECS
	{
		class BaseSystem
		{
		public:
			BaseSystem(const Array<u32>& componentTypes) : m_ComponentTypes(componentTypes) {}
			virtual void UpdateComponents(float deltaTime, BaseComponentData** components) {}
			inline const Array<u32> GetComponentTypes() { return m_ComponentTypes; }
		private:
			Array<u32> m_ComponentTypes;
		};
	}
}