#pragma once

namespace engine
{
	namespace core
	{
		class MessageBus;
		struct Message;

		class System
		{
		protected:
			MessageBus* m_MessageBus;

		public:
			void ProcessMessage(const Message& msg);

		};
	}
}