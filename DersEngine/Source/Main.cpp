#include "Core/Engine.h"
#include "MathLibrary/MathHeaders.h"
#include "Debug/DebugLogging.h"
#include "Utils\FileManager.h"
#include "Utils\ModelLoader.h"
#include "Graphics\ModelRenderer.h"
#include "Graphics\Shader.h"

#include<time.h>
#include<iostream>

using namespace DersEngine;
using namespace Maths;
using namespace Debug;
using namespace Utils;

int main()
{	
	Model model;
	model = LoadModel("Resources/Models/test.obj", model);

	ModelRenderer renderer;

	renderer.Submit(model);
	// renderer.Submit(model);

	Engine engine = { 800, 600, "DersEngine v0.01", true, false };
	engine.Start();
	return 0;
}