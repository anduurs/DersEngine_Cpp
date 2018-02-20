#include "Platform\OpenGL\GLRenderer.h"

namespace DersEngine
{
	namespace Graphics
	{
		namespace OpenGL_API
		{
			void UploadMeshData(Mesh& mesh)
			{
				unsigned int vao, vbo, ibo;

				glGenVertexArrays(1, &vao);
				glBindVertexArray(vao);

				glGenBuffers(1, &vbo);
				glBindBuffer(GL_ARRAY_BUFFER, vbo);
				glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(Vertex), &mesh.vertices[0], GL_STATIC_DRAW);
				
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
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(unsigned int), &mesh.indices[0], GL_STATIC_DRAW);

				glBindVertexArray(0);

				mesh.vaoID = vao;
			}

			void InitDrawCall(const Mesh& mesh)
			{
				glBindVertexArray(mesh.vaoID);
				glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, 0);
			}

			void BindTexture(unsigned int textureID, unsigned int textureSlot)
			{
				glActiveTexture(GL_TEXTURE0 + textureSlot);
				glBindTexture(GL_TEXTURE_2D, textureID);
			}
		}
	}
}