#include "Core/Engine.h"

using namespace DersEngine;

int main(void)
{
	Engine engine = { 800, 600, "TestGame", true, false };
	engine.Start();
	return 0;
}