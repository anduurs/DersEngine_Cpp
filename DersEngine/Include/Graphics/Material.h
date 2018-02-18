#pragma once

#include <vector>

#include "Graphics\Texture.h"


namespace DersEngine
{
	namespace Graphics
	{
		struct Vector3f;
		class Shader;

		struct Material
		{
			Shader shader;
			std::vector<Texture> textures;

			Vector3f baseColor;
			Vector3f specularColor;
			Vector3f emissiveColor;

			float shininess;
		};
	}
}
