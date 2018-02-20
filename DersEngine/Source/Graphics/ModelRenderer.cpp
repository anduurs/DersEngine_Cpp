#include "Graphics\RenderEngine.h"
#include "Platform\OpenGL\GLRenderer.h"
#include "Graphics\Model.h"
#include "Graphics\Shader.h"

namespace DersEngine
{
	namespace Graphics
	{
		void ModelRenderer::Submit(Model& model)
		{
			for (auto& mesh : model.meshes)
			{
				OpenGL_API::UploadMeshData(mesh);
			}
			
			m_Models.emplace_back(model);
		}

		void ModelRenderer::Render()
		{
			for (const auto& model : m_Models)
			{
				for (const auto& mesh : model.meshes)
				{
					Material* meshMaterial = mesh.material;

					meshMaterial->shader->Bind();

					for (unsigned int i = 0; i < meshMaterial->textures.size(); i++)
					{
						OpenGL_API::BindTexture(texture.id, i);
					}

					

					OpenGL_API::InitDrawCall(mesh);
				}
			}
		}
	}
}
