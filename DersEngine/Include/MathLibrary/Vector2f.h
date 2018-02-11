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

			Vector2f(): x(0.0f), y(0.0f){}
			Vector2f(float scalar): x(scalar), y(scalar){}
			Vector2f(float x, float y): x(x), y(y){}

			float Length() const
			{
				return sqrt(x * x + y * y);
			}

			Vector2f Normalize() const
			{
				float length = Length();
				return { x / length, y / length };
			}

			std::string ToString() const
			{
				std::stringstream result;
				result << "Vector2f(" << x << ", " << y << ")";
				return result.str();
			}

			friend std::ostream& operator<<(std::ostream& stream, const Vector2f& vector)
			{
				stream << vector.ToString();
				return stream;
			}
		};

		Vector2f operator+(const Vector2f& left, const Vector2f& right)
		{
			return { left.x + right.x , left.y + right.y };
		}

		Vector2f operator-(const Vector2f& left, const Vector2f& right)
		{
			return { left.x - right.x , left.y - right.y };
		}
		
		Vector2f operator*(const Vector2f& left, const Vector2f& right)
		{
			return { left.x * right.x , left.y * right.y };
		}
		
		Vector2f operator/(const Vector2f& left, const Vector2f& right)
		{
			return { left.x / right.x , left.y / right.y };
		}

		Vector2f operator+(const Vector2f& left, float value)
		{
			return { left.x + value , left.y + value };
		}

		Vector2f operator-(const Vector2f& left, float value)
		{
			return { left.x - value , left.y - value };
		}

		Vector2f operator*(const Vector2f& left, float value)
		{
			return { left.x * value , left.y * value };
		}

		Vector2f operator/(const Vector2f& left, float value)
		{
			return { left.x / value , left.y / value };
		}

		void operator+=(Vector2f& left, const Vector2f& right)
		{
			left.x = left.x + right.x;
			left.y = left.y + right.y;
		}

		void operator-=(Vector2f& left, const Vector2f& right)
		{
			left.x = left.x - right.x;
			left.y = left.y - right.y;
		}

		void operator*=(Vector2f& left, const Vector2f& right)
		{
			left.x = left.x * right.x;
			left.y = left.y * right.y;
		}

		void operator/=(Vector2f& left, const Vector2f& right)
		{
			left.x = left.x / right.x;
			left.y = left.y / right.y;
		}

		bool operator==(const Vector2f& left, const Vector2f& right)
		{
			return left.x == right.x && left.y == right.y;
		}

		bool operator!=(const Vector2f& left, const Vector2f& right)
		{
			return !(left == right);
		}
	}
}

