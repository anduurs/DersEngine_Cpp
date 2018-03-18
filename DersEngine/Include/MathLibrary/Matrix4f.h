#pragma once

#include <string>
#include <sstream>

namespace DersEngine
{
	namespace Maths
	{
		struct Vector3f;
		struct Quaternion;

		struct Matrix4f
		{
			// 64 bytes
			float data[16];
		};

		Matrix4f CreateMatrix4f();

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

		void Identity(Matrix4f& mat);

		std::string ToString(const Matrix4f& mat);

		std::ostream& operator<<(std::ostream& stream, const Matrix4f& mat);

		Matrix4f operator*(const Matrix4f& mat1, const Matrix4f& mat2);
		
	}
}
