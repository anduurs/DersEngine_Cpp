#include "MathLibrary\Vector2f.h"

namespace DersEngine
{
	namespace Maths
	{
		Vector2f::Vector2f() : x(0.0f), y(0.0f) {}

		Vector2f::Vector2f(float scalar) : x(scalar), y(scalar) {}

		Vector2f::Vector2f(float x, float y) : x(x), y(y) {}

		float Vector2f::Length() const
		{
			return sqrt(x * x + y * y);
		}

		Vector2f Vector2f::Normalize() const
		{
			float length = Length();
			return { x / length, y / length };
		}

		std::string Vector2f::ToString() const
		{
			std::stringstream result;
			result << "Vector2f(" << x << ", " << y << ")";
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Vector2f& vector)
		{
			stream << vector.ToString();
			return stream;
		}
	}
}