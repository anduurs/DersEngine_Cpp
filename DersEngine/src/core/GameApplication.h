#pragma once

#include <memory>
#include <string>
#include <chrono>
#include <iostream>

#include "../graphics/Window.h"
#include "../utils/Debug.h"

namespace engine
{
	namespace core
	{
		using namespace graphics;

		class GameApplication
		{
		public:
			GameApplication(unsigned int width, unsigned int height,
				const char* title, bool vsync, bool fullScreen);

			~GameApplication();

			void Start();
			void Stop();
		private:
			volatile bool m_Running;
			std::unique_ptr<Window> m_Window;

			void ProcessInputs();
			void Update(float deltaTime);
			void Render();
			void RunGameLoop();
		};
	}
}
