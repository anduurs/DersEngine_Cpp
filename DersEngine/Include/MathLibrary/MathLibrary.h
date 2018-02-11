#pragma once

#include "Vector2f.h"
#include "Vector3f.h"
#include "Quaternion.h"

namespace DersEngine
{
	namespace Maths
	{
		/* 2D VECTOR OPERATIONS */

		float Distance(const Vector2f& vector1, const Vector2f& vector2)
		{
			float xDiff = vector1.x - vector2.x;
			float yDiff = vector1.y - vector2.y;

			return sqrt(xDiff * xDiff + yDiff * yDiff);
		}

		float Dot(const Vector2f& vector1, const Vector2f& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y;
		}

		Vector2f Lerp(const Vector2f& start, const Vector2f& target, float alpha)
		{
			return start + (target - start) * alpha;
		}

		/* 3D VECTOR OPERATIONS */

		float Distance(const Vector3f& vector1, const Vector3f& vector2)
		{
			float xDiff = vector1.x - vector2.x;
			float yDiff = vector1.y - vector2.y;
			float zDiff = vector1.z - vector2.z;

			return sqrt(xDiff * xDiff + yDiff * yDiff + zDiff * zDiff);
		}

		float Dot(const Vector3f& vector1, const Vector3f& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
		}

		Vector3f Cross(const Vector3f& vector1, const Vector3f& vector2)
		{
			return 
			{ 
				vector1.y * vector2.z - vector1.z * vector2.y,
				vector1.z * vector2.x - vector1.x * vector2.z,
				vector1.x * vector2.y - vector1.y * vector2.x
			};
		}

		Vector3f Lerp(const Vector3f& start, const Vector3f& target, float alpha)
		{
			return start + (target - start) * alpha;
		}

		Vector3f Rotate(const Vector3f& vector, const Quaternion& rotation)
		{
			Quaternion conjugate = rotation.Conjugate();
			Quaternion quat = rotation * vector * conjugate;
			return { quat.x, quat.y, quat.z };
		}

		/* QUATERNION OPERATIONS */

		float Dot(const Quaternion& quat1, const Quaternion& quat2)
		{
			return quat1.x * quat2.x + quat1.y * quat2.y + quat1.z * quat2.z + quat1.w * quat2.w
		}

		/* 4x4 MATRIX OPERATIONS */


	}
}




