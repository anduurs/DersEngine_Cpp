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

			Window(unsigned int width, unsigned int height,
				const char* title, bool vsync, bool fullScreen);
			~Window();

			void PollEvents();
			void SwapBuffers();
			bool IsOpen();
		};
	}
}


