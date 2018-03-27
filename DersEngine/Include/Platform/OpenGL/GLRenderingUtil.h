#pragma once

#include <GL/glew.h>
#include <vector>

#include "Graphics\Mesh.h"
#include "Graphics\Vertex.h"

#include "Core\Types.h"

namespace DersEngine
{
	namespace Platform
	{
		namespace OpenGL
		{
			using namespace Graphics;

			struct Vec4f;

			u32 UploadMeshData(const std::vector<Vertex>& vertices, const std::vector<u32>& indices);
			void BindMesh(const Mesh& mesh);
			void DrawMesh(const Mesh& mesh);
			void BindTexture(u32 textureID, u32 textureSlot);
			void ClearFrameBuffer(const Vec4f& color);
		}
	}
}
