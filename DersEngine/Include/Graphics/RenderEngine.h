#pragma once

#include <vector>
#include <unordered_map>

namespace DersEngine
{
	namespace Graphics
	{
		struct Mesh;
		struct Model;
		class Material;

		class RenderEngine
		{
		private:
			std::vector<Material> m_Materials;
			std::vector<Mesh> m_Meshes;

		public:
			void Submit(const Model& model, const Material& material);
			void Render();

		};
	}
}
