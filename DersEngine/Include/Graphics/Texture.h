#pragma once

#include <string>

namespace DersEngine
{
	namespace Graphics
	{
		enum TextureType
		{
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
			TextureType type;
			std::string path;
		};
	}
}
