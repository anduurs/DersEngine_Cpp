#include "Platform\OpenGL\GLShader.h"
#include "Utils\FileManager.h"
#include "Debug\DebugLogging.h"

namespace DersEngine
{
	namespace Graphics
	{
		namespace OpenGL_API
		{
			unsigned int CreateShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
			{
				std::string vertexShaderCode   = Utils::ReadFile(vertexShaderPath);
				std::string fragmentShaderCode = Utils::ReadFile(fragmentShaderPath);

				const char* vsCode = vertexShaderCode.c_str();
				const char* fsCode = fragmentShaderCode.c_str();
		
				unsigned int shaderProgramID;
				unsigned int vertexShaderID;
				unsigned int fragmentShaderID;

				int success;
				char infoLog[512];

				// Create and compile the vertex shader
				vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
				glShaderSource(vertexShaderID, 1, &vsCode, NULL);
				glCompileShader(vertexShaderID);

				glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);

				if (!success)
				{
					glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
					Debug::Log("Error compiling vertex shader: ", vertexShaderPath.c_str(), "\n", infoLog);
				};

				// Create and compile the fragment shader
				fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
				glShaderSource(fragmentShaderID, 1, &fsCode, NULL);
				glCompileShader(fragmentShaderID);

				glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);

				if (!success)
				{
					glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
					Debug::Log("Error compiling fragment shader: ", fragmentShaderPath.c_str(), "\n", infoLog);
				};

				// Create the shader program and attach the vertex and fragment shaders
				shaderProgramID = glCreateProgram();
				glAttachShader(shaderProgramID, vertexShaderID);
				glAttachShader(shaderProgramID, fragmentShaderID);

				// Link the shader program
				glLinkProgram(shaderProgramID);

				glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);

				if (!success)
				{
					glGetProgramInfoLog(shaderProgramID, 512, NULL, infoLog);
					Debug::Log("Error linking shader program with shaders: ", 
						vertexShaderPath.c_str(), " and ", fragmentShaderPath.c_str(),  " attached\n", infoLog);
				}

				// Clean up the vertex and fragment shaders since they are now linked succesfully to the shader program
				glDeleteShader(vertexShaderID);
				glDeleteShader(fragmentShaderID);

				return shaderProgramID;
			}

			unsigned int AddUniform(unsigned int shaderProgram, const std::string& uniformName)
			{
				return glGetUniformLocation(shaderProgram, uniformName.c_str());
			}

			void LoadFloat(unsigned int uniformLocation, float value)
			{
				glUniform1f(uniformLocation, value);
			}

			void LoadInteger(unsigned int uniformLocation, int value)
			{
				glUniform1i(uniformLocation, value);
			}

			void LoadBool(unsigned int uniformLocation, bool value)
			{
				glUniform1i(uniformLocation, value ? 1 : 0);
			}

			void LoadVector2f(unsigned int uniformLocation, const Vector2f& vector)
			{
				glUniform2f(uniformLocation, vector.x, vector.y);
			}

			void LoadVector3f(unsigned int uniformLocation, const Vector3f& vector)
			{
				glUniform3f(uniformLocation, vector.x, vector.y, vector.z);
			}

			void LoadMatrix4f(unsigned int uniformLocation, const Matrix4f& mat)
			{
				glUniformMatrix4fv(uniformLocation, 1, GL_TRUE,  mat.data);
			}

			void Bind(unsigned int shaderProgram)
			{
				glUseProgram(shaderProgram);
			}

			void UnBind()
			{
				glUseProgram(0);
			}

			void DeleteShader(unsigned int shaderProgram)
			{
				glDeleteProgram(shaderProgram);
			}
		}
	}
}