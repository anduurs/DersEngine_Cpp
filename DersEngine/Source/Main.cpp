#include "Core/Engine.h"
#include "MathLibrary/MathHeaders.h"
#include "Debug/DebugLogging.h"
#include "Utils\FileManager.h"
#include "Utils\ModelLoader.h"
#include "Graphics\RenderEngine.h"
#include "Graphics\Shader.h"
#include "Platform\OpenGL\GLTextureLoader.h"
#include "Memory\StackAllocator.h"

#include<time.h>
#include<iostream>

using namespace DersEngine;
using namespace Maths;
using namespace Debug;
using namespace Utils;
using namespace Graphics;

class Entity
{

};


int main()
{	
	

	

	//Material* mat = new Material(shader);
	
	

	Engine engine = { 800, 600, "DersEngine v0.01", true, false };

	Shader* shader = new Shader("Resources/Shaders/PhongVertexShader.vert", "Resources/Shaders/PhongFragmentShader.frag");
	Model model = LoadModel("Resources/Models/TestModel/test.fbx", model);
	engine.Start();
	return 0;
}