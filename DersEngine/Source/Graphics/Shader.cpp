#include "Graphics\Shader.h"

namespace DersEngine
{
	namespace Graphics
	{
		Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
		{
			m_ShaderProgram = OpenGL::CreateShaderProgram(vertexShaderPath, fragmentShaderPath);
		}

		Shader::~Shader()
		{
			OpenGL::DeleteShader(m_ShaderProgram);
		}

		void Shader::Bind()
		{
			OpenGL::BindShader(m_ShaderProgram);
		}

		void Shader::UnBind()
		{
			OpenGL::UnBindShader();
		}

		void Shader::AddUniform(const std::string& uniformName)
		{
			m_UniformTable[uniformName] = OpenGL::AddUniform(m_ShaderProgram, uniformName);
		}

		void Shader::LoadFloat(const std::string& uniformName, f32 value)
		{
			OpenGL::LoadFloat(m_UniformTable[uniformName], value);
		}

		void Shader::LoadInteger(const std::string& uniformName, s32 value)
		{
			OpenGL::LoadInteger(m_UniformTable[uniformName], value);
		}

		void Shader::LoadBool(const std::string& uniformName, bool value)
		{
			OpenGL::LoadBool(m_UniformTable[uniformName], value);
		}

		void Shader::LoadVector2f(const std::string& uniformName, const Vec2f& vector)
		{
			OpenGL::LoadVector2f(m_UniformTable[uniformName], vector);
		}

		void Shader::LoadVector3f(const std::string& uniformName, const Vec3f& vector)
		{
			OpenGL::LoadVector3f(m_UniformTable[uniformName], vector);
		}

		void Shader::LoadMatrix4f(const std::string& uniformName, const Mat4f& mat)
		{
			OpenGL::LoadMatrix4f(m_UniformTable[uniformName], mat);
		}
	}
}