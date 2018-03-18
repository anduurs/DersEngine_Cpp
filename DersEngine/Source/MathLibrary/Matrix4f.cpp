#include "MathLibrary\Matrix4f.h"
#include "MathLibrary\MathLibrary.h"
#include "MathLibrary\Quaternion.h"
#include "MathLibrary\Vector3f.h"

namespace DersEngine
{
	namespace Maths
	{
		Matrix4f CreateMatrix4f()
		{
			Matrix4f mat;
			memset(mat.data, 0, 16 * sizeof(float));
			return mat;
		}

		Matrix4f Translate(Matrix4f& mat, float x, float y, float z)
		{
			//col + row * 4
			Identity(mat);

			mat.data[3 + 0 * 4] = x;
			mat.data[3 + 1 * 4] = y;
			mat.data[3 + 2 * 4] = z;

			return mat;
		}

		Matrix4f Scale(Matrix4f& mat, float x, float y, float z)
		{
			//col + row * 4
			Identity(mat);

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
			Identity(mat);

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
			Identity(mat);

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
			Identity(mat);


			return mat;
		}

		Matrix4f Basis(Matrix4f& mat, const Vector3f& forward, const Vector3f& up, const Vector3f& right)
		{
			Identity(mat);

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

		void Identity(Matrix4f& mat)
		{
			memset(mat.data, 0, 16 * sizeof(float));

			//col + row * 4
			mat.data[0 + 0 * 4] = 1.0f;
			mat.data[1 + 1 * 4] = 1.0f;
			mat.data[2 + 2 * 4] = 1.0f;
			mat.data[3 + 3 * 4] = 1.0f;
		}

		std::string ToString(const Matrix4f& mat)
		{
			std::stringstream result;

			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					result << mat.data[x + y * 4] << "  ";
				}
				result <<"\n";
			}
			
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Matrix4f& mat)
		{
			stream << ToString(mat);
			return stream;
		}

		Matrix4f operator*(const Matrix4f& mat1, const Matrix4f& mat2)
		{
			Matrix4f res;
			
			for (int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					float sum = 0.0f;

					for (int e = 0; e < 4; e++)
					{
						sum += mat1.data[e + row * 4] * mat2.data[col + e * 4];
					}
					res.data[col + row * 4] = sum;
				}
			}
			
			return res;
		}

	}
}