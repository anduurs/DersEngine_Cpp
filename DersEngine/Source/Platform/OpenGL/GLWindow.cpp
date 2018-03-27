#include "Platform\OpenGL\GLWindow.h"
#include "Debug\DebugLogging.h"

namespace DersEngine
{
	namespace Platform
	{
		namespace OpenGL
		{
			void InitGLFW()
			{
				if (!glfwInit())
				{
					std::cout << "Failed to initialize glfw!" << std::endl;
					return;
				}

				glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
				glfwWindowHint(GLFW_STENCIL_BITS, 4);
			}

			GLFWwindow* CreateWindow(u32 width, u32 height, const char* title)
			{
				GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
				const GLFWvidmode* vidMode = glfwGetVideoMode(primaryMonitor);

				GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
				
				if (!window)
				{
					std::cout << "Failed to initialize window!" << std::endl;
					glfwTerminate();
					return nullptr;
				}

				glfwSetWindowPos(window, (vidMode->width - width) / 2, (vidMode->height - height) / 2);

				return window;
			}

			GLFWwindow* CreateFullScreenWindow()
			{
				GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
				const GLFWvidmode* vidMode = glfwGetVideoMode(primaryMonitor);

				GLFWwindow* window = glfwCreateWindow(vidMode->width, vidMode->height, "", primaryMonitor, NULL);

				if (!window)
				{
					std::cout << "Failed to initialize window!" << std::endl;
					glfwTerminate();
					return nullptr;
				}

				return window;
			}

			void CreateGLContext(GLFWwindow* window)
			{
				glfwMakeContextCurrent(window);

				if (glewInit() != GLEW_OK)
				{
					Debug::Log("Failed to initialize glew!");
				}

				std::cout << glGetString(GL_VERSION) << std::endl;
			}

			void SetupEventCallbacks(GLFWwindow* window)
			{
				glfwSetKeyCallback(window, OnKeyEvent);
			}

			void SetVSync(bool enabled)
			{
				enabled ? glfwSwapInterval(1) : glfwSwapInterval(0);
			}

			void PollEvents()
			{
				glfwPollEvents();
			}

			void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (key == GLFW_KEY_E && action == GLFW_PRESS)
				{
					Debug::Log("Key: ", GLFW_KEY_E, " pressed!");
				}
			}

			void SwapBuffers(GLFWwindow* window)
			{
				glfwSwapBuffers(window);
			}

			bool IsWindowOpen(GLFWwindow* window)
			{
				return !glfwWindowShouldClose(window);
			}

			void DestroyWindow()
			{
				Debug::Log("Window destroyed!");
				glfwTerminate();
			}
		}
	}
}