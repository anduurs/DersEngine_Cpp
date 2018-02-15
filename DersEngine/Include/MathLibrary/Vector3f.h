#pragma once

#include <string>
#include <sstream>

namespace DersEngine
{
	namespace Maths
	{
		struct Vector3f
		{
			float x, y, z;

			Vector3f();
			Vector3f(float scalar);
			Vector3f(float x, float y, float z);

			static Vector3f XAxis();
			static Vector3f YAxis();
			static Vector3f ZAxis();
			static Vector3f Zero();

			float Length() const;
			Vector3f Normalize() const;
			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Vector3f& vector);
		};

		inline Vector3f operator+(const Vector3f& left, const Vector3f& right)
		{
			return { left.x + right.x , left.y + right.y, left.z + right.z };
		}

		inline Vector3f operator-(const Vector3f& left, const Vector3f& right)
		{
			return { left.x - right.x , left.y - right.y, left.z - right.z };
		}

		inline Vector3f operator*(const Vector3f& left, const Vector3f& right)
		{
			return { left.x * right.x , left.y * right.y, left.z * right.z };
		}

		inline Vector3f operator/(const Vector3f& left, const Vector3f& right)
		{
			return { left.x / right.x , left.y / right.y, left.z / right.z };
		}

		inline Vector3f operator+(const Vector3f& left, float value)
		{
			return { left.x + value , left.y + value, left.z + value };
		}

		inline Vector3f operator-(const Vector3f& left, float value)
		{
			return { left.x - value , left.y - value, left.z - value };
		}

		inline Vector3f operator*(const Vector3f& left, float value)
		{
			return { left.x * value , left.y * value, left.z * value };
		}

		inline Vector3f operator/(const Vector3f& left, float value)
		{
			return { left.x / value , left.y / value, left.z / value };
		}

		inline void operator+=(Vector3f& left, const Vector3f& right)
		{
			left.x = left.x + right.x;
			left.y = left.y + right.y;
			left.z = left.z + right.z;
		}

		inline void operator-=(Vector3f& left, const Vector3f& right)
		{
			left.x = left.x - right.x;
			left.y = left.y - right.y;
			left.z = left.z - right.z;
		}

		inline void operator*=(Vector3f& left, const Vector3f& right)
		{
			left.x = left.x * right.x;
			left.y = left.y * right.y;
			left.z = left.z * right.z;
		}

		inline void operator/=(Vector3f& left, const Vector3f& right)
		{
			left.x = left.x / right.x;
			left.y = left.y / right.y;
			left.z = left.z / right.z;
		}

		inline bool operator==(const Vector3f& left, const Vector3f& right)
		{
			return left.x == right.x && left.y == right.y && left.z == right.z;
		}

		inline bool operator!=(const Vector3f& left, const Vector3f& right)
		{
			return !(left == right);
		}
	}
}

