#pragma once

#include <math.h>

#define PI 3.14159265f

namespace DersEngine
{
	namespace Maths
	{
		struct Vector3f;

		struct Quaternion
		{
			float x;
			float y;
			float z;
			float w;

			Quaternion() : x(0), y(0), z(0), w(1) {}

			Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){}

			Quaternion(const Vector3f& axis, float angle)
			{
				float rad = angle * PI / 180.0f;
				
				float sinHalfAngle = sin(rad / 2.0f);
				float cosHalfAngle = cos(rad / 2.0f);

				x = axis.x * sinHalfAngle;
				y = axis.y * sinHalfAngle;
				z = axis.z * sinHalfAngle;
				w = cosHalfAngle;
			}

			float Length() const
			{
				return sqrt(x * x, y * y, z * z, w * w);
			}

			Quaternion Normalize() const 
			{
				float length = Length();
				return { x / length, y / length, z / length, w / length };
			}

			Quaternion Conjugate() const
			{
				return { -x, -y, -z, -w };
			}
		};

		Quaternion operator*(const Quaternion& left, const Quaternion& right)
		{
			float x = left.x * right.w + left.w * right.x + left.y * right.z - left.z * right.y;
			float y = left.y * right.w + left.w * right.y + left.z * right.x - left.x * right.z;
			float z = left.z * right.w + left.w * right.z + left.x * right.y - left.y * right.x;
			float w = left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z;

			return { x, y, z, w };
		}

		Quaternion operator*(const Quaternion& left, const Vector3f& right)
		{
			float x = left.w * right.x + left.y * right.z - left.z * right.y;
			float y = left.w * right.y + left.z * right.x - left.x * right.z;
			float z = left.w * right.z + left.x * right.y - left.y * right.x;
			float w = -left.x * right.x - left.y * right.y - left.z * right.z;

			return { x, y, z, w };
		}

		Quaternion operator+(const Quaternion& left, const Quaternion& right)
		{
			return { left.x + right.x , left.y + right.y, left.z + right.z, left.w + right.w };
		}

		Quaternion operator-(const Quaternion& left, const Quaternion& right)
		{
			return { left.x - right.x , left.y - right.y, left.z - right.z, left.w - right.w };
		}
	}
}
