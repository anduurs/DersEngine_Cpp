#include "MathLibrary\Vector3f.h"

#include <sstream>

namespace DersEngine
{
	namespace Maths
	{
		Vector3f::Vector3f()
			: x(0.0f), y(0.0f), z(0.0)
		{
		}

		Vector3f::Vector3f(float scalar)
			: x(scalar), y(scalar), z(scalar)
		{
		}

		Vector3f::Vector3f(float x, float y, float z)
			: x(x), y(y), z(z)
		{
		}

		Vector3f Vector3f::Zero()
		{
			return { 0.0f, 0.0f, 0.0f };
		}

		Vector3f Vector3f::XAxis()
		{
			return { 1.0f, 0.0f, 0.0f };
		}

		Vector3f Vector3f::YAxis()
		{
			return { 0.0f, 1.0f, 0.0f };
		}

		Vector3f Vector3f::ZAxis()
		{
			return { 0.0f, 0.0f, 1.0f };
		}

		Vector3f& Vector3f::Add(const Vector3f& vector)
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;

			return *this;
		}

		Vector3f& Vector3f::Sub(const Vector3f& vector)
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;

			return *this;
		}

		Vector3f& Vector3f::Mul(const Vector3f& vector)
		{
			x *= vector.x;
			y *= vector.y;
			z *= vector.z;

			return *this;
		}

		Vector3f& Vector3f::Div(const Vector3f& vector)
		{
			x /= vector.x;
			y /= vector.y;
			z /= vector.z;

			return *this;
		}

		Vector3f& Vector3f::Add(float value)
		{
			x += value;
			y += value;
			z += value;

			return *this;
		}

		Vector3f& Vector3f::Sub(float value)
		{
			x -= value;
			y -= value;
			z -= value;

			return *this;
		}

		Vector3f& Vector3f::Mul(float value)
		{
			x *= value;
			y *= value;
			z *= value;

			return *this;
		}

		Vector3f& Vector3f::Div(float value)
		{
			x /= value;
			y /= value;
			z /= value;

			return *this;
		}

		Vector3f operator+(Vector3f left, const Vector3f& right)
		{
			return left.Add(right);
		}

		Vector3f operator-(Vector3f left, const Vector3f& right)
		{
			return left.Sub(right);
		}

		Vector3f operator*(Vector3f left, const Vector3f& right)
		{
			return left.Mul(right);
		}

		Vector3f operator/(Vector3f left, const Vector3f& right)
		{
			return left.Div(right);
		}

		Vector3f operator+(Vector3f left, float value)
		{
			return left.Add(value);
		}

		Vector3f operator-(Vector3f left, float value)
		{
			return left.Sub(value);
		}

		Vector3f operator*(Vector3f left, float value)
		{
			return left.Mul(value);
		}

		Vector3f operator/(Vector3f left, float value)
		{
			return left.Div(value);
		}

		bool Vector3f::operator==(const Vector3f& vector) const
		{
			return x == vector.x && y == vector.y && z == vector.z;
		}

		bool Vector3f::operator!=(const Vector3f& vector) const
		{
			return !(*this == vector);
		}

		Vector3f& Vector3f::operator+=(const Vector3f& vector)
		{
			return Add(vector);
		}

		Vector3f& Vector3f::operator-=(const Vector3f& vector)
		{
			return Sub(vector);
		}

		Vector3f& Vector3f::operator*=(const Vector3f& vector)
		{
			return Mul(vector);
		}

		Vector3f& Vector3f::operator/=(const Vector3f& vector)
		{
			return Div(vector);
		}

		Vector3f& Vector3f::operator+=(float value)
		{
			return Add(value);
		}

		Vector3f& Vector3f::operator-=(float value)
		{
			return Sub(value);
		}

		Vector3f& Vector3f::operator*=(float value)
		{
			return Mul(value);
		}

		Vector3f& Vector3f::operator/=(float value)
		{
			return Div(value);
		}

		float Vector3f::Length() const
		{
			return sqrt(x * x + y * y + z * z);
		}

		Vector3f Vector3f::Normalize() const
		{
			float length = Length();
			return { x / length, y / length , z / length};
		}

		float Vector3f::Distance(const Vector3f& vector) const
		{
			float xDiff = x - vector.x;
			float yDiff = y - vector.y;
			float zDiff = z - vector.z;

			return sqrt(xDiff * xDiff + yDiff * yDiff + zDiff * zDiff);
		}

		float Vector3f::Dot(const Vector3f& vector) const
		{
			return x * vector.x + y * vector.y + z * vector.z;
		}

		Vector3f Vector3f::Cross(const Vector3f& vector) const
		{
			return Vector3f(y * vector.z - z * vector.y, 
				z * vector.x - x * vector.z, x * vector.y - y * vector.x);
		}

		std::string Vector3f::ToString() const
		{
			std::stringstream result;
			result << "Vector3f: (" << x << ", " << y << ", " << z << ")";
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Vector3f& vector)
		{
			stream << vector.ToString();
			return stream;
		}
	}
}