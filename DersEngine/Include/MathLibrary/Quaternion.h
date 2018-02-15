#pragma once

#include "Vector3f.h"

#define PI 3.14159265f

namespace DersEngine
{
	namespace Maths
	{
		struct Quaternion
		{
			float x, y, z, w;

			Quaternion();
			Quaternion(float x, float y, float z, float w);
			Quaternion(const Vector3f& axis, float angle);
			
			float Length() const;
			Quaternion Normalize() const;
			Quaternion Conjugate() const;
			Quaternion Identity() const;

			Vector3f GetForward() const;
			Vector3f GetUp() const;
			Vector3f GetRight() const;

			inline Vector3f GetXYZ() const { return { x, y, z }; }

			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Quaternion& vector);
		};

		inline Quaternion operator*(const Quaternion& left, const Quaternion& right)
		{
			return 
			{ 
				left.x * right.w + left.w * right.x + left.y * right.z - left.z * right.y,
				left.y * right.w + left.w * right.y + left.z * right.x - left.x * right.z, 
				left.z * right.w + left.w * right.z + left.x * right.y - left.y * right.x,
				left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z 
			};
		}

		inline Quaternion operator*(const Quaternion& left, const Vector3f& right)
		{
			return 
			{
				left.w * right.x + left.y * right.z - left.z * right.y, 
				left.w * right.y + left.z * right.x - left.x * right.z, 
				left.w * right.z + left.x * right.y - left.y * right.x,
			   -left.x * right.x - left.y * right.y - left.z * right.z 
			};
		}

		inline Quaternion operator+(const Quaternion& left, const Quaternion& right)
		{
			return 
			{ 
				left.x + right.x, 
				left.y + right.y, 
				left.z + right.z, 
				left.w + right.w 
			};
		}

		inline Quaternion operator-(const Quaternion& left, const Quaternion& right)
		{
			return 
			{ 
				left.x - right.x, 
				left.y - right.y, 
				left.z - right.z, 
				left.w - right.w 
			};
		}

		inline bool operator==(const Quaternion& left, const Quaternion& right)
		{
			return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
		}

		inline bool operator!=(const Quaternion& left, const Quaternion& right)
		{
			return !(left == right);
		}
	}
}
