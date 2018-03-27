#include "Platform\OpenGL\GLTextureLoader.h"
#include "Utils\stb_image.h"
#include "Debug\DebugLogging.h"

namespace DersEngine
{
	namespace Platform
	{
		namespace OpenGL
		{
			u32 LoadTexture(const std::string& path)
			{
				TextureParameters params;

				params.wrappingMethod = GL_REPEAT;
				params.minFilterMethod = GL_LINEAR_MIPMAP_LINEAR;
				params.magFilterMethod = GL_LINEAR_MIPMAP_LINEAR;
				params.useMipMapping = true;

				return LoadTexture(path, params);
			}

			u32 LoadTextureFromFile(const std::string& path, const std::string& directory)
			{
				std::string fileName = directory + '/' + path;
				return LoadTexture(fileName);
			}

			u32 LoadTexture(const std::string& path, const TextureParameters& params)
			{
				s32 width;
				s32 height;
				s32 nrChannels;

				u32 textureID;
				unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

				if (data)
				{
					GLenum format;

					if (nrChannels == 1)
					{
						format = GL_RED;
					}
					else if (nrChannels == 3)
					{
						format = GL_RGB;
					}	
					else if (nrChannels == 4)
					{
						format = GL_RGBA;
					}

					glGenTextures(1, &textureID);
					glBindTexture(GL_TEXTURE_2D, textureID);
					glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

					if (params.useMipMapping)
					{
						glGenerateMipmap(GL_TEXTURE_2D);
					}

					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, params.wrappingMethod);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, params.wrappingMethod);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, params.minFilterMethod);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, params.magFilterMethod);
				}
				else
				{
					Debug::Log("Failed to load image at path: ", path.c_str());
				}

				stbi_image_free(data);

				return textureID;
			}
		}
	}
}