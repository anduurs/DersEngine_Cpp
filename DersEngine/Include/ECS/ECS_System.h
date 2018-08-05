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
			enum
			{
				FLAG_OPTIONAL = 1,
			};

			BaseSystem();

			virtual void UpdateComponents(float deltaTime, BaseComponentData** components) {}

			bool IsValid();

			inline const Array<u32> GetComponentTypes() { return m_ComponentTypes; }
			inline const Array<u32> GetComponentFlags() { return m_ComponentFlags; }

		protected:
			void AddComponentType(u32 componentType, u32 componentFlag = 0);

		private:
			Array<u32> m_ComponentTypes;
			Array<u32> m_ComponentFlags;
		};

		class ECSSystemList
		{
		public:
			bool AddSystem(BaseSystem& system);
			bool RemoveSystem(BaseSystem& system);

			inline size_t Size() { return m_Systems.size(); }
			inline BaseSystem* operator[](u32 index) { return m_Systems[index]; }
	
		private:
			Array<BaseSystem*> m_Systems;
		};
	}
}