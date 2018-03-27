#pragma once

#include <unordered_map>
#include <string>

#include "Platform\OpenGL\GLShader.h"

namespace DersEngine
{
	namespace Graphics
	{
		using namespace Maths;
		using namespace Platform;

		using UniformTable = std::unordered_map<std::string, u32>;

		class Shader
		{
		private:
			UniformTable m_UniformTable;

			u32 m_ShaderProgram;

		public:

			Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
			~Shader();

			void Bind();
			void UnBind();

			void AddUniform(const std::string& uniformName);

			void LoadFloat(const std::string& uniformName, f32 value);
			void LoadInteger(const std::string& uniformName, s32 value);
			void LoadBool(const std::string& uniformName, bool value);
			void LoadVector2f(const std::string& uniformName, const Vec2f& vector);
			void LoadVector3f(const std::string& uniformName, const Vec3f& vector);
			void LoadMatrix4f(const std::string& uniformName, const Mat4f& mat);

			inline u32 GetID() const { return m_ShaderProgram; };
		};
	}
}
