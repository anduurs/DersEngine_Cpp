#include "Core/Engine.h"
#include "MathLibrary/MathHeaders.h"

using namespace DersEngine;
using namespace Maths;
using namespace Debug;

int main()
{
	Matrix4f translationMatrix = Maths::Translate(Matrix4f(), 10.0f, 3.0f, 7.0f);
	Matrix4f scalingMatrix = Maths::Scale(Matrix4f(), 5.0f, 5.0f, 5.0f);
	
	Matrix4f resMat = translationMatrix * scalingMatrix;

	//Log(translationMatrix.ToString().c_str());
	//Log(scalingMatrix.ToString().c_str());

	//Log(resMat.ToString().c_str());

	float r = Maths::ToRadians(45.0f);
	float d = Maths::ToDegrees(0.785398f);
	//Log("Radians: ", r);
	//Log("Degrees: ", d);

	Vector3f vec1 = { 2.0f, 1.0f, 5.0f };
	Vector3f vec2 = { 5.0f, 9.0f, 3.0f };

	Vector2f v = { 1.0f, 2.0f };
	Vector3f euler = { 45.0f, 12.0f, -87.0f };

	Quaternion quat = Quaternion(Vector3f(1, 0, 0), 90.0f);
	//Log("Euler: ", Maths::ToEuler(quat).ToString().c_str());
	Log(quat.ToString().c_str());
	//Log("Quaternion: ", Maths::FromEuler(euler.x, euler.y, euler.z).ToString().c_str());
	

	Engine engine = { 800, 600, "DersEngine v0.01", true, false };
	engine.Start();
	return 0;
}