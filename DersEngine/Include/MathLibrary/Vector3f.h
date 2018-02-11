#pragma once

#include <string>
#include <sstream>

namespace DersEngine
{
	namespace Maths
	{
		struct Vector3f
		{
			float x;
			float y;
			float z;

			Vector3f(): x(0.0f), y(0.0f), z(0.0){}
			Vector3f(float scalar): x(scalar), y(scalar), z(scalar){}
			Vector3f(float x, float y, float z): x(x), y(y), z(z){}

			Vector3f Zero()
			{
				return { 0.0f, 0.0f, 0.0f };
			}

			Vector3f XAxis()
			{
				return { 1.0f, 0.0f, 0.0f };
			}

			Vector3f YAxis()
			{
				return { 0.0f, 1.0f, 0.0f };
			}

			Vector3f ZAxis()
			{
				return { 0.0f, 0.0f, 1.0f };
			}

			float Length() const
			{
				return sqrt(x * x + y * y + z * z);
			}

			Vector3f Normalize() const
			{
				float length = Length();
				return { x / length, y / length , z / length };
			}

			std::string ToString() const
			{
				std::stringstream result;
				result << "Vector3f(" << x << ", " << y << ", " << z << ")";
				return result.str();
			}

			friend std::ostream& operator<<(std::ostream& stream, const Vector3f& vector)
			{
				stream << vector.ToString();
				return stream;
			}
		};

		Vector3f operator+(const Vector3f& left, const Vector3f& right)
		{
			return { left.x + right.x , left.y + right.y, left.z + right.z };
		}

		Vector3f operator-(const Vector3f& left, const Vector3f& right)
		{
			return { left.x - right.x , left.y - right.y, left.z - right.z };
		}

		Vector3f operator*(const Vector3f& left, const Vector3f& right)
		{
			return { left.x * right.x , left.y * right.y, left.z * right.z };
		}

		Vector3f operator/(const Vector3f& left, const Vector3f& right)
		{
			return { left.x / right.x , left.y / right.y, left.z / right.z };
		}

		Vector3f operator+(const Vector3f& left, float value)
		{
			return { left.x + value , left.y + value, left.z + value };
		}

		Vector3f operator-(const Vector3f& left, float value)
		{
			return { left.x - value , left.y - value, left.z - value };
		}

		Vector3f operator*(const Vector3f& left, float value)
		{
			return { left.x * value , left.y * value, left.z * value };
		}

		Vector3f operator/(const Vector3f& left, float value)
		{
			return { left.x / value , left.y / value, left.z / value };
		}

		void operator+=(Vector3f& left, const Vector3f& right)
		{
			left.x = left.x + right.x;
			left.y = left.y + right.y;
			left.z = left.z + right.z;
		}

		void operator-=(Vector3f& left, const Vector3f& right)
		{
			left.x = left.x - right.x;
			left.y = left.y - right.y;
			left.z = left.z - right.z;
		}

		void operator*=(Vector3f& left, const Vector3f& right)
		{
			left.x = left.x * right.x;
			left.y = left.y * right.y;
			left.z = left.z * right.z;
		}

		void operator/=(Vector3f& left, const Vector3f& right)
		{
			left.x = left.x / right.x;
			left.y = left.y / right.y;
			left.z = left.z / right.z;
		}

		bool operator==(const Vector3f& left, const Vector3f& right)
		{
			return left.x == right.x && left.y == right.y && left.z == right.z;
		}

		bool operator!=(const Vector3f& left, const Vector3f& right)
		{
			return !(left == right);
		}
	}
}

