#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
private:
	GLFWwindow* m_Window;
public:
	static size_t WIDTH;
	static size_t HEIGHT;

	Window(size_t width, size_t height);
	~Window();

	void PollEvents();
	void SwapBuffers();
	bool IsClosed();
};
