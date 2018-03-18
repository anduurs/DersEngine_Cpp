#pragma once

#include <string>
#include <sstream>

namespace DersEngine
{
	namespace Maths
	{
		struct Quaternion;

		struct Vector3f
		{
			float x;
			float y;
			float z;
		};

		Vector3f XAxis();
		Vector3f YAxis();
		Vector3f ZAxis();
		Vector3f Zero();

		float Distance(const Vector3f& vector1, const Vector3f& vector2);

		float Dot(const Vector3f& vector1, const Vector3f& vector2);

		Vector3f Cross(const Vector3f& vector1, const Vector3f& vector2);

		Vector3f Lerp(const Vector3f& start, const Vector3f& target, float alpha);

		Vector3f Rotate(const Vector3f& vector, const Quaternion& rotation);

		Vector3f GetAxis(const Quaternion& quat);

		float Length(const Vector3f& vector);

		Vector3f Normalize(const Vector3f& vector);

		std::string ToString(const Vector3f& vector);

		std::ostream& operator<<(std::ostream& stream, const Vector3f& vector);

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

