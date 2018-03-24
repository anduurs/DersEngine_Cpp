#pragma once

#include <string>
#include <sstream>

#include "Core\Types.h"

namespace DersEngine
{
	namespace Maths
	{
		struct Quaternion;

		struct Vector3f
		{
			f32 x;
			f32 y;
			f32 z;
		};

		Vector3f XAxis();
		Vector3f YAxis();
		Vector3f ZAxis();
		Vector3f Zero();

		f32 Distance(const Vector3f& vector1, const Vector3f& vector2);

		f32 Dot(const Vector3f& vector1, const Vector3f& vector2);

		Vector3f Cross(const Vector3f& vector1, const Vector3f& vector2);

		Vector3f Lerp(const Vector3f& start, const Vector3f& target, float alpha);

		Vector3f Rotate(const Vector3f& vector, const Quaternion& rotation);

		Vector3f GetAxis(const Quaternion& quat);

		f32 Length(const Vector3f& vector);

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

