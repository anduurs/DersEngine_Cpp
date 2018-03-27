#include "MathLibrary\Vector3f.h"
#include "MathLibrary\Quaternion.h"

namespace DersEngine
{
	namespace Maths
	{
		Vec3f XAxis()
		{
			return { -1.0f, 0.0f, 0.0f };
		}

		Vec3f YAxis()
		{
			return {0.0f, 1.0f, 0.0f};
		}

		Vec3f ZAxis()
		{
			return { 0.0f, 0.0f, 1.0f };
		}

		Vec3f Zero()
		{
			return { 0.0f, 0.0f, 0.0f };
		}

		f32 Distance(const Vec3f& vector1, const Vec3f& vector2)
		{
			f32 xDiff = vector1.x - vector2.x;
			f32 yDiff = vector1.y - vector2.y;
			f32 zDiff = vector1.z - vector2.z;

			return sqrt(xDiff * xDiff + yDiff * yDiff + zDiff * zDiff);
		}

		f32 Dot(const Vec3f& vector1, const Vec3f& vector2)
		{
			return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
		}

		Vec3f Cross(const Vec3f& vector1, const Vec3f& vector2)
		{
			return
			{
				vector1.y * vector2.z - vector1.z * vector2.y,
				vector1.z * vector2.x - vector1.x * vector2.z,
				vector1.x * vector2.y - vector1.y * vector2.x
			};
		}

		Vec3f Lerp(const Vec3f& start, const Vec3f& target, float alpha)
		{
			return start + (target - start) * alpha;
		}

		Vec3f Rotate(const Vec3f& vector, const Quat& rotation)
		{
			Quat quat = rotation * vector * Conjugate(rotation);
			return { quat.x, quat.y, quat.z };
		}

		Vec3f GetAxis(const Quat& quat)
		{
			Vec3f v;

			v.x = quat.x;
			v.y = quat.y;
			v.z = quat.z;

			return Normalize(v);
		}

		f32 Length(const Vec3f& vector)
		{
			f32 vx = vector.x;
			f32 vy = vector.y;
			f32 vz = vector.z;

			return sqrt(vx * vx + vy * vy + vz * vz);
		}

		Vec3f Normalize(const Vec3f& vector) 
		{
			f32 length = Length(vector);
			return { vector.x / length, vector.y / length , vector.z / length };
		}

		std::string ToString(const Vec3f& vector) 
		{
			std::stringstream result;
			result << "Vector3f(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Vec3f& vector)
		{
			stream << ToString(vector);
			return stream;
		}
	}
}