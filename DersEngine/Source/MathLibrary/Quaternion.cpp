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


		Quaternion::Quaternion(const Vector3f& axis, float angle)
		{
			float halfAngleInRadians = ToRadians(angle) / 2.0f;

			float sinHalfAngle = Sin(halfAngleInRadians);
			float cosHalfAngle = Cos(halfAngleInRadians);

			x = axis.x * sinHalfAngle;
			y = axis.y * sinHalfAngle;
			z = axis.z * sinHalfAngle;

			w = cosHalfAngle;
		}

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

		Quaternion Quaternion::Identity() const
		{
			return { 0.0f, 0.0f, 0.0f, 1.0f };
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

		std::string Quaternion::ToString() const
		{
			std::stringstream result;
			result << "Quaternion(" << x << ", " << y << ", " << z << ", " << w << ")";
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Quaternion& quat)
		{
			stream << quat.ToString();
			return stream;
		}
	}
}