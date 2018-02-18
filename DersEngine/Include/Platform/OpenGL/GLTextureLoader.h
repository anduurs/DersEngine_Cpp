#pragma once

#include <GL\glew.h>
#include <string>

namespace DersEngine
{
	namespace Graphics
	{
		namespace OpenGL_API
		{
			using TextureWrap = GLuint;
			using TextureFilter = GLuint;

			struct TextureParameters
			{
				TextureWrap wrappingMethod;
				TextureFilter minFilterMethod;
				TextureFilter magFilterMethod;
				bool useMipMapping;
				float anisotropicFilteringLevel;
			};

			unsigned int LoadTexture(const std::string& path);
			unsigned int LoadTextureFromFile(const std::string& path, const std::string& directory);
			unsigned int LoadTexture(const std::string& path, const TextureParameters& params);
		}
	}
}
