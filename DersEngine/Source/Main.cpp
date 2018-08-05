#include "Core/GameApplication.h"
#include "MathLibrary/MathHeaders.h"
#include "MathLibrary\Transform.h"
#include "Debug/DebugLogging.h"
#include "Utils\FileManager.h"
#include "Utils\ModelLoader.h"
#include "Graphics\Renderer.h"
#include "Graphics\Shader.h"
#include "Platform\OpenGL\GLTextureLoader.h"
#include "Core/Memory/LinearAllocator.h"
#include "Core\Memory\StackAllocator.h"
#include "ECS/ECS_Manager.h"

#include<time.h>
#include<iostream>

using namespace DersEngine;
using namespace Maths;
using namespace Debug;
using namespace Utils;
using namespace Graphics;
using namespace Memory;
using namespace ECS;

struct TransformComponent : public ComponentData<TransformComponent>
{
	Vec3f position;
	Vec3f scale;
	Quat orientation;
};

int main()
{	
	ECSManager ecs;

	TransformComponent transform;
	transform.position = Vec3f(0.0f, 0.0f, 20.0f);

	ecs.CreateEntity(TransformComponent);

	GameApplication game = { 800, 600, "DersEngine v0.01", true, false };
	game.Start();
	return 0;
}

