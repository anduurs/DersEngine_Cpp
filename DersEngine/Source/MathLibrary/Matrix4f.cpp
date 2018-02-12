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
			//col + row * 4
			data[0 + 0 * 4] = 1.0f;
			data[1 + 1 * 4] = 1.0f;
			data[2 + 2 * 4] = 1.0f;
			data[3 + 3 * 4] = 1.0f;
		}



	}
}