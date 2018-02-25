#pragma once

#include <GL/glew.h>

#include "Graphics\Mesh.h"

namespace DersEngine
{
	namespace Graphics
	{
		namespace OpenGL_API
		{
			void UploadMeshData(Mesh& mesh);
			void Begin(const Mesh& mesh);
			void InitDrawCall(const Mesh& mesh);
			void BindTexture(unsigned int textureID, unsigned int textureSlot);
		}
	}
}
