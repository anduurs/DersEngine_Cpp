#pragma once

#include "MathLibrary\MathHeaders.h"
#include "Graphics\Vertex.h"
#include "Graphics\Texture.h"
#include <vector>

namespace DersEngine 
{
	namespace Graphics 
	{
		using namespace Maths;

		struct Mesh
		{
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;
			std::vector<Texture> textures;
		};
	}
}

