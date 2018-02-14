#include "MathLibrary\MathLibrary.h"
#include "MathLibrary\Vector2f.h"
#include "MathLibrary\Vector3f.h"
#include "MathLibrary\Quaternion.h"
#include "MathLibrary\Matrix4f.h"

namespace DersEngine
{
	namespace Maths
	{
		float Maths::ToRadians(float degrees)
		{
			return degrees * PI / 180.0f;
		}

		float Maths::ToDegrees(float radians)
		{
			return radians * 180.0f / PI;
		}

		/* 2D VECTOR OPERATIONS */

		float Maths::Distance(const Vector2f& vector1, const Vector2f& vector2)
		{
			float xDiff = vector1.x - vector2.x;
			float yDiff = vector1.y - vector2.y;

			return sqrt(xDiff * xDiff + yDiff * yDiff);
		}

		float Maths::Dot(const Vector2f& vector1, const Vector2f& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y;
		}

		Vector2f Maths::Lerp(const Vector2f& start, const Vector2f& target, float alpha)
		{
			return start + (target - start) * alpha;
		}

		/* 3D VECTOR OPERATIONS */

		float Maths::Distance(const Vector3f& vector1, const Vector3f& vector2)
		{
			float xDiff = vector1.x - vector2.x;
			float yDiff = vector1.y - vector2.y;
			float zDiff = vector1.z - vector2.z;

			return sqrt(xDiff * xDiff + yDiff * yDiff + zDiff * zDiff);
		}

		float Maths::Dot(const Vector3f& vector1, const Vector3f& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
		}

		Vector3f Maths::Cross(const Vector3f& vector1, const Vector3f& vector2)
		{
			return
			{
				vector1.y * vector2.z - vector1.z * vector2.y,
				vector1.z * vector2.x - vector1.x * vector2.z,
				vector1.x * vector2.y - vector1.y * vector2.x
			};
		}

		Vector3f Maths::Lerp(const Vector3f& start, const Vector3f& target, float alpha)
		{
			return start + (target - start) * alpha;
		}

		Vector3f Maths::Rotate(const Vector3f& vector, const Quaternion& rotation)
		{
			Quaternion quat = rotation * vector * rotation.Conjugate();
			return { quat.x, quat.y, quat.z };
		}

		/* QUATERNION OPERATIONS */

		float Maths::Dot(const Quaternion& quat1, const Quaternion& quat2)
		{
			return quat1.x * quat2.x + quat1.y * quat2.y + quat1.z * quat2.z + quat1.w * quat2.w;
		}

		Quaternion Maths::MakeQuaternion(const Vector3f& axis, float angle)
		{
			Quaternion quat;

			float rad = ToRadians(angle);

			float sinHalfAngle = sin(rad / 2.0f);
			float cosHalfAngle = cos(rad / 2.0f);

			quat.x = axis.x * sinHalfAngle;
			quat.y = axis.y * sinHalfAngle;
			quat.z = axis.z * sinHalfAngle;
			quat.w = cosHalfAngle;

			return quat;
		}

		Quaternion Maths::ToQuaternion(float roll, float pitch, float yaw)
		{
			float cy = cos(yaw * 0.5);
			float sy = sin(yaw * 0.5);
			float cr = cos(roll * 0.5);
			float sr = sin(roll * 0.5);
			float cp = cos(pitch * 0.5);
			float sp = sin(pitch * 0.5);

			return 
			{   
				cy * sr * cp - sy * cr * sp,
				cy * cr * sp + sy * sr * cp,
				sy * cr * cp - cy * sr * sp,
				cy * cr * cp + sy * sr * sp
			};
		}

		Vector3f Maths::ToEuler(const Quaternion& quat)
		{
			quat.Normalize();
			return 
			{ 
				atan2(2 * quat.x * quat.w - 2 * quat.y * quat.z, 1 - 2 * quat.x * quat.x - 2 * quat.z * quat.z), 
				atan2(2 * quat.y * quat.w - 2 * quat.x * quat.z, 1 - 2 * quat.y * quat.y - 2 * quat.z * quat.z),
				asin(2 * quat.x * quat.y + 2 * quat.z * quat.w) 
			};
		}

		Matrix4f ToRotationMatrix(const Quaternion& quat)
		{
			Vector3f forward = 
			{ 
				2.0f * (quat.x * quat.z - quat.w * quat.y),
				2.0f * (quat.y * quat.z + quat.w * quat.x),
				1.0f - 2.0f * (quat.x * quat.x + quat.y * quat.y) 
			};

			Vector3f up = 
			{
				2.0f * (quat.x * quat.y + quat.w * quat.z),
				1.0f - 2.0f * (quat.x * quat.x + quat.z * quat.z),
				2.0f * (quat.y * quat.z - quat.w * quat.x)
			};

			Vector3f right = 
			{
				1.0f - 2.0f * (quat.y * quat.y + quat.z * quat.z),
				2.0f * (quat.x * quat.y - quat.w * quat.z),
				2.0f * (quat.x * quat.z + quat.w * quat.y)
			};


			return Basis(Matrix4f(), forward, up, right);
		}

		/* 4x4 MATRIX OPERATIONS */

		Matrix4f Maths::Translate(Matrix4f& mat, float x, float y, float z)
		{
			//col + row * 4
			mat.Identity();

			mat.data[3 + 0 * 4] = x;
			mat.data[3 + 1 * 4] = y;
			mat.data[3 + 2 * 4] = z;
			
			return mat;
		}

		Matrix4f Maths::Scale(Matrix4f& mat, float x, float y, float z)
		{
			//col + row * 4
			mat.Identity();

			mat.data[0 + 0 * 4] = x;
			mat.data[1 + 1 * 4] = y;
			mat.data[2 + 2 * 4] = z;

			return mat;
		}

		Matrix4f Maths::Rotate(Matrix4f& mat, const Vector3f& axis, float angle)
		{
			return mat;
		}

		Matrix4f Maths::Rotate(Matrix4f& mat, const Quaternion& quat)
		{
			return mat;
		}

		Matrix4f Maths::Perspective(Matrix4f& mat, float fieldOfView, float aspectRatio, float zNear, float zFar)
		{
			mat.Identity();

			float tanHalfFoV = tan(ToRadians(fieldOfView) / 2.0f);

			mat.data[0 + 0 * 4] = 1.0f / (tanHalfFoV * aspectRatio);
			mat.data[1 + 1 * 4] = 1.0f / tanHalfFoV;
			mat.data[2 + 2 * 4] = (-zFar - zNear) / (zFar - zNear);
			mat.data[3 + 3 * 4] = (-2.0f * zFar * zNear) / (zFar - zNear);
			mat.data[2 + 3 * 4] = -1.0f;

			return mat;
		}

		Matrix4f Maths::Ortho(Matrix4f& mat, float left, float right, float bottom, float top, float near, float far)
		{
			mat.Identity();

			mat.data[0 + 0 * 4] = 2.0f / (right - left);
			mat.data[1 + 1 * 4] = 2.0f / (top - bottom);
			mat.data[2 + 2 * 4] = -2.0f / (far - near);
			
			mat.data[3 + 0 * 4] = (-right - left) / (right - left);
			mat.data[3 + 1 * 4] = (-top - bottom) / (top - bottom);
			mat.data[3 + 2 * 4] = (-far - near) / (far - near);
			
			return mat;
		}

		Matrix4f Maths::LookAt(Matrix4f& mat, const Vector3f& forward, const Vector3f& up, const Vector3f& right)
		{
			mat.Identity();


			return mat;
		}

		Matrix4f Basis(Matrix4f& mat, const Vector3f& forward, const Vector3f& up, const Vector3f& right)
		{
			mat.Identity();

			mat.data[0 + 0 * 4] = right.x;
			mat.data[0 + 1 * 4] = up.x;
			mat.data[0 + 2 * 4] = forward.x;

			mat.data[1 + 0 * 4] = right.y;
			mat.data[1 + 1 * 4] = up.y;
			mat.data[1 + 2 * 4] = forward.y;

			mat.data[2 + 0 * 4] = right.z;
			mat.data[2 + 1 * 4] = up.z;
			mat.data[2 + 2 * 4] = forward.z;

			return mat;
		}

		Matrix4f Maths::Invers(Matrix4f& mat)
		{
			float temp[16];

			temp[0] = mat.data[5] * mat.data[10] * mat.data[15] -
				mat.data[5] * mat.data[11] * mat.data[14] -
				mat.data[9] * mat.data[6] * mat.data[15] +
				mat.data[9] * mat.data[7] * mat.data[14] +
				mat.data[13] * mat.data[6] * mat.data[11] -
				mat.data[13] * mat.data[7] * mat.data[10];

			temp[4] = -mat.data[4] * mat.data[10] * mat.data[15] +
				mat.data[4] * mat.data[11] * mat.data[14] +
				mat.data[8] * mat.data[6] * mat.data[15] -
				mat.data[8] * mat.data[7] * mat.data[14] -
				mat.data[12] * mat.data[6] * mat.data[11] +
				mat.data[12] * mat.data[7] * mat.data[10];

			temp[8] = mat.data[4] * mat.data[9] * mat.data[15] -
				mat.data[4] * mat.data[11] * mat.data[13] -
				mat.data[8] * mat.data[5] * mat.data[15] +
				mat.data[8] * mat.data[7] * mat.data[13] +
				mat.data[12] * mat.data[5] * mat.data[11] -
				mat.data[12] * mat.data[7] * mat.data[9];

			temp[12] = -mat.data[4] * mat.data[9] * mat.data[14] +
				mat.data[4] * mat.data[10] * mat.data[13] +
				mat.data[8] * mat.data[5] * mat.data[14] -
				mat.data[8] * mat.data[6] * mat.data[13] -
				mat.data[12] * mat.data[5] * mat.data[10] +
				mat.data[12] * mat.data[6] * mat.data[9];

			temp[1] = -mat.data[1] * mat.data[10] * mat.data[15] +
				mat.data[1] * mat.data[11] * mat.data[14] +
				mat.data[9] * mat.data[2] * mat.data[15] -
				mat.data[9] * mat.data[3] * mat.data[14] -
				mat.data[13] * mat.data[2] * mat.data[11] +
				mat.data[13] * mat.data[3] * mat.data[10];

			temp[5] = mat.data[0] * mat.data[10] * mat.data[15] -
				mat.data[0] * mat.data[11] * mat.data[14] -
				mat.data[8] * mat.data[2] * mat.data[15] +
				mat.data[8] * mat.data[3] * mat.data[14] +
				mat.data[12] * mat.data[2] * mat.data[11] -
				mat.data[12] * mat.data[3] * mat.data[10];

			temp[9] = -mat.data[0] * mat.data[9] * mat.data[15] +
				mat.data[0] * mat.data[11] * mat.data[13] +
				mat.data[8] * mat.data[1] * mat.data[15] -
				mat.data[8] * mat.data[3] * mat.data[13] -
				mat.data[12] * mat.data[1] * mat.data[11] +
				mat.data[12] * mat.data[3] * mat.data[9];

			temp[13] = mat.data[0] * mat.data[9] * mat.data[14] -
				mat.data[0] * mat.data[10] * mat.data[13] -
				mat.data[8] * mat.data[1] * mat.data[14] +
				mat.data[8] * mat.data[2] * mat.data[13] +
				mat.data[12] * mat.data[1] * mat.data[10] -
				mat.data[12] * mat.data[2] * mat.data[9];

			temp[2] = mat.data[1] * mat.data[6] * mat.data[15] -
				mat.data[1] * mat.data[7] * mat.data[14] -
				mat.data[5] * mat.data[2] * mat.data[15] +
				mat.data[5] * mat.data[3] * mat.data[14] +
				mat.data[13] * mat.data[2] * mat.data[7] -
				mat.data[13] * mat.data[3] * mat.data[6];

			temp[6] = -mat.data[0] * mat.data[6] * mat.data[15] +
				mat.data[0] * mat.data[7] * mat.data[14] +
				mat.data[4] * mat.data[2] * mat.data[15] -
				mat.data[4] * mat.data[3] * mat.data[14] -
				mat.data[12] * mat.data[2] * mat.data[7] +
				mat.data[12] * mat.data[3] * mat.data[6];

			temp[10] = mat.data[0] * mat.data[5] * mat.data[15] -
				mat.data[0] * mat.data[7] * mat.data[13] -
				mat.data[4] * mat.data[1] * mat.data[15] +
				mat.data[4] * mat.data[3] * mat.data[13] +
				mat.data[12] * mat.data[1] * mat.data[7] -
				mat.data[12] * mat.data[3] * mat.data[5];

			temp[14] = -mat.data[0] * mat.data[5] * mat.data[14] +
				mat.data[0] * mat.data[6] * mat.data[13] +
				mat.data[4] * mat.data[1] * mat.data[14] -
				mat.data[4] * mat.data[2] * mat.data[13] -
				mat.data[12] * mat.data[1] * mat.data[6] +
				mat.data[12] * mat.data[2] * mat.data[5];

			temp[3] = -mat.data[1] * mat.data[6] * mat.data[11] +
				mat.data[1] * mat.data[7] * mat.data[10] +
				mat.data[5] * mat.data[2] * mat.data[11] -
				mat.data[5] * mat.data[3] * mat.data[10] -
				mat.data[9] * mat.data[2] * mat.data[7] +
				mat.data[9] * mat.data[3] * mat.data[6];

			temp[7] = mat.data[0] * mat.data[6] * mat.data[11] -
				mat.data[0] * mat.data[7] * mat.data[10] -
				mat.data[4] * mat.data[2] * mat.data[11] +
				mat.data[4] * mat.data[3] * mat.data[10] +
				mat.data[8] * mat.data[2] * mat.data[7] -
				mat.data[8] * mat.data[3] * mat.data[6];

			temp[11] = -mat.data[0] * mat.data[5] * mat.data[11] +
				mat.data[0] * mat.data[7] * mat.data[9] +
				mat.data[4] * mat.data[1] * mat.data[11] -
				mat.data[4] * mat.data[3] * mat.data[9] -
				mat.data[8] * mat.data[1] * mat.data[7] +
				mat.data[8] * mat.data[3] * mat.data[5];

			temp[15] = mat.data[0] * mat.data[5] * mat.data[10] -
				mat.data[0] * mat.data[6] * mat.data[9] -
				mat.data[4] * mat.data[1] * mat.data[10] +
				mat.data[4] * mat.data[2] * mat.data[9] +
				mat.data[8] * mat.data[1] * mat.data[6] -
				mat.data[8] * mat.data[2] * mat.data[5];

			float determinant = mat.data[0] * temp[0] + mat.data[1] * temp[4] + mat.data[2] * temp[8] + mat.data[3] * temp[12];
			determinant = 1.0f / determinant;

			for (int i = 0; i < 16; i++)
			{
				mat.data[i] = temp[i] * determinant;
			}
				
			return mat;
		}

		Matrix4f Maths::Transpose(Matrix4f& mat)
		{
			return mat;
		}
	}
}