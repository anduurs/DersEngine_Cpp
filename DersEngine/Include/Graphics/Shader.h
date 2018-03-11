#pragma once

#include <unordered_map>
#include <string>

#include "Platform\OpenGL\GLShader.h"

namespace DersEngine
{
	namespace Graphics
	{
		using namespace Maths;
		using UniformTable = std::unordered_map<std::string, unsigned int>;

		class Shader
		{
		private:
			UniformTable m_UniformTable;

			unsigned int m_ShaderProgram;

		public:

			Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
			~Shader();

			void Bind();
			void UnBind();

			void AddUniform(const std::string& uniformName);

			void LoadFloat(const std::string& uniformName, float value);
			void LoadInteger(const std::string& uniformName, int value);
			void LoadBool(const std::string& uniformName, bool value);
			void LoadVector2f(const std::string& uniformName, const Vector2f& vector);
			void LoadVector3f(const std::string& uniformName, const Vector3f& vector);
			void LoadMatrix4f(const std::string& uniformName, const Matrix4f& mat);

			inline unsigned int GetID() const { return m_ShaderProgram; };
		};
	}
}
