#pragma once

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

		float ToRadians(float degrees);

		float ToDegrees(float radians);

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


		/* QUATERNION OPERATIONS */

		float Dot(const Quaternion& quat1, const Quaternion& quat2);

		Quaternion MakeQuaternion(const Vector3f& axis, float angle);

		Quaternion ToQuaternion(float roll, float pitch, float yaw);

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




