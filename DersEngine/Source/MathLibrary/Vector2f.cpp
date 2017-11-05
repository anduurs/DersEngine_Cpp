#include "MathLibrary\Vector2f.h"

#include <sstream>

namespace DersEngine
{
	namespace Maths
	{
		Vector2f::Vector2f()
			: x(0.0f), y(0.0f)
		{
		}

		Vector2f::Vector2f(float scalar)
			: x(scalar), y(scalar)
		{
		}

		Vector2f::Vector2f(float x, float y)
			: x(x), y(y)
		{
		}

		Vector2f& Vector2f::Add(const Vector2f& vector)
		{
			x += vector.x;
			y += vector.y;

			return *this;
		}

		Vector2f& Vector2f::Sub(const Vector2f& vector)
		{
			x -= vector.x;
			y -= vector.y;

			return *this;
		}

		Vector2f& Vector2f::Mul(const Vector2f& vector)
		{
			x *= vector.x;
			y *= vector.y;

			return *this;
		}

		Vector2f& Vector2f::Div(const Vector2f& vector)
		{
			x /= vector.x;
			y /= vector.y;

			return *this;
		}

		Vector2f& Vector2f::Add(float value)
		{
			x += value;
			y += value;

			return *this;
		}

		Vector2f& Vector2f::Sub(float value)
		{
			x -= value;
			y -= value;

			return *this;
		}

		Vector2f& Vector2f::Mul(float value)
		{
			x *= value;
			y *= value;

			return *this;
		}

		Vector2f& Vector2f::Div(float value)
		{
			x /= value;
			y /= value;

			return *this;
		}

		Vector2f operator+(Vector2f left, const Vector2f& right)
		{
			return left.Add(right);
		}

		Vector2f operator-(Vector2f left, const Vector2f& right)
		{
			return left.Sub(right);
		}

		Vector2f operator*(Vector2f left, const Vector2f& right)
		{
			return left.Mul(right);
		}

		Vector2f operator/(Vector2f left, const Vector2f& right)
		{
			return left.Div(right);
		}

		Vector2f operator+(Vector2f left, float value)
		{
			return left.Add(value);
		}

		Vector2f operator-(Vector2f left, float value)
		{
			return left.Sub(value);
		}

		Vector2f operator*(Vector2f left, float value)
		{
			return left.Mul(value);
		}

		Vector2f operator/(Vector2f left, float value)
		{
			return left.Div(value);
		}

		bool Vector2f::operator==(const Vector2f& vector) const
		{
			return x == vector.x && y == vector.y;
		}

		bool Vector2f::operator!=(const Vector2f& vector) const
		{
			return !(*this == vector);
		}

		Vector2f& Vector2f::operator+=(const Vector2f& vector)
		{
			return Add(vector);
		}

		Vector2f& Vector2f::operator-=(const Vector2f& vector)
		{
			return Sub(vector);
		}

		Vector2f& Vector2f::operator*=(const Vector2f& vector)
		{
			return Mul(vector);
		}

		Vector2f& Vector2f::operator/=(const Vector2f& vector)
		{
			return Div(vector);
		}

		Vector2f& Vector2f::operator+=(float value)
		{
			return Add(value);
		}

		Vector2f& Vector2f::operator-=(float value)
		{
			return Sub(value);
		}

		Vector2f& Vector2f::operator*=(float value)
		{
			return Mul(value);
		}

		Vector2f& Vector2f::operator/=(float value)
		{
			return Div(value);
		}

		float Vector2f::Length() const
		{
			return sqrt(x * x + y * y);
		}

		Vector2f Vector2f::Normalize() const
		{
			float length = Length();
			return { x / length, y / length };
		}

		float Vector2f::Distance(const Vector2f& vector) const
		{
			float xDiff = x - vector.x;
			float yDiff = y - vector.y;

			return sqrt(xDiff * xDiff + yDiff * yDiff);
		}

		float Vector2f::Dot(const Vector2f& vector) const
		{
			return x * vector.x + y * vector.y;
		}

		std::string Vector2f::ToString() const
		{
			std::stringstream result;
			result << "Vector2f: (" << x << ", " << y << ")";
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Vector2f& vector)
		{
			stream << vector.ToString();
			return stream;
		}
	}
}