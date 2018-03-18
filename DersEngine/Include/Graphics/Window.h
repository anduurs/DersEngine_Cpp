#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace DersEngine
{
	namespace Graphics
	{
		class Window
		{
		private:
			GLFWwindow* m_Window;
		public:
			static unsigned int WIDTH;
			static unsigned int HEIGHT;

			void Init();
			void CreateWindow(unsigned int width, unsigned int height, const char* title);
			void CreateFullScreenWindow();
			void CreateGLContext();
			void SetupEventCallbacks();
			void SetVSync(bool enabled);
			void PollEvents();
			static void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods);
			void SwapBuffers();
			bool IsOpen();
			void Destroy();
		};
	}
}


