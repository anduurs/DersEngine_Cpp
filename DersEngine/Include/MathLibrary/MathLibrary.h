/**
	Math util functions

	@author Anders Eriksson
	@version 0.1
*/

#pragma once

#include <limits>
#include <math.h>

#define PI 3.14159265f

namespace DersEngine
{
	namespace Maths
	{
		/* HELPER FUNCTIONS */

		/*
			Takes an angle in degrees and returns the angle in radians
			@param degrees a angle in degrees 
		*/
		float ToRadians(float degrees);

		/*
			Takes an angle in radians and returns the angle in degrees
			@param radians a angle in radians
		*/
		float ToDegrees(float radians);

		/*
			Clamps the given value between the given min and max values
			@param value the given value that will be clamped
			@param min the minimum limit for the clamped value
			@param max the maximum limit for the clamped value
		*/
		float Clamp(float value, float min, float max);

		float Max(float value1, float value2);

		float Cos(float angleInRadians);

		float Sin(float angleInRadians);

		float Tan(float angleInRadians);

		template <typename T>
		inline bool IsCloseToZero(T x)
		{
			return std::abs(x) < std::numeric_limits<T>::epsilon();
		}

	}
}




