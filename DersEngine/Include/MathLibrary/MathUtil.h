/**
	Math util functions

	@author Anders Eriksson
	@version 0.1
*/

#pragma once

#include <limits>
#include <math.h>

#include "Core\Types.h"

#define PI 3.14159265f

namespace DersEngine
{
	namespace Maths
	{
		/*
			Takes an angle in degrees and returns the angle in radians
			@param degrees a angle in degrees 
		*/
		f32 ToRadians(f32 degrees);

		/*
			Takes an angle in radians and returns the angle in degrees
			@param radians a angle in radians
		*/
		f32 ToDegrees(f32 radians);

		/*
			Clamps the given value between the given min and max values
			@param value the given value that will be clamped
			@param min the minimum limit for the clamped value
			@param max the maximum limit for the clamped value
		*/
		f32 Clamp(f32 value, f32 min, f32 max);

		f32 Max(f32 value1, f32 value2);

		f32 Cos(f32 angleInRadians);

		f32 Sin(f32 angleInRadians);

		f32 Tan(f32 angleInRadians);

		template <typename T>
		inline bool IsCloseToZero(T x)
		{
			return std::abs(x) < std::numeric_limits<T>::epsilon();
		}

	}
}




