#include "Core/Engine.h"
#include "MathLibrary/MathHeaders.h"
#include "Debug/DebugLogging.h"
#include "Utils\FileManager.h"

#include<time.h>
#include<iostream>

using namespace DersEngine;
using namespace Maths;
using namespace Debug;
using namespace Utils;

int main()
{	
	Matrix4f mat = Maths::Translate(Matrix4f(), 3, 8, 2);
	Log(mat.ToString().c_str());

	clock_t time1 = 0, time2 = 0, delta;
	float seconds;

	time1 = clock();

	std::string file = ReadFile("Resources/Shaders/testVertexShader.vert");

	time2 = clock();

	delta = time2 - time1;

	seconds = (((float)delta) / ((float)CLOCKS_PER_SEC));

	Log("The operation took: ", seconds, " seconds.");
	Log(file.c_str());

	Engine engine = { 800, 600, "DersEngine v0.01", true, false };
	engine.Start();
	return 0;
}