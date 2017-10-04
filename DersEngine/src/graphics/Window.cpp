#include "Window.h"

size_t Window::WIDTH = 0;
size_t Window::HEIGHT = 0;

Window::Window(size_t width, size_t height)
{
	WIDTH = width;
	HEIGHT = height;

	if (!glfwInit())
	{
		std::cout << "Failed to initialize glfw!" << std::endl;
		return;
	}

	m_Window = glfwCreateWindow(width, height, "DersEngine v0.01", NULL, NULL);

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
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(m_Window);
}

bool Window::IsClosed()
{
	return glfwWindowShouldClose(m_Window);
}