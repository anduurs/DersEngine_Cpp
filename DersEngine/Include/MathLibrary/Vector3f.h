#pragma once

#include <string>

namespace DersEngine
{
	namespace Maths
	{
		class Quaternion;

		class Vector3f
		{
		public:
			float x;
			float y;
			float z;

			Vector3f();
			Vector3f(float scalar);
			Vector3f(float x, float y, float z);

			static Vector3f Zero();
			static Vector3f XAxis();
			static Vector3f YAxis();
			static Vector3f ZAxis();

			Vector3f& Add(const Vector3f& vector);
			Vector3f& Sub(const Vector3f& vector);
			Vector3f& Mul(const Vector3f& vector);
			Vector3f& Div(const Vector3f& vector);

			Vector3f& Add(float value);
			Vector3f& Sub(float value);
			Vector3f& Mul(float value);
			Vector3f& Div(float value);

			friend Vector3f operator+(Vector3f left, const Vector3f& right);
			friend Vector3f operator-(Vector3f left, const Vector3f& right);
			friend Vector3f operator*(Vector3f left, const Vector3f& right);
			friend Vector3f operator/(Vector3f left, const Vector3f& right);

			friend Vector3f operator+(Vector3f left, float value);
			friend Vector3f operator-(Vector3f left, float value);
			friend Vector3f operator*(Vector3f left, float value);
			friend Vector3f operator/(Vector3f left, float value);

			bool operator==(const Vector3f& vector) const;
			bool operator!=(const Vector3f& vector) const;

			Vector3f& operator+=(const Vector3f& vector);
			Vector3f& operator-=(const Vector3f& vector);
			Vector3f& operator*=(const Vector3f& vector);
			Vector3f& operator/=(const Vector3f& vector);

			Vector3f& operator+=(float value);
			Vector3f& operator-=(float value);
			Vector3f& operator*=(float value);
			Vector3f& operator/=(float value);

			float Length() const;
			Vector3f Normalize() const;
			float Distance(const Vector3f& vector) const;
			float Dot(const Vector3f& vector) const;
			Vector3f Cross(const Vector3f& vector) const;
			Vector3f Lerp(const Vector3f& target, float alpha);
			Vector3f Rotate(const Quaternion& rotation);

			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Vector3f& vector);
		};
	}
}

