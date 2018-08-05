#include "ECS/ECS_System.h"

namespace DersEngine
{
	namespace ECS
	{
		BaseSystem::BaseSystem()
		{
		}

		bool BaseSystem::IsValid()
		{
			for (const auto& flag : m_ComponentFlags)
			{
				if ((flag & FLAG_OPTIONAL) == 0)
				{
					return true;
				}
			}
			
			return false;
		}

		void BaseSystem::AddComponentType(u32 componentType, u32 componentFlag)
		{
			m_ComponentTypes.push_back(componentType);
			m_ComponentFlags.push_back(componentFlag);
		}

		bool ECSSystemList::AddSystem(BaseSystem& system)
		{
			if (!system.IsValid())
			{
				return false;
			}

			m_Systems.emplace_back(&system);
			return true;
		}

		bool ECSSystemList::RemoveSystem(BaseSystem& system)
		{
			for (u32 i = 0; i < m_Systems.size(); i++)
			{
				if (&system == m_Systems[i])
				{
					m_Systems.erase(m_Systems.begin() + i);
					return true;
				}
			}

			return false;
		}
	}
}