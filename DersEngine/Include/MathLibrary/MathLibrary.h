/**
	MathLibrary for DersEngine.

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
		struct Vector2f;
		struct Vector3f;
		struct Quaternion;
		struct Matrix4f;

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

		/* 2D VECTOR OPERATIONS */

		float Distance(const Vector2f& vector1, const Vector2f& vector2);

		float Dot(const Vector2f& vector1, const Vector2f& vector2);

		Vector2f Lerp(const Vector2f& start, const Vector2f& target, float alpha);

		/* 3D VECTOR OPERATIONS */

		float Distance(const Vector3f& vector1, const Vector3f& vector2);

		float Dot(const Vector3f& vector1, const Vector3f& vector2);

		Vector3f Cross(const Vector3f& vector1, const Vector3f& vector2);

		Vector3f Lerp(const Vector3f& start, const Vector3f& target, float alpha);

		Vector3f Rotate(const Vector3f& vector, const Quaternion& rotation);

		Vector3f GetAxis(const Quaternion& quat);


		/* QUATERNION OPERATIONS */

		float Dot(const Quaternion& quat1, const Quaternion& quat2);

		Quaternion LookAt(const Vector3f& start, const Vector3f& target);

		Quaternion Slerp(const Quaternion& quat1, Quaternion quat2, float alpha);

		Quaternion FromEuler(float roll, float pitch, float yaw);

		Vector3f ToEuler(const Quaternion& q);

		Matrix4f ToRotationMatrix(const Quaternion& quat);


		/* 4x4 MATRIX OPERATIONS */

		Matrix4f Translate(Matrix4f& mat, float x, float y, float z);

		Matrix4f Scale(Matrix4f& mat, float x, float y, float z);

		Matrix4f Rotate(Matrix4f& mat, const Vector3f& axis, float angle);

		Matrix4f Rotate(Matrix4f& mat, const Quaternion& quat);

		Matrix4f Perspective(Matrix4f& mat, float fieldOfView, float aspectRatio, float zNear, float zFar);

		Matrix4f Ortho(Matrix4f& mat, float left, float right, float bottom, float top, float near, float far);

		Matrix4f LookAt(Matrix4f& mat, const Vector3f& forward, const Vector3f& up, const Vector3f& right);

		Matrix4f Basis(Matrix4f& mat, const Vector3f& forward, const Vector3f& up, const Vector3f& right);

		Matrix4f Invers(Matrix4f& mat);

		Matrix4f Transpose(Matrix4f& mat);

	}
}




