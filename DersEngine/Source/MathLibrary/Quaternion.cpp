#include "MathLibrary\Quaternion.h"
#include "MathLibrary\Vector3f.h"
#include "MathLibrary\MathLibrary.h"

namespace DersEngine
{
	namespace Maths
	{
		Quaternion::Quaternion() : x(0), y(0), z(0), w(1) {}

		Quaternion::Quaternion(float x, float y, float z, float w) 
			: x(x), y(y), z(z), w(w) {}

		float Quaternion::Length() const
		{
			return sqrt(x * x + y * y + z * z + w * w);
		}

		Quaternion Quaternion::Normalize() const
		{
			float length = Length();
			return { x / length, y / length, z / length, w / length };
		}

		Quaternion Quaternion::Conjugate() const
		{
			return { -x, -y, -z, w };
		}

		Vector3f Quaternion::GetForward() const
		{
			return Rotate(Vector3f(0, 0, 1), *this).Normalize();
		}

		Vector3f Quaternion::GetUp() const
		{
			return Rotate(Vector3f(0, 1, 0), *this).Normalize();
		}

		Vector3f Quaternion::GetRight() const
		{
			return Rotate(Vector3f(1, 0, 0), *this).Normalize();
		}
	}
}