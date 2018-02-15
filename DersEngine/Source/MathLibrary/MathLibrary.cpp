#include "MathLibrary\MathLibrary.h"
#include "MathLibrary\Vector2f.h"
#include "MathLibrary\Vector3f.h"
#include "MathLibrary\Quaternion.h"
#include "MathLibrary\Matrix4f.h"

namespace DersEngine
{
	namespace Maths
	{
		float ToRadians(float degrees)
		{
			return degrees * PI / 180.0f;
		}

		float ToDegrees(float radians)
		{
			return radians * 180.0f / PI;
		}

		float Clamp(float value, float min, float max)
		{
			return value <= min ? min :
				value >= max ? max : value;
		}

		float Max(float value1, float value2)
		{
			return value1 > value2 ? value1 : value2;
		}

		float Cos(float angleInRadians)
		{
			float r = cos(angleInRadians);
			return IsCloseToZero(r) ? 0.0f : r;
		}

		float Sin(float angleInRadians)
		{
			float r = sin(angleInRadians);
			return IsCloseToZero(r) ? 0.0f : r;
		}

		float Tan(float angleInRadians)
		{
			float r = tan(angleInRadians);
			return IsCloseToZero(r) ? 0.0f : r;
		}

		/* 2D VECTOR OPERATIONS */

		float Distance(const Vector2f& vector1, const Vector2f& vector2)
		{
			float xDiff = vector1.x - vector2.x;
			float yDiff = vector1.y - vector2.y;

			return sqrt(xDiff * xDiff + yDiff * yDiff);
		}

		float Dot(const Vector2f& vector1, const Vector2f& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y;
		}

		Vector2f Lerp(const Vector2f& start, const Vector2f& target, float alpha)
		{
			return start + (target - start) * alpha;
		}

		/* 3D VECTOR OPERATIONS */

		float Distance(const Vector3f& vector1, const Vector3f& vector2)
		{
			float xDiff = vector1.x - vector2.x;
			float yDiff = vector1.y - vector2.y;
			float zDiff = vector1.z - vector2.z;

			return sqrt(xDiff * xDiff + yDiff * yDiff + zDiff * zDiff);
		}

		float Dot(const Vector3f& vector1, const Vector3f& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
		}

		Vector3f Cross(const Vector3f& vector1, const Vector3f& vector2)
		{
			return
			{
				vector1.y * vector2.z - vector1.z * vector2.y,
				vector1.z * vector2.x - vector1.x * vector2.z,
				vector1.x * vector2.y - vector1.y * vector2.x
			};
		}

		Vector3f Lerp(const Vector3f& start, const Vector3f& target, float alpha)
		{
			return start + (target - start) * alpha;
		}

		Vector3f Rotate(const Vector3f& vector, const Quaternion& rotation)
		{
			Quaternion quat = rotation * vector * rotation.Conjugate();
			return { quat.x, quat.y, quat.z };
		}

		Vector3f GetAxis(const Quaternion& quat)
		{
			return Vector3f(quat.x, quat.y, quat.z).Normalize();
		}

		/* QUATERNION OPERATIONS */

		float Dot(const Quaternion& quat1, const Quaternion& quat2)
		{
			return quat1.x * quat2.x + quat1.y * quat2.y + quat1.z * quat2.z + quat1.w * quat2.w;
		}

		Quaternion LookAt(const Vector3f& start, const Vector3f& target)
		{
			Vector3f directionToTarget = (target - start).Normalize();

			float dot = Dot(Vector3f::ZAxis(), directionToTarget);

			if (abs(dot + 1.0f) < 0.000001f)
			{
				return { Vector3f::YAxis().x, Vector3f::YAxis().y, Vector3f::YAxis().z, PI };
			}

			if(abs(dot - 1.0f) < 0.000001f)
			{
				return Quaternion().Identity();
			}

			float angle = acosf(dot);
			Vector3f rotationAxis = Cross(Vector3f::ZAxis(), directionToTarget).Normalize();

			return Quaternion(rotationAxis, ToDegrees(angle));
		}

		Quaternion Slerp(const Quaternion& quat1, Quaternion quat2, float alpha)
		{
			float flCosOmega = quat1.w * quat2.w + Dot(quat2.GetXYZ(), quat1.GetXYZ());

			if (flCosOmega < 0)
			{
				quat2.w = -quat2.w;
				quat2.x = -quat2.x;
				quat2.y = -quat2.y;
				quat2.z = -quat2.z;

				flCosOmega = -flCosOmega;
			}

			float k0, k1;

			if (flCosOmega > 0.9999f)
			{
				k0 = 1 - alpha;
				k1 = alpha;
			}
			else
			{
				float flSinOmega = sqrt(1 - flCosOmega * flCosOmega);
				float flOmega = atan2(flSinOmega, flCosOmega);
				float flOneOverSinOmega = 1 / flSinOmega;

				k0 = sin((1 - alpha) * flOmega) * flOneOverSinOmega;
				k1 = sin(alpha * flOmega) * flOneOverSinOmega;
			}

			Quaternion result;

			result.w = quat1.w * k0 + quat2.w * k1;
			result.x = quat1.x * k0 + quat2.x * k1;
			result.y = quat1.y * k0 + quat2.y * k1;
			result.z = quat1.z * k0 + quat2.z * k1;

			return result;
		}

		Quaternion FromEuler(float pitch, float yaw, float roll)
		{
			return Quaternion();
		}

		Vector3f ToEuler(const Quaternion& q1)
		{
			return Vector3f();
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

		Matrix4f Translate(Matrix4f& mat, float x, float y, float z)
		{
			//col + row * 4
			mat.Identity();

			mat.data[3 + 0 * 4] = x;
			mat.data[3 + 1 * 4] = y;
			mat.data[3 + 2 * 4] = z;
			
			return mat;
		}

		Matrix4f Scale(Matrix4f& mat, float x, float y, float z)
		{
			//col + row * 4
			mat.Identity();

			mat.data[0 + 0 * 4] = x;
			mat.data[1 + 1 * 4] = y;
			mat.data[2 + 2 * 4] = z;

			return mat;
		}

		Matrix4f Rotate(Matrix4f& mat, const Vector3f& axis, float angle)
		{
			return mat;
		}

		Matrix4f Rotate(Matrix4f& mat, const Quaternion& quat)
		{
			return mat;
		}

		Matrix4f Perspective(Matrix4f& mat, float fieldOfView, float aspectRatio, float zNear, float zFar)
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

		Matrix4f Ortho(Matrix4f& mat, float left, float right, float bottom, float top, float near, float far)
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

		Matrix4f LookAt(Matrix4f& mat, const Vector3f& forward, const Vector3f& up, const Vector3f& right)
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

		Matrix4f Invers(Matrix4f& mat)
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

		Matrix4f Transpose(Matrix4f& mat)
		{
			return mat;
		}
	}
}