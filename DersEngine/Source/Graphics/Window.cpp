#include "Graphics/Window.h"
#include "Debug\DebugLogging.h"

namespace DersEngine
{
	namespace Graphics
	{
		unsigned int Window::WIDTH = 0;
		unsigned int Window::HEIGHT = 0;

		void Window::Init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize glfw!" << std::endl;
				return;
			}

			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
			glfwWindowHint(GLFW_STENCIL_BITS, 4);
		}

		void Window::CreateWindow(unsigned int width, unsigned int height, const char* title)
		{
			GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* vidMode = glfwGetVideoMode(primaryMonitor);

			WIDTH = width;
			HEIGHT = height;

			m_Window = glfwCreateWindow(WIDTH, HEIGHT, title, NULL, NULL);
			glfwSetWindowPos(m_Window, (vidMode->width - WIDTH) / 2, (vidMode->height - HEIGHT) / 2);

			if (!m_Window)
			{
				std::cout << "Failed to initialize window!" << std::endl;
				glfwTerminate();
				return;
			}
		}

		void Window::CreateFullScreenWindow()
		{
			GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* vidMode  = glfwGetVideoMode(primaryMonitor);

			WIDTH = vidMode->width;
			HEIGHT = vidMode->height;

			m_Window = glfwCreateWindow(WIDTH, HEIGHT, "", primaryMonitor, NULL);

			if (!m_Window)
			{
				std::cout << "Failed to initialize window!" << std::endl;
				glfwTerminate();
				return;
			}
		}

		void Window::CreateGLContext()
		{
			glfwMakeContextCurrent(m_Window);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Failed to initialize glew!" << std::endl;
			}

			std::cout << glGetString(GL_VERSION) << std::endl;
		}

		void Window::SetupEventCallbacks()
		{
			glfwSetKeyCallback(m_Window, OnKeyEvent);
		}

		void Window::SetVSync(bool enabled)
		{
			enabled ? glfwSwapInterval(1) : glfwSwapInterval(0);
		}

		void Window::PollEvents()
		{
			glfwPollEvents();
		}

		void Window::OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_E && action == GLFW_PRESS)
			{
				Debug::Log("Key: ", GLFW_KEY_E, " pressed!");
			}
		}

		void Window::SwapBuffers()
		{
			glfwSwapBuffers(m_Window);
		}

		bool Window::IsOpen()
		{
			return !glfwWindowShouldClose(m_Window);
		}

		void Window::Destroy()
		{
			std::cout << "Window destroyed!" << std::endl;
			glfwTerminate();
		}
	}
}

