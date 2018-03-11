#pragma once

#include <GL/glew.h>

#include "Graphics\Mesh.h"
#include "Graphics\Vertex.h"

namespace DersEngine
{
	namespace Graphics
	{
		namespace OpenGL_API
		{
			unsigned int UploadMeshData(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
			void Bind(const Mesh& mesh);
			void Draw(const Mesh& mesh);
			void BindTexture(unsigned int textureID, unsigned int textureSlot);
		}
	}
}
