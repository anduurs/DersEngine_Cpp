#pragma once

#include <string>

#include "Core\Types.h"

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
			u32 id;
			u32 textureSlot;
			TextureType type;
			std::string path;
		};
	}
}
