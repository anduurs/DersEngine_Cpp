#include "Graphics\RenderEngine.h"
#include "Platform\OpenGL\GLRenderer.h"
#include "Graphics\Model.h"

namespace DersEngine
{
	namespace Graphics
	{
		void RenderEngine::Submit(Model& model)
		{
			for (auto& mesh : model.meshes)
			{
				OpenGL_API::UploadMeshData(mesh);
			}
			
			m_Models.emplace_back(model);
		}

		void RenderEngine::Render()
		{
			for (const auto& model : m_Models)
			{
				for (const auto& mesh : model.meshes)
				{
					OpenGL_API::RenderMesh(mesh);
				}
			}
		}
	}
}
