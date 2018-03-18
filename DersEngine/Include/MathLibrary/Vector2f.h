#pragma once

#include <string>
#include <sstream>

namespace DersEngine
{
	namespace Maths
	{
		struct Vector2f
		{
			float x;
			float y;
		};

		float Distance(const Vector2f& vector1, const Vector2f& vector2);

		float Dot(const Vector2f& vector1, const Vector2f& vector2);

		Vector2f Lerp(const Vector2f& start, const Vector2f& target, float alpha);

		float Length(const Vector2f& vector);

		Vector2f Normalize(const Vector2f& vector);

		std::string ToString(const Vector2f& vector);

		std::ostream& operator<<(std::ostream& stream, const Vector2f& vector);

		inline Vector2f operator+(const Vector2f& left, const Vector2f& right)
		{
			return { left.x + right.x , left.y + right.y };
		}

		inline Vector2f operator-(const Vector2f& left, const Vector2f& right)
		{
			return { left.x - right.x , left.y - right.y };
		}
		
		inline Vector2f operator*(const Vector2f& left, const Vector2f& right)
		{
			return { left.x * right.x , left.y * right.y };
		}
		
		inline Vector2f operator/(const Vector2f& left, const Vector2f& right)
		{
			return { left.x / right.x , left.y / right.y };
		}

		inline Vector2f operator+(const Vector2f& left, float value)
		{
			return { left.x + value , left.y + value };
		}

		inline Vector2f operator-(const Vector2f& left, float value)
		{
			return { left.x - value , left.y - value };
		}

		inline Vector2f operator*(const Vector2f& left, float value)
		{
			return { left.x * value , left.y * value };
		}

		inline Vector2f operator/(const Vector2f& left, float value)
		{
			return { left.x / value , left.y / value };
		}

		inline void operator+=(Vector2f& left, const Vector2f& right)
		{
			left.x = left.x + right.x;
			left.y = left.y + right.y;
		}

		inline void operator-=(Vector2f& left, const Vector2f& right)
		{
			left.x = left.x - right.x;
			left.y = left.y - right.y;
		}

		inline void operator*=(Vector2f& left, const Vector2f& right)
		{
			left.x = left.x * right.x;
			left.y = left.y * right.y;
		}

		inline void operator/=(Vector2f& left, const Vector2f& right)
		{
			left.x = left.x / right.x;
			left.y = left.y / right.y;
		}

		inline bool operator==(const Vector2f& left, const Vector2f& right)
		{
			return left.x == right.x && left.y == right.y;
		}

		inline bool operator!=(const Vector2f& left, const Vector2f& right)
		{
			return !(left == right);
		}
	}
}

