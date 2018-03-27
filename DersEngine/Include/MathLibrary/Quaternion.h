#pragma once

#include "MathLibrary\Vector3f.h"

#define PI 3.14159265f

namespace DersEngine
{
	namespace Maths
	{
		struct Mat4f;

		struct Quat
		{
			float x;
			float y;
			float z;
			float w;
		};

		Quat CreateQuaternionFromAxisAndAngle(const Vec3f& axis, f32 angle);

		f32 Dot(const Quat& quat1, const Quat& quat2);

		Quat LookAt(const Vec3f& start, const Vec3f& target);

		Quat Slerp(const Quat& quat1, Quat quat2, f32 alpha);

		//Quaternion FromEuler(float roll, float pitch, float yaw);

		//Vector3f ToEuler(const Quaternion& q);

		Mat4f ToRotationMatrix(const Quat& quat);

		f32 Length(const Quat& quat);

		Quat Normalize(const Quat& quat);

		Quat Conjugate(const Quat& quat);

		Quat Identity();

		Vec3f GetForward(const Quat& quat);

		Vec3f GetUp(const Quat& quat);

		Vec3f GetRight(const Quat& quat);

		Vec3f GetXYZ(const Quat& quat);

		std::string ToString(const Quat& quat);

		std::ostream& operator<<(std::ostream& stream, const Quat& quat);

		inline Quat operator*(const Quat& left, const Quat& right)
		{
			return 
			{ 
				left.x * right.w + left.w * right.x + left.y * right.z - left.z * right.y,
				left.y * right.w + left.w * right.y + left.z * right.x - left.x * right.z, 
				left.z * right.w + left.w * right.z + left.x * right.y - left.y * right.x,
				left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z 
			};
		}

		inline Quat operator*(const Quat& left, const Vec3f& right)
		{
			return 
			{
				left.w * right.x + left.y * right.z - left.z * right.y, 
				left.w * right.y + left.z * right.x - left.x * right.z, 
				left.w * right.z + left.x * right.y - left.y * right.x,
			   -left.x * right.x - left.y * right.y - left.z * right.z 
			};
		}

		inline Quat operator+(const Quat& left, const Quat& right)
		{
			return 
			{ 
				left.x + right.x, 
				left.y + right.y, 
				left.z + right.z, 
				left.w + right.w 
			};
		}

		inline Quat operator-(const Quat& left, const Quat& right)
		{
			return 
			{ 
				left.x - right.x, 
				left.y - right.y, 
				left.z - right.z, 
				left.w - right.w 
			};
		}

		inline bool operator==(const Quat& left, const Quat& right)
		{
			return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
		}

		inline bool operator!=(const Quat& left, const Quat& right)
		{
			return !(left == right);
		}
	}
}
