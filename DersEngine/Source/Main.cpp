#include "Core/Engine.h"
#include "MathLibrary/MathHeaders.h"

using namespace DersEngine;
using namespace Maths;
using namespace Debug;

int main()
{
	Engine engine = { 800, 600, "DersEngine v0.01", true, false };
	engine.Start();
	return 0;
}