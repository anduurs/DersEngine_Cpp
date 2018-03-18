#include "MathLibrary\Quaternion.h"
#include "MathLibrary\MathLibrary.h"
#include "MathLibrary\Matrix4f.h"

namespace DersEngine
{
	namespace Maths
	{
		Quaternion CreateQuaternionFromAxisAndAngle(const Vector3f& axis, float angle)
		{
			Quaternion quat;

			float halfAngleInRadians = ToRadians(angle) / 2.0f;

			float sinHalfAngle = Sin(halfAngleInRadians);
			float cosHalfAngle = Cos(halfAngleInRadians);

			quat.x = axis.x * sinHalfAngle;
			quat.y = axis.y * sinHalfAngle;
			quat.z = axis.z * sinHalfAngle;

			quat.w = cosHalfAngle;

			return quat;
		}

		float Dot(const Quaternion& quat1, const Quaternion& quat2)
		{
			return quat1.x * quat2.x + quat1.y * quat2.y + quat1.z * quat2.z + quat1.w * quat2.w;
		}

		Quaternion LookAt(const Vector3f& start, const Vector3f& target)
		{
			Vector3f directionToTarget = Normalize(target - start);

			float dot = Dot(ZAxis(), directionToTarget);

			if (abs(dot + 1.0f) < 0.000001f)
			{
				return { YAxis().x, YAxis().y, YAxis().z, PI };
			}

			if (abs(dot - 1.0f) < 0.000001f)
			{
				return Identity();
			}

			float angle = acosf(dot);
			Vector3f rotationAxis = Cross(ZAxis(), Normalize(directionToTarget));

			return CreateQuaternionFromAxisAndAngle(rotationAxis, ToDegrees(angle));
		}

		Quaternion Slerp(const Quaternion& quat1, Quaternion quat2, float alpha)
		{
			float flCosOmega = quat1.w * quat2.w + Dot(GetXYZ(quat2), GetXYZ(quat1));

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

		float Length(const Quaternion& quat)
		{
			float qx = quat.x;
			float qy = quat.y;
			float qz = quat.z;
			float qw = quat.w;
			return sqrt(qx * qx + qy * qy + qz * qz + qw * qw);
		}

		Quaternion Normalize(const Quaternion& quat)
		{
			float length = Length(quat);
			return { quat.x / length, quat.y / length, quat.z / length, quat.w / length };
		}

		Quaternion Conjugate(const Quaternion& quat)
		{
			return { -quat.x, -quat.y, -quat.z, quat.w };
		}

		Quaternion Identity()
		{
			return { 0.0f, 0.0f, 0.0f, 1.0f };
		}

		Vector3f GetForward(const Quaternion& quat)
		{
			return Normalize(Rotate({ 0, 0, 1 }, quat));
		}

		Vector3f GetUp(const Quaternion& quat)
		{
			return Normalize(Rotate({ 0, 1, 0 }, quat));
		}

		Vector3f GetRight(const Quaternion& quat)
		{
			return Normalize(Rotate({ 1, 0, 0 }, quat));
		}

		Vector3f GetXYZ(const Quaternion& quat) 
		{ 
			return { quat.x, quat.y, quat.z }; 
		}

		std::string ToString(const Quaternion& quat)
		{
			std::stringstream result;
			result << "Quaternion(" << quat.x << ", " << quat.y << ", " << quat.z << ", " << quat.w << ")";
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Quaternion& quat)
		{
			stream << ToString(quat);
			return stream;
		}
	}
}