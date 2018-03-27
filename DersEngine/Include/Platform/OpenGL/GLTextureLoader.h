#pragma once

#include <GL\glew.h>
#include <string>

#include "Core\Types.h"

namespace DersEngine
{
	namespace Platform
	{
		namespace OpenGL
		{
			using TextureWrap = GLuint;
			using TextureFilter = GLuint;

			struct TextureParameters
			{
				TextureWrap wrappingMethod;
				TextureFilter minFilterMethod;
				TextureFilter magFilterMethod;
				bool useMipMapping;
				f32 anisotropicFilteringLevel;
			};

			u32 LoadTexture(const std::string& path);
			u32 LoadTextureFromFile(const std::string& path, const std::string& directory);
			u32 LoadTexture(const std::string& path, const TextureParameters& params);
		}
	}
}
