#include "MathLibrary\MathLibrary.h"

namespace DersEngine
{
	namespace Maths
	{
		float ToRadians(float degrees)
		{
			return degrees * PI / 180.0f;
		}

		float ToDegrees(float radians)
		{
			return radians * 180.0f / PI;
		}

		float Clamp(float value, float min, float max)
		{
			return value <= min ? min :
				value >= max ? max : value;
		}

		float Max(float value1, float value2)
		{
			return value1 > value2 ? value1 : value2;
		}

		float Cos(float angleInRadians)
		{
			float r = cos(angleInRadians);
			return IsCloseToZero(r) ? 0.0f : r;
		}

		float Sin(float angleInRadians)
		{
			float r = sin(angleInRadians);
			return IsCloseToZero(r) ? 0.0f : r;
		}

		float Tan(float angleInRadians)
		{
			float r = tan(angleInRadians);
			return IsCloseToZero(r) ? 0.0f : r;
		}
	}
}