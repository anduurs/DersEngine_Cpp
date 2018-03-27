#include "Platform\OpenGL\GLRenderingUtil.h"
#include "MathLibrary\Vector4f.h"

namespace DersEngine
{
	namespace Platform
	{
		namespace OpenGL
		{
			u32 UploadMeshData(const std::vector<Vertex>& vertices, const std::vector<u32>& indices)
			{
				u32 vao, vbo, ibo;

				glGenVertexArrays(1, &vao);
				glBindVertexArray(vao);

				glGenBuffers(1, &vbo);
				glBindBuffer(GL_ARRAY_BUFFER, vbo);
				glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
				
				// store the buffer layout for vertex positions in the vertexarray
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

				// store the buffer layout for vertex normals in the vertexarray
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

				// store the buffer layout for vertex texture coordinate in the vertexarray
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoordinate));

				glGenBuffers(1, &ibo);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(u32), &indices[0], GL_STATIC_DRAW);

				glBindVertexArray(0);

				return vao;
			}

			void BindMesh(const Mesh& mesh)
			{
				glBindVertexArray(mesh.id);
			}

			void DrawMesh(const Mesh& mesh)
			{
				glDrawElements(GL_TRIANGLES, mesh.indices, GL_UNSIGNED_INT, 0);
			}

			void BindTexture(u32 textureID, u32 textureSlot)
			{
				glActiveTexture(GL_TEXTURE0 + textureSlot);
				glBindTexture(GL_TEXTURE_2D, textureID);
			}

			void ClearFrameBuffer(const Maths::Vec4f& color)
			{
				glClearColor(color.x, color.y, color.z, color.w);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			}
		}
	}
}