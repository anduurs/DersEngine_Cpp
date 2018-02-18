#include "Graphics\Shader.h"

namespace DersEngine
{
	namespace Graphics
	{
		Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
		{
			m_ShaderProgram = OpenGL_API::CreateShaderProgram(vertexShaderPath, fragmentShaderPath);
		}

		Shader::~Shader()
		{
			OpenGL_API::DeleteShader(m_ShaderProgram);
		}

		void Shader::Bind()
		{
			OpenGL_API::Bind(m_ShaderProgram);
		}

		void Shader::UnBind()
		{
			OpenGL_API::Bind(0);
		}

		void Shader::AddUniform(const std::string& uniformName)
		{
			m_UniformTable[uniformName] = OpenGL_API::AddUniform(m_ShaderProgram, uniformName);
		}

		void Shader::LoadFloat(const std::string& uniformName, float value)
		{
			OpenGL_API::LoadFloat(m_UniformTable[uniformName], value);
		}

		void Shader::LoadInteger(const std::string& uniformName, int value)
		{
			OpenGL_API::LoadInteger(m_UniformTable[uniformName], value);
		}

		void Shader::LoadBool(const std::string& uniformName, bool value)
		{
			OpenGL_API::LoadBool(m_UniformTable[uniformName], value);
		}

		void Shader::LoadVector2f(const std::string& uniformName, const Vector2f& vector)
		{
			OpenGL_API::LoadVector2f(m_UniformTable[uniformName], vector);
		}

		void Shader::LoadVector3f(const std::string& uniformName, const Vector3f& vector)
		{
			OpenGL_API::LoadVector3f(m_UniformTable[uniformName], vector);
		}

		void Shader::LoadMatrix4f(const std::string& uniformName, const Matrix4f& mat)
		{
			OpenGL_API::LoadMatrix4f(m_UniformTable[uniformName], mat);
		}
	}
}