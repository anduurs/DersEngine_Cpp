#pragma once

#include <string>
#include <sstream>

#include "Core\Types.h"

namespace DersEngine
{
	namespace Maths
	{
		struct Quat;

		struct Vec3f
		{
			f32 x;
			f32 y;
			f32 z;
		};

		Vec3f XAxis();
		Vec3f YAxis();
		Vec3f ZAxis();
		Vec3f Zero();

		f32 Distance(const Vec3f& vector1, const Vec3f& vector2);

		f32 Dot(const Vec3f& vector1, const Vec3f& vector2);

		Vec3f Cross(const Vec3f& vector1, const Vec3f& vector2);

		Vec3f Lerp(const Vec3f& start, const Vec3f& target, float alpha);

		Vec3f Rotate(const Vec3f& vector, const Quat& rotation);

		Vec3f GetAxis(const Quat& quat);

		f32 Length(const Vec3f& vector);

		Vec3f Normalize(const Vec3f& vector);

		std::string ToString(const Vec3f& vector);

		std::ostream& operator<<(std::ostream& stream, const Vec3f& vector);

		inline Vec3f operator+(const Vec3f& left, const Vec3f& right)
		{
			return { left.x + right.x , left.y + right.y, left.z + right.z };
		}

		inline Vec3f operator-(const Vec3f& left, const Vec3f& right)
		{
			return { left.x - right.x , left.y - right.y, left.z - right.z };
		}

		inline Vec3f operator*(const Vec3f& left, const Vec3f& right)
		{
			return { left.x * right.x , left.y * right.y, left.z * right.z };
		}

		inline Vec3f operator/(const Vec3f& left, const Vec3f& right)
		{
			return { left.x / right.x , left.y / right.y, left.z / right.z };
		}

		inline Vec3f operator+(const Vec3f& left, float value)
		{
			return { left.x + value , left.y + value, left.z + value };
		}

		inline Vec3f operator-(const Vec3f& left, float value)
		{
			return { left.x - value , left.y - value, left.z - value };
		}

		inline Vec3f operator*(const Vec3f& left, float value)
		{
			return { left.x * value , left.y * value, left.z * value };
		}

		inline Vec3f operator/(const Vec3f& left, float value)
		{
			return { left.x / value , left.y / value, left.z / value };
		}

		inline void operator+=(Vec3f& left, const Vec3f& right)
		{
			left.x = left.x + right.x;
			left.y = left.y + right.y;
			left.z = left.z + right.z;
		}

		inline void operator-=(Vec3f& left, const Vec3f& right)
		{
			left.x = left.x - right.x;
			left.y = left.y - right.y;
			left.z = left.z - right.z;
		}

		inline void operator*=(Vec3f& left, const Vec3f& right)
		{
			left.x = left.x * right.x;
			left.y = left.y * right.y;
			left.z = left.z * right.z;
		}

		inline void operator/=(Vec3f& left, const Vec3f& right)
		{
			left.x = left.x / right.x;
			left.y = left.y / right.y;
			left.z = left.z / right.z;
		}

		inline bool operator==(const Vec3f& left, const Vec3f& right)
		{
			return left.x == right.x && left.y == right.y && left.z == right.z;
		}

		inline bool operator!=(const Vec3f& left, const Vec3f& right)
		{
			return !(left == right);
		}
	}
}

