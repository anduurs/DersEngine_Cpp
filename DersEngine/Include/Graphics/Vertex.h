#pragma once

#include "MathLibrary\MathHeaders.h"

namespace DersEngine
{
	namespace Graphics
	{
		using namespace Maths;

		struct Vertex
		{
			Vec3f position;
			Vec3f normal;
			Vec2f textureCoordinate;
		};
	}
}
