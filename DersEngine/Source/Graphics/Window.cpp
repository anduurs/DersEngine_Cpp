#include "Graphics/Window.h"

namespace DersEngine
{
	namespace Graphics
	{
		unsigned int Window::WIDTH = 0;
		unsigned int Window::HEIGHT = 0;

		Window::Window(unsigned int width, unsigned int height,
			const char* title, bool vsync, bool fullScreen)
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize glfw!" << std::endl;
				return;
			}

			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
			glfwWindowHint(GLFW_STENCIL_BITS, 4);

			auto primaryMonitor = glfwGetPrimaryMonitor();
			auto vidMode = glfwGetVideoMode(primaryMonitor);

			if (fullScreen)
			{
				WIDTH = vidMode->width;
				HEIGHT = vidMode->height;

				m_Window = glfwCreateWindow(WIDTH, HEIGHT, title, primaryMonitor, NULL);
			}
			else
			{
				WIDTH = width;
				HEIGHT = height;

				m_Window = glfwCreateWindow(WIDTH, HEIGHT, title, NULL, NULL);
				glfwSetWindowPos(m_Window, (vidMode->width - WIDTH) / 2, (vidMode->height - HEIGHT) / 2);
			}

			if (!m_Window)
			{
				std::cout << "Failed to initialize window!" << std::endl;
				glfwTerminate();
				return;
			}

			glfwMakeContextCurrent(m_Window);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Failed to initialize glew!" << std::endl;
			}

			vsync ? glfwSwapInterval(1) : glfwSwapInterval(0);

			std::cout << glGetString(GL_VERSION) << std::endl;
		}

		Window::~Window()
		{
			std::cout << "Window destroyed!" << std::endl;
			glfwTerminate();
		}

		void Window::PollEvents()
		{
			glfwPollEvents();
		}

		void Window::SwapBuffers()
		{
			//TODO: Move this to render engine later
			glClearColor(0, 0.2f, 0.3f, 0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glfwSwapBuffers(m_Window);
		}

		bool Window::IsOpen()
		{
			return !glfwWindowShouldClose(m_Window);
		}
	}
}

