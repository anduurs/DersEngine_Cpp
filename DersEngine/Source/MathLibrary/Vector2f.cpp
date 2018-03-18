#include "MathLibrary\Vector2f.h"

namespace DersEngine
{
	namespace Maths
	{
		float Distance(const Vector2f& vector1, const Vector2f& vector2)
		{
			float xDiff = vector1.x - vector2.x;
			float yDiff = vector1.y - vector2.y;

			return sqrt(xDiff * xDiff + yDiff * yDiff);
		}

		float Dot(const Vector2f& vector1, const Vector2f& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y;
		}

		Vector2f Lerp(const Vector2f& start, const Vector2f& target, float alpha)
		{
			return start + (target - start) * alpha;
		}

		float Length(const Vector2f& vector)
		{
			float vx = vector.x;
			float vy = vector.y;
			return sqrt(vx * vx + vy * vy);
		}

		Vector2f Normalize(const Vector2f& vector)
		{
			float length = Length(vector);
			return { vector.x / length, vector.y / length };
		}

		std::string ToString(const Vector2f& vector)
		{
			std::stringstream result;
			result << "Vector2f(" << vector.x << ", " << vector.y << ")";
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Vector2f& vector)
		{
			stream << ToString(vector);
			return stream;
		}
	}
}