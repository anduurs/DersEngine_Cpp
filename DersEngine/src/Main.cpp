#include "graphics\Window.h"

int main(void)
{
	Window window = { 800, 600 };

	while (!window.IsClosed())
	{
		window.PollEvents();
		window.SwapBuffers();
	}

	return 0;
}