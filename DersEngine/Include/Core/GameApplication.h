#pragma once

#include <memory>
#include <string>
#include <chrono>
#include <iostream>

#include "Graphics/Window.h"
#include "Debug/DebugLogging.h"

namespace DersEngine
{
	using namespace Graphics;

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
