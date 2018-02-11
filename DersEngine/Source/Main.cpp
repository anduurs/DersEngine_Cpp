#include "Core/Engine.h"
#include "MathLibrary/MathUtil.h"

using namespace DersEngine;
using namespace Maths;
using namespace Debug;

int main()
{
	Vector3f vec1 = { 2.0f, 1.0f, 5.0f };
	Vector3f vec2 = { 5.0f, 9.0f, 3.0f };

	Vector2f v = { 1.0f, 2.0f };

	Quaternion quat = { 0,0,0,0 };

	float distance = Maths::Distance(vec1, vec2);

	Log(distance);

	Engine engine = { 800, 600, "DersEngine v0.01", true, false };
	engine.Start();
	return 0;
}