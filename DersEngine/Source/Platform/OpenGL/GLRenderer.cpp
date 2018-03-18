#include "Platform\OpenGL\GLRenderer.h"

namespace DersEngine
{
	namespace Graphics
	{
		namespace OpenGL_API
		{
			unsigned int UploadMeshData(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
			{
				unsigned int vao, vbo, ibo;

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
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

				glBindVertexArray(0);

				return vao;
			}

			void Bind(const Mesh& mesh)
			{
				glBindVertexArray(mesh.id);
			}

			void Draw(const Mesh& mesh)
			{
				glDrawElements(GL_TRIANGLES, mesh.numOfIndices, GL_UNSIGNED_INT, 0);
			}

			void BindTexture(unsigned int textureID, unsigned int textureSlot)
			{
				glActiveTexture(GL_TEXTURE0 + textureSlot);
				glBindTexture(GL_TEXTURE_2D, textureID);
			}

			void ClearFramebuffer()
			{
				glClearColor(0, 0.2f, 0.3f, 0);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			}
		}
	}
}