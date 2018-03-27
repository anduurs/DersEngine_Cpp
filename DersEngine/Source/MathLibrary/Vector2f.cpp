#include "MathLibrary\Vector2f.h"

namespace DersEngine
{
	namespace Maths
	{
		f32 Distance(const Vec2f& vector1, const Vec2f& vector2)
		{
			float xDiff = vector1.x - vector2.x;
			float yDiff = vector1.y - vector2.y;

			return sqrt(xDiff * xDiff + yDiff * yDiff);
		}

		f32 Dot(const Vec2f& vector1, const Vec2f& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y;
		}

		Vec2f Lerp(const Vec2f& start, const Vec2f& target, f32 alpha)
		{
			return start + (target - start) * alpha;
		}

		f32 Length(const Vec2f& vector)
		{
			float vx = vector.x;
			float vy = vector.y;
			return sqrt(vx * vx + vy * vy);
		}

		Vec2f Normalize(const Vec2f& vector)
		{
			float length = Length(vector);
			return { vector.x / length, vector.y / length };
		}

		std::string ToString(const Vec2f& vector)
		{
			std::stringstream result;
			result << "Vector2f(" << vector.x << ", " << vector.y << ")";
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Vec2f& vector)
		{
			stream << ToString(vector);
			return stream;
		}
	}
}