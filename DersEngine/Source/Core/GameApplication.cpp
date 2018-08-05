#include "Core/GameApplication.h"

namespace DersEngine
{
	GameApplication::GameApplication(unsigned int width, unsigned int height,
		const char* title, bool vsync, bool fullScreen)
	{
		m_Window = std::make_unique<Window>();
		m_Window->Init();
		
		if (fullScreen)
		{
			m_Window->CreateFullScreenWindow();
		}
		else
		{
			m_Window->CreateWindow(width, height, title);
		}

		m_Window->CreateGLContext();
		m_Window->SetupEventCallbacks();
		m_Window->SetVSync(vsync);
	}

	GameApplication::~GameApplication()
	{

	}

	void GameApplication::Init()
	{

	}

	void GameApplication::Start()
	{
		std::cout << "Game engine started" << std::endl;
		m_Running = true;
		RunGameLoop();
	}

	void GameApplication::Stop()
	{
		std::cout << "Game engine stopped" << std::endl;
		m_Running = false;
	}

	void GameApplication::ProcessInput()
	{
		m_Window->PollEvents();
	}

	void GameApplication::Update(float deltaTime)
	{
		//Update game logic
	}

	void GameApplication::Render()
	{
		//Render scene

		m_Window->SwapBuffers();
	}

	void GameApplication::RunGameLoop()
	{
		auto previousTime = std::chrono::high_resolution_clock::now();

		double elapsedTimeInSeconds = 0.0;
		double accumulator = 0.0;
		double frameCounter = 0.0;

		int fps = 0;
		int tps = 0;

		const double TARGET_UPS = 60.0;
		const double SECONDS_PER_UPDATE = 1.0 / TARGET_UPS;
		float dt = (float)SECONDS_PER_UPDATE;

		while (m_Running)
		{
			auto currentTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsedTime = currentTime - previousTime;

			elapsedTimeInSeconds = elapsedTime.count();

			if (elapsedTimeInSeconds > 0.25)
			{
				elapsedTimeInSeconds = 0.25;
			}

			accumulator += elapsedTimeInSeconds;
			frameCounter += elapsedTimeInSeconds;

			previousTime = currentTime;

			while (accumulator >= SECONDS_PER_UPDATE)
			{
				ProcessInput();

				Update(dt);

				tps++;
				accumulator -= SECONDS_PER_UPDATE;
			}

			Render();
			fps++;

			if (frameCounter >= 1)
			{
				//Debug::Log(fps, " fps, ", tps, " tps");
				fps = 0;
				tps = 0;
				frameCounter = 0;
			}

			if (!m_Window->IsOpen())
			{
				Stop();
			}
		}
	}
}

