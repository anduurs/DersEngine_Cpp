#include "MathLibrary\Quaternion.h"
#include "MathLibrary\MathUtil.h"
#include "MathLibrary\Matrix4f.h"

namespace DersEngine
{
	namespace Maths
	{
		Quat CreateQuaternionFromAxisAndAngle(const Vec3f& axis, f32 angle)
		{
			Quat quat;

			f32 halfAngleInRadians = ToRadians(angle) / 2.0f;

			f32 sinHalfAngle = Sin(halfAngleInRadians);
			f32 cosHalfAngle = Cos(halfAngleInRadians);

			quat.x = axis.x * sinHalfAngle;
			quat.y = axis.y * sinHalfAngle;
			quat.z = axis.z * sinHalfAngle;

			quat.w = cosHalfAngle;

			return quat;
		}

		f32 Dot(const Quat& quat1, const Quat& quat2)
		{
			return quat1.x * quat2.x + quat1.y * quat2.y + quat1.z * quat2.z + quat1.w * quat2.w;
		}

		Quat LookAt(const Vec3f& start, const Vec3f& target)
		{
			Vec3f directionToTarget = Normalize(target - start);

			f32 dot = Dot(ZAxis(), directionToTarget);

			if (abs(dot + 1.0f) < 0.000001f)
			{
				return { YAxis().x, YAxis().y, YAxis().z, PI };
			}

			if (abs(dot - 1.0f) < 0.000001f)
			{
				return Identity();
			}

			f32 angle = acosf(dot);
			Vec3f rotationAxis = Cross(ZAxis(), Normalize(directionToTarget));

			return CreateQuaternionFromAxisAndAngle(rotationAxis, ToDegrees(angle));
		}

		Quat Slerp(const Quat& quat1, Quat quat2, f32 alpha)
		{
			f32 flCosOmega = quat1.w * quat2.w + Dot(GetXYZ(quat2), GetXYZ(quat1));

			if (flCosOmega < 0)
			{
				quat2.w = -quat2.w;
				quat2.x = -quat2.x;
				quat2.y = -quat2.y;
				quat2.z = -quat2.z;

				flCosOmega = -flCosOmega;
			}

			f32 k0, k1;

			if (flCosOmega > 0.9999f)
			{
				k0 = 1 - alpha;
				k1 = alpha;
			}
			else
			{
				f32 flSinOmega = sqrt(1 - flCosOmega * flCosOmega);
				f32 flOmega = atan2(flSinOmega, flCosOmega);
				f32 flOneOverSinOmega = 1 / flSinOmega;

				k0 = sin((1 - alpha) * flOmega) * flOneOverSinOmega;
				k1 = sin(alpha * flOmega) * flOneOverSinOmega;
			}

			Quat result;

			result.w = quat1.w * k0 + quat2.w * k1;
			result.x = quat1.x * k0 + quat2.x * k1;
			result.y = quat1.y * k0 + quat2.y * k1;
			result.z = quat1.z * k0 + quat2.z * k1;

			return result;
		}

		Mat4f ToRotationMatrix(const Quat& quat)
		{
			Vec3f forward =
			{
				2.0f * (quat.x * quat.z - quat.w * quat.y),
				2.0f * (quat.y * quat.z + quat.w * quat.x),
				1.0f - 2.0f * (quat.x * quat.x + quat.y * quat.y)
			};

			Vec3f up =
			{
				2.0f * (quat.x * quat.y + quat.w * quat.z),
				1.0f - 2.0f * (quat.x * quat.x + quat.z * quat.z),
				2.0f * (quat.y * quat.z - quat.w * quat.x)
			};

			Vec3f right =
			{
				1.0f - 2.0f * (quat.y * quat.y + quat.z * quat.z),
				2.0f * (quat.x * quat.y - quat.w * quat.z),
				2.0f * (quat.x * quat.z + quat.w * quat.y)
			};


			return Basis(Mat4f(), forward, up, right);
		}

		f32 Length(const Quat& quat)
		{
			f32 qx = quat.x;
			f32 qy = quat.y;
			f32 qz = quat.z;
			f32 qw = quat.w;
			return sqrt(qx * qx + qy * qy + qz * qz + qw * qw);
		}

		Quat Normalize(const Quat& quat)
		{
			f32 length = Length(quat);
			return { quat.x / length, quat.y / length, quat.z / length, quat.w / length };
		}

		Quat Conjugate(const Quat& quat)
		{
			return { -quat.x, -quat.y, -quat.z, quat.w };
		}

		Quat Identity()
		{
			return { 0.0f, 0.0f, 0.0f, 1.0f };
		}

		Vec3f GetForward(const Quat& quat)
		{
			return Normalize(Rotate({ 0, 0, 1 }, quat));
		}

		Vec3f GetUp(const Quat& quat)
		{
			return Normalize(Rotate({ 0, 1, 0 }, quat));
		}

		Vec3f GetRight(const Quat& quat)
		{
			return Normalize(Rotate({ 1, 0, 0 }, quat));
		}

		Vec3f GetXYZ(const Quat& quat) 
		{ 
			return { quat.x, quat.y, quat.z }; 
		}

		std::string ToString(const Quat& quat)
		{
			std::stringstream result;
			result << "Quaternion(" << quat.x << ", " << quat.y << ", " << quat.z << ", " << quat.w << ")";
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Quat& quat)
		{
			stream << ToString(quat);
			return stream;
		}
	}
}