#include"Graphics\ShaderFactory.h"
#include "Graphics\Shader.h"

namespace DersEngine
{
	namespace Graphics
	{
		Shader CreatePhongShader()
		{
			Shader phongShader("Resources/Shaders/PhongVertexShader.vert", "Resources/Shaders/PhongFragmentShader.frag");

			phongShader.AddUniform("modelMatrix");
			phongShader.AddUniform("viewMatrix");
			phongShader.AddUniform("projectionMatrix");
		}
	}
}
