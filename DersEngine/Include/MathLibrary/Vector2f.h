#pragma once

#include <string>

namespace DersEngine
{
	namespace Maths
	{
		class Vector2f
		{
		public:
			float x;
			float y;

			Vector2f();
			Vector2f(float scalar);
			Vector2f(float x, float y);

			Vector2f& Add(const Vector2f& vector);
			Vector2f& Sub(const Vector2f& vector);
			Vector2f& Mul(const Vector2f& vector);
			Vector2f& Div(const Vector2f& vector);

			Vector2f& Add(float value);
			Vector2f& Sub(float value);
			Vector2f& Mul(float value);
			Vector2f& Div(float value);

			friend Vector2f operator+(Vector2f left, const Vector2f& right);
			friend Vector2f operator-(Vector2f left, const Vector2f& right);
			friend Vector2f operator*(Vector2f left, const Vector2f& right);
			friend Vector2f operator/(Vector2f left, const Vector2f& right);

			friend Vector2f operator+(Vector2f left, float value);
			friend Vector2f operator-(Vector2f left, float value);
			friend Vector2f operator*(Vector2f left, float value);
			friend Vector2f operator/(Vector2f left, float value);

			bool operator==(const Vector2f& vector) const;
			bool operator!=(const Vector2f& vector) const;

			Vector2f& operator+=(const Vector2f& vector);
			Vector2f& operator-=(const Vector2f& vector);
			Vector2f& operator*=(const Vector2f& vector);
			Vector2f& operator/=(const Vector2f& vector);

			Vector2f& operator+=(float value);
			Vector2f& operator-=(float value);
			Vector2f& operator*=(float value);
			Vector2f& operator/=(float value);

			float Length() const;
			Vector2f Normalize() const;
			float Distance(const Vector2f& vector) const;
			float Dot(const Vector2f& vector) const;

			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Vector2f& vector);
		};
	}
}

