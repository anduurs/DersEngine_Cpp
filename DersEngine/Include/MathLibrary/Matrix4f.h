#pragma once

#include <string>
#include <sstream>

namespace DersEngine
{
	namespace Maths
	{
		struct Vec3f;
		struct Quat;

		struct Mat4f
		{
			// 64 bytes
			float data[16];
		};

		Mat4f CreateMatrix4f();

		Mat4f Translate(Mat4f& mat, float x, float y, float z);

		Mat4f Scale(Mat4f& mat, float x, float y, float z);

		Mat4f Rotate(Mat4f& mat, const Vec3f& axis, float angle);

		Mat4f Rotate(Mat4f& mat, const Quat& quat);

		Mat4f Perspective(Mat4f& mat, float fieldOfView, float aspectRatio, float zNear, float zFar);

		Mat4f Ortho(Mat4f& mat, float left, float right, float bottom, float top, float near, float far);

		Mat4f LookAt(Mat4f& mat, const Vec3f& forward, const Vec3f& up, const Vec3f& right);

		Mat4f Basis(Mat4f& mat, const Vec3f& forward, const Vec3f& up, const Vec3f& right);

		Mat4f Invers(Mat4f& mat);

		Mat4f Transpose(Mat4f& mat);

		void Identity(Mat4f& mat);

		std::string ToString(const Mat4f& mat);

		std::ostream& operator<<(std::ostream& stream, const Mat4f& mat);

		Mat4f operator*(const Mat4f& mat1, const Mat4f& mat2);
		
	}
}
