#pragma once

#include <math.h>
#include "Vector3f.h"

#define PI 3.14159265f

namespace DersEngine
{
	namespace Maths
	{
		//struct Vector3f;

		struct Quaternion
		{
			float x, y, z, w;

			Quaternion();
			Quaternion(float x, float y, float z, float w);
			Quaternion(const Vector3f& axis, float angle);

			float Length() const;
			Quaternion Normalize() const;
			Quaternion Conjugate() const;
		};

		inline Quaternion operator*(const Quaternion& left, const Quaternion& right)
		{
			float x = left.x * right.w + left.w * right.x + left.y * right.z - left.z * right.y;
			float y = left.y * right.w + left.w * right.y + left.z * right.x - left.x * right.z;
			float z = left.z * right.w + left.w * right.z + left.x * right.y - left.y * right.x;
			float w = left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z;

			return { x, y, z, w };
		}

		inline Quaternion operator*(const Quaternion& left, const Vector3f& right)
		{
			float x = left.w * right.x + left.y * right.z - left.z * right.y;
			float y = left.w * right.y + left.z * right.x - left.x * right.z;
			float z = left.w * right.z + left.x * right.y - left.y * right.x;
			float w = -left.x * right.x - left.y * right.y - left.z * right.z;

			return { x, y, z, w };
		}

		inline Quaternion operator+(const Quaternion& left, const Quaternion& right)
		{
			return { left.x + right.x , left.y + right.y, left.z + right.z, left.w + right.w };
		}

		inline Quaternion operator-(const Quaternion& left, const Quaternion& right)
		{
			return { left.x - right.x , left.y - right.y, left.z - right.z, left.w - right.w };
		}
	}
}