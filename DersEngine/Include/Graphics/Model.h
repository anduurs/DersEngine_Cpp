#pragma once

#include <vector>
#include <string>
#include "Graphics\Texture.h"

namespace DersEngine
{
	namespace Graphics
	{
		struct Mesh;

		struct Model
		{
			std::vector<Mesh> meshes;
			std::vector<Texture> loadedTextures;
			std::string directory;
		};
	}
}
