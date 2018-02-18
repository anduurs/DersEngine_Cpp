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

	//Model model;
	//model = LoadModel("Resources/Models/test.obj", model);
	// renderer.Submit(model);

	Engine engine = { 800, 600, "DersEngine v0.01", true, false };
	engine.Start();
	return 0;
}