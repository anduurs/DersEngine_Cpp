#pragma once

#include <vector>

namespace DersEngine
{
	namespace Graphics
	{
		struct Model;

		class RenderEngine
		{
		private:
			std::vector<Model> m_Models;
		public:
			void Submit(Model& model);
			void Render();

		};
	}
}
