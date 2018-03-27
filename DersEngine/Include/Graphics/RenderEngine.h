#pragma once

#include <vector>
#include <unordered_map>

namespace DersEngine
{
	namespace Graphics
	{
		struct Model;
		class Material;

		class RenderEngine
		{
		private:
			

		public:
			void Submit(const Model& model, const Material& material);
			void Render();

		};
	}
}
