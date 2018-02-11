#include "MathLibrary\Quaternion.h"
#include "MathLibrary\Vector3f.h"

namespace DersEngine
{
	namespace Maths
	{
		Quaternion::Quaternion() : x(0), y(0), z(0), w(1) {}

		Quaternion::Quaternion(float x, float y, float z, float w) 
			: x(x), y(y), z(z), w(w) {}

		Quaternion::Quaternion(const Vector3f& axis, float angle)
		{
			float rad = angle * PI / 180.0f;

			float sinHalfAngle = sin(rad / 2.0f);
			float cosHalfAngle = cos(rad / 2.0f);

			x = axis.x * sinHalfAngle;
			y = axis.y * sinHalfAngle;
			z = axis.z * sinHalfAngle;
			w = cosHalfAngle;
		}

		float Quaternion::Length() const
		{
			float len = x * x + y * y + z * z + w * w;
			return sqrt(len);
		}

		Quaternion Quaternion::Normalize() const
		{
			float length = Length();
			return { x / length, y / length, z / length, w / length };
		}

		Quaternion Quaternion::Conjugate() const
		{
			return { -x, -y, -z, -w };
		}
	}
}