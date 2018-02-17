#pragma once

#include "MathLibrary\MathHeaders.h"
#include <vector>

namespace DersEngine 
{
	namespace Graphics 
	{
		using namespace Maths;

		struct Vertex
		{
			Vector3f position;
			Vector3f normal;
			Vector2f textureCoordinate;
		};

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
		};

		struct Mesh
		{
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;
			std::vector<Texture> textures;
		};
	}
}

