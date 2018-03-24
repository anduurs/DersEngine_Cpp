#include "Core/GameApplication.h"
#include "MathLibrary/MathHeaders.h"
#include "MathLibrary\Transform.h"
#include "Debug/DebugLogging.h"
#include "Utils\FileManager.h"
#include "Utils\ModelLoader.h"
#include "Graphics\RenderEngine.h"
#include "Graphics\Shader.h"
#include "Platform\OpenGL\GLTextureLoader.h"
#include "Core/MemoryAllocators/LinearAllocator.h"

#include<time.h>
#include<iostream>

using namespace DersEngine;
using namespace Maths;
using namespace Debug;
using namespace Utils;
using namespace Graphics;
using namespace MemoryManagement;

struct Entity
{
	u32 id;
	Transform transform;
};


struct Component
{
	u32 id;
	u32 a;
	u16 b;
	u8 c;
};


int main()
{	
	Debug::Log(sizeof(Entity));
	LinearAllocator allocator;
	allocator.Reserve(sizeof(Entity) * 64);
	//start: 
	//1840681766764
	Entity* e  = (Entity*)allocator.Allocate(sizeof(Entity), 4);
	Entity* e2 = (Entity*)allocator.Allocate(sizeof(Entity), 8);
	Component* c = (Component*)allocator.Allocate(sizeof(Component), 16);
	Entity* e3 = (Entity*)allocator.Allocate(sizeof(Entity), 4);
	Entity* e4 = (Entity*)allocator.Allocate(sizeof(Entity), 4);
	

	//Material* mat = new Material(shader);
	GameApplication game = { 800, 600, "DersEngine v0.01", true, false };

	//Shader* shader = new Shader("Resources/Shaders/PhongVertexShader.vert", "Resources/Shaders/PhongFragmentShader.frag");
	//Model model = LoadModel("Resources/Models/TestModel/test.fbx", model);
	game.Start();
	return 0;
}