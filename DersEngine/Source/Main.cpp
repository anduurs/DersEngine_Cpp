#include "Core/Engine.h"
#include "MathLibrary/MathLibrary.h"
#include "Utils/Debug.h"

using namespace DersEngine;
using namespace Maths;
using namespace Debug;

int main()
{
	Vector3f vec1 = { 2.0f, 1.0f, 5.0f };
	Vector3f vec2 = { 5.0f, 9.0f, 3.0f };

	Vector2f v1 = { 2.0f, 1.0f };
	Vector2f v2 = { 5.0f, 9.0f };

	float distance = Maths::Distance(vec1, vec2);
	float distance2 = Maths::Distance(v1, v2);

	Log(distance2);
	Log(distance);

	Engine engine = { 800, 600, "DersEngine v0.01", true, false };
	engine.Start();
	return 0;
}