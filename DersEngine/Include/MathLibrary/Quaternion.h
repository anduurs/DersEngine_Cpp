#pragma once

namespace DersEngine
{
	namespace Maths
	{
		class Vector3f;
		class Matrix4f;

		class Quaternion
		{
		public:
			float x;
			float y;
			float z;
			float w;

			Quaternion();
			Quaternion(float x, float y, float z, float w);
			Quaternion(const Vector3f& axis, float angle);

			Quaternion& Add(const Quaternion& quaternion);
			Quaternion& Sub(const Quaternion& quaternion);
			Quaternion& Mul(const Quaternion& quaternion);
			Quaternion& Mul(float scalar);
			Quaternion& Mul(const Vector3f& vector);

			friend Quaternion operator+(Quaternion left, const Quaternion& right);
			friend Quaternion operator-(Quaternion left, const Quaternion& right);
			friend Quaternion operator*(Quaternion left, const Quaternion& right);
			friend Quaternion operator*(Quaternion left, const Vector3f& right);
			friend Quaternion operator*(Quaternion left, float scalar);

			float Length() const;
			Quaternion Normalize() const;
			Quaternion Conjugate() const;
			float Dot(const Quaternion& quaternion) const;

			Matrix4f ToRotationMatrix() const;

			Vector3f GetForward() const;
			Vector3f GetBack() const;
			Vector3f GetRight() const;
			Vector3f GetLeft() const;
			Vector3f GetUp() const;
			Vector3f GetDown() const;

			bool Equals(const Quaternion& quaternion);

			bool operator==(const Quaternion& quaternion) const;
		};
	}
}
