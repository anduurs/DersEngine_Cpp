#include "MathLibrary\Vector3f.h"
#include <sstream>

namespace DersEngine
{
	namespace Maths
	{
		Vector3f::Vector3f() : x(0.0f), y(0.0f), z(0.0) {}
		Vector3f::Vector3f(float scalar) : x(scalar), y(scalar), z(scalar) {}
		Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

		Vector3f Vector3f::XAxis()
		{
			return { -1.0f, 0.0f, 0.0f };
		}

		Vector3f Vector3f::YAxis()
		{
			return {0.0f, 1.0f, 0.0f};
		}

		Vector3f Vector3f::ZAxis()
		{
			return { 0.0f, 0.0f, 1.0f };
		}

		Vector3f Vector3f::Zero()
		{
			return { 0.0f, 0.0f, 0.0f };
		}

		float Vector3f::Length() const
		{
			return sqrt(x * x + y * y + z * z);
		}

		Vector3f Vector3f::Normalize() const
		{
			float length = Length();
			return { x / length, y / length , z / length };
		}

		std::string Vector3f::ToString() const
		{
			std::stringstream result;
			result << "Vector3f(" << x << ", " << y << ", " << z << ")";
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Vector3f& vector)
		{
			stream << vector.ToString();
			return stream;
		}
	}
}