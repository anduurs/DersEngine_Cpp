#pragma once

#include "MathLibrary\Vector3f.h"

#define PI 3.14159265f

namespace DersEngine
{
	namespace Maths
	{
		struct Matrix4f;

		struct Quaternion
		{
			float x;
			float y;
			float z;
			float w;
		};

		Quaternion CreateQuaternionFromAxisAndAngle(const Vector3f& axis, float angle);

		float Dot(const Quaternion& quat1, const Quaternion& quat2);

		Quaternion LookAt(const Vector3f& start, const Vector3f& target);

		Quaternion Slerp(const Quaternion& quat1, Quaternion quat2, float alpha);

		//Quaternion FromEuler(float roll, float pitch, float yaw);

		//Vector3f ToEuler(const Quaternion& q);

		Matrix4f ToRotationMatrix(const Quaternion& quat);

		float Length(const Quaternion& quat);

		Quaternion Normalize(const Quaternion& quat);

		Quaternion Conjugate(const Quaternion& quat);

		Quaternion Identity();

		Vector3f GetForward(const Quaternion& quat);

		Vector3f GetUp(const Quaternion& quat);

		Vector3f GetRight(const Quaternion& quat);

		Vector3f GetXYZ(const Quaternion& quat);

		std::string ToString(const Quaternion& quat);

		std::ostream& operator<<(std::ostream& stream, const Quaternion& quat);

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
