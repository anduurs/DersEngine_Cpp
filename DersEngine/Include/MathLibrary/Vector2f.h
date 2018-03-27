#pragma once

#include <string>
#include <sstream>

#include "Core\Types.h"

namespace DersEngine
{
	namespace Maths
	{
		struct Vec2f
		{
			float x;
			float y;
		};

		f32 Distance(const Vec2f& vector1, const Vec2f& vector2);

		f32 Dot(const Vec2f& vector1, const Vec2f& vector2);

		Vec2f Lerp(const Vec2f& start, const Vec2f& target, f32 alpha);

		f32 Length(const Vec2f& vector);

		Vec2f Normalize(const Vec2f& vector);

		std::string ToString(const Vec2f& vector);

		std::ostream& operator<<(std::ostream& stream, const Vec2f& vector);

		inline Vec2f operator+(const Vec2f& left, const Vec2f& right)
		{
			return { left.x + right.x , left.y + right.y };
		}

		inline Vec2f operator-(const Vec2f& left, const Vec2f& right)
		{
			return { left.x - right.x , left.y - right.y };
		}
		
		inline Vec2f operator*(const Vec2f& left, const Vec2f& right)
		{
			return { left.x * right.x , left.y * right.y };
		}
		
		inline Vec2f operator/(const Vec2f& left, const Vec2f& right)
		{
			return { left.x / right.x , left.y / right.y };
		}

		inline Vec2f operator+(const Vec2f& left, float value)
		{
			return { left.x + value , left.y + value };
		}

		inline Vec2f operator-(const Vec2f& left, float value)
		{
			return { left.x - value , left.y - value };
		}

		inline Vec2f operator*(const Vec2f& left, float value)
		{
			return { left.x * value , left.y * value };
		}

		inline Vec2f operator/(const Vec2f& left, float value)
		{
			return { left.x / value , left.y / value };
		}

		inline void operator+=(Vec2f& left, const Vec2f& right)
		{
			left.x = left.x + right.x;
			left.y = left.y + right.y;
		}

		inline void operator-=(Vec2f& left, const Vec2f& right)
		{
			left.x = left.x - right.x;
			left.y = left.y - right.y;
		}

		inline void operator*=(Vec2f& left, const Vec2f& right)
		{
			left.x = left.x * right.x;
			left.y = left.y * right.y;
		}

		inline void operator/=(Vec2f& left, const Vec2f& right)
		{
			left.x = left.x / right.x;
			left.y = left.y / right.y;
		}

		inline bool operator==(const Vec2f& left, const Vec2f& right)
		{
			return left.x == right.x && left.y == right.y;
		}

		inline bool operator!=(const Vec2f& left, const Vec2f& right)
		{
			return !(left == right);
		}
	}
}

