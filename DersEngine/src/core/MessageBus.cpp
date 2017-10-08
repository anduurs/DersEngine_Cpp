#include "MessageBus.h"
#include "../systems/System.h"

namespace engine
{
	namespace core
	{
		MessageBus::MessageBus()
		{

		}

		MessageBus::~MessageBus()
		{

		}

		void MessageBus::AddSystem(std::unique_ptr<System> system)
		{
			m_Systems.emplace_back(std::move(system));
		}

		void MessageBus::PushMessage(Message* message)
		{
			m_MessageQueue.push_back(message);
		}

		void MessageBus::ProcessMessageQueue()
		{
			while (m_MessageQueue.size() != 0)
			{
				for (auto& system : m_Systems)
				{
					system->ProcessMessage(*m_MessageQueue[0]);
				}
				m_MessageQueue.pop_front();
			}
		}
	}
}