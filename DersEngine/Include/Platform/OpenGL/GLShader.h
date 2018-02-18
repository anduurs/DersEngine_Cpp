#pragma once

#include <GL/glew.h>
#include <string>

#include "MathLibrary\MathHeaders.h"

namespace DersEngine
{
	namespace Graphics
	{
		namespace OpenGL_API
		{
			using namespace Maths;

			unsigned int CreateShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

			void Bind(unsigned int shaderProgram);
			void UnBind();

			unsigned int AddUniform(unsigned int shaderProgram, const std::string& uniformName);

			void LoadFloat(unsigned int uniformLocation, float value);
			void LoadInteger(unsigned int uniformLocation, int value);
			void LoadBool(unsigned int uniformLocation, bool value);
			void LoadVector2f(unsigned int uniformLocation, const Vector2f& vector);
			void LoadVector3f(unsigned int uniformLocation, const Vector3f& vector);
			void LoadMatrix4f(unsigned int uniformLocation, const Matrix4f& mat);

			void DeleteShader(unsigned int shaderProgram);
		}
	}
}