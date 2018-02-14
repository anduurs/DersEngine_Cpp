#include "MathLibrary\Matrix4f.h"

namespace DersEngine
{
	namespace Maths
	{
		Matrix4f::Matrix4f()
		{
			memset(data, 0, 16 * sizeof(float));
		}

		void Matrix4f::Identity()
		{
			memset(data, 0, 16 * sizeof(float));

			//col + row * 4
			data[0 + 0 * 4] = 1.0f;
			data[1 + 1 * 4] = 1.0f;
			data[2 + 2 * 4] = 1.0f;
			data[3 + 3 * 4] = 1.0f;
		}

		std::string Matrix4f::ToString() const
		{
			std::stringstream result;

			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					result << data[x + y * 4] << "  ";
				}
				result <<"\n";
			}
			
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Matrix4f& mat)
		{
			stream << mat.ToString();
			return stream;
		}

		Matrix4f Maths::operator*(const Matrix4f& mat1, const Matrix4f& mat2)
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