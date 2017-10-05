#include "core\GameApplication.h"

int main(int c, char* args[])
{
	using namespace engine;

	core::GameApplication game = { 800, 600, "DersEngine v0.01", true, false };
	game.Start();

	return 0;
}