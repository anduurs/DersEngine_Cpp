#include "MathLibrary\MathLibrary.h"
#include "MathLibrary\Vector2f.h"
#include "MathLibrary\Vector3f.h"
#include "MathLibrary\Quaternion.h"
#include "MathLibrary\Matrix4f.h"

namespace DersEngine
{
	namespace Maths
	{
		/* 2D VECTOR OPERATIONS */

		float Maths::Distance(const Vector2f& vector1, const Vector2f& vector2)
		{
			float xDiff = vector1.x - vector2.x;
			float yDiff = vector1.y - vector2.y;

			return sqrt(xDiff * xDiff + yDiff * yDiff);
		}

		float Maths::Dot(const Vector2f& vector1, const Vector2f& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y;
		}

		Vector2f Maths::Lerp(const Vector2f& start, const Vector2f& target, float alpha)
		{
			return start + (target - start) * alpha;
		}

		/* 3D VECTOR OPERATIONS */

		float Maths::Distance(const Vector3f& vector1, const Vector3f& vector2)
		{
			float xDiff = vector1.x - vector2.x;
			float yDiff = vector1.y - vector2.y;
			float zDiff = vector1.z - vector2.z;

			return sqrt(xDiff * xDiff + yDiff * yDiff + zDiff * zDiff);
		}

		float Maths::Dot(const Vector3f& vector1, const Vector3f& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
		}

		Vector3f Maths::Cross(const Vector3f& vector1, const Vector3f& vector2)
		{
			return
			{
				vector1.y * vector2.z - vector1.z * vector2.y,
				vector1.z * vector2.x - vector1.x * vector2.z,
				vector1.x * vector2.y - vector1.y * vector2.x
			};
		}

		Vector3f Maths::Lerp(const Vector3f& start, const Vector3f& target, float alpha)
		{
			return start + (target - start) * alpha;
		}

		Vector3f Maths::Rotate(const Vector3f& vector, const Quaternion& rotation)
		{
			Quaternion conjugate = rotation.Conjugate();
			Quaternion quat = rotation * vector * conjugate;
			return { quat.x, quat.y, quat.z };
		}

		/* QUATERNION OPERATIONS */

		float Maths::Dot(const Quaternion& quat1, const Quaternion& quat2)
		{
			return quat1.x * quat2.x + quat1.y * quat2.y + quat1.z * quat2.z + quat1.w * quat2.w;
		}

		/* 4x4 MATRIX OPERATIONS */

		Matrix4f Maths::Translate(Matrix4f& mat, float x, float y, float z)
		{
			//col + row * 4
			mat.Identity();

			mat.data[3 + 0 * 4] = x;
			mat.data[3 + 1 * 4] = y;
			mat.data[3 + 2 * 4] = z;
			
			return mat;
		}
	}
}