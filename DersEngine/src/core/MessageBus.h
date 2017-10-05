#pragma once

#include <memory>
#include <vector>
#include <deque>


namespace engine
{
	namespace core
	{
		class System;

		enum MessageType { TEST };

		struct Message
		{
			MessageType type;
		};

		class MessageBus
		{
			using SystemContainer = std::vector<std::unique_ptr<System>>;
			using MessageQueue = std::deque<Message*>;

		private:
			SystemContainer m_Systems;
			MessageQueue m_MessageQueue;
			
		public:
			MessageBus();
			~MessageBus();

			void AddSystem(std::unique_ptr<System> system);
			void PushMessage(Message* message);
			void ProcessMessageQueue();
		};
	}
}
