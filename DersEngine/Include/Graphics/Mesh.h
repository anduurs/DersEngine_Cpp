#pragma once

#include "MathLibrary\MathHeaders.h"
#include "Graphics\Vertex.h"
#include "Graphics\Texture.h"
#include "Graphics\Material.h"
#include <vector>

namespace DersEngine 
{
	namespace Graphics 
	{
		using namespace Maths;

		struct Mesh
		{
			unsigned int vaoID;
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;
			Material* material;
		};
	}
}

