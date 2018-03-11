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
			using MeshTable = std::unordered_map<Material, std::vector<Mesh>>;
		private:
			
			

		public:
			void Submit(const Model& model, const Material& material);
			void Render();

		};
	}
}
