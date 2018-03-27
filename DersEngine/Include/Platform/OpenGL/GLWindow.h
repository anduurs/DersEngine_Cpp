#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Core\Types.h"

namespace DersEngine
{
	namespace Platform
	{
		namespace OpenGL
		{
			void InitGLFW();
			GLFWwindow* CreateWindow(u32 width, u32 height, const char* title);
			GLFWwindow* CreateFullScreenWindow();
			void CreateGLContext(GLFWwindow* window);
			void SetupEventCallbacks(GLFWwindow* window);
			void SetVSync(bool enabled);
			void PollEvents();
			void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods);
			void SwapBuffers(GLFWwindow* window);
			bool IsWindowOpen(GLFWwindow* window);
			void DestroyWindow();
		}
	}
}
