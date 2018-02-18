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
			void RenderMesh(const Mesh& mesh);
		}
	}
}
