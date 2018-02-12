#pragma once

namespace DersEngine
{
	namespace Maths
	{
		struct Vector2f;
		struct Vector3f;
		struct Quaternion;
		struct Matrix4f;

		/* 2D VECTOR OPERATIONS */

		float Distance(const Vector2f& vector1, const Vector2f& vector2);

		float Dot(const Vector2f& vector1, const Vector2f& vector2);

		Vector2f Lerp(const Vector2f& start, const Vector2f& target, float alpha);

		/* 3D VECTOR OPERATIONS */

		float Distance(const Vector3f& vector1, const Vector3f& vector2);

		float Dot(const Vector3f& vector1, const Vector3f& vector2);

		Vector3f Cross(const Vector3f& vector1, const Vector3f& vector2);

		Vector3f Lerp(const Vector3f& start, const Vector3f& target, float alpha);

		Vector3f Rotate(const Vector3f& vector, const Quaternion& rotation);

		/* QUATERNION OPERATIONS */

		float Dot(const Quaternion& quat1, const Quaternion& quat2);

		/* 4x4 MATRIX OPERATIONS */

		Matrix4f Translate(float x, float y, float z);

	}
}




