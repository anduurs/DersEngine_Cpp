#include "MathLibrary\MathUtil.h"

namespace DersEngine
{
	namespace Maths
	{
		f32 ToRadians(f32 degrees)
		{
			return degrees * PI / 180.0f;
		}

		f32 ToDegrees(f32 radians)
		{
			return radians * 180.0f / PI;
		}

		f32 Clamp(f32 value, f32 min, f32 max)
		{
			return value <= min ? min :
				value >= max ? max : value;
		}

		f32 Max(f32 value1, f32 value2)
		{
			return value1 > value2 ? value1 : value2;
		}

		s32 MaxInt(s32 value1, s32 value2)
		{
			return value1 > value2 ? value1 : value2;
		}

		f32 Cos(f32 angleInRadians)
		{
			float r = cos(angleInRadians);
			return IsCloseToZero(r) ? 0.0f : r;
		}

		f32 Sin(f32 angleInRadians)
		{
			float r = sin(angleInRadians);
			return IsCloseToZero(r) ? 0.0f : r;
		}

		f32 Tan(f32 angleInRadians)
		{
			float r = tan(angleInRadians);
			return IsCloseToZero(r) ? 0.0f : r;
		}
	}
}