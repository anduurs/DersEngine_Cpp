#pragma once

#include <string>
#include <sstream>

namespace DersEngine
{
	namespace Maths
	{
		struct Matrix4f
		{
			// 64 bytes
			float data[16];

			Matrix4f();

			void Identity();

			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Matrix4f& vector);
			
		};


	}
}
