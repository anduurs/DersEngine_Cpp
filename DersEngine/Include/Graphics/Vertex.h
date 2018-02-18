#pragma once

#include "MathLibrary\MathHeaders.h"

namespace DersEngine
{
	namespace Graphics
	{
		using namespace Maths;

		struct Vertex
		{
			Vector3f position;
			Vector3f normal;
			Vector2f textureCoordinate;
		};
	}
}
