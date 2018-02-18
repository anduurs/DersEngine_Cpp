#pragma once

#include <string>

namespace DersEngine
{
	namespace Graphics
	{
		enum TextureMap
		{
			NONE,
			DIFFUSE,
			SPECULAR,
			NORMAL,
			AMBIENT_OCCLUSION,
			ROUGHNESS,
			METALLIC
		};

		struct Texture
		{
			unsigned int id;
			TextureMap textureMap;
			std::string path;
		};
	}
}
