#pragma once

#include <GL/glew.h>
#include <string>

#include "MathLibrary\MathHeaders.h"

namespace DersEngine
{
	namespace Platform
	{
		namespace OpenGL
		{
			using namespace Maths;

			u32 CreateShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

			void BindShader(u32 shaderProgram);
			void UnBindShader();

			u32 AddUniform(u32 shaderProgram, const std::string& uniformName);

			void LoadFloat(u32 uniformLocation, f32 value);
			void LoadInteger(u32 uniformLocation, s32 value);
			void LoadBool(u32 uniformLocation, bool value);
			void LoadVector2f(u32 uniformLocation, const Vec2f& vector);
			void LoadVector3f(u32 uniformLocation, const Vec3f& vector);
			void LoadMatrix4f(u32 uniformLocation, const Mat4f& mat);

			void DeleteShader(u32 shaderProgram);
		}
	}
}