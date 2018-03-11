#pragma once


#include "Graphics\Material.h"
#include <vector>

namespace DersEngine 
{
	namespace Graphics 
	{
		struct Mesh
		{
			unsigned int id;
			unsigned int numOfIndices;

			Material* material;
		};
	}
}

