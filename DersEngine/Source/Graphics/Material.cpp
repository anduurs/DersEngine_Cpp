#include "Graphics\Material.h"
#include "Graphics\Shader.h"
#include <algorithm>

namespace DersEngine
{
	namespace Graphics
	{
		Material::Material(Shader* shader)
			: m_Shader(shader)
		{
			ID = shader->GetID();
		}

		Material::~Material()
		{

		}

		void Material::AddTexture(const std::string& name, Texture texture)
		{
			auto it = std::find_if(m_Textures.begin(), m_Textures.end(),
				[&](const auto& elem)
			{
				return elem.name.compare(name) == 0;
			});

			if (it == m_Textures.end()) 
			{
				UniformTextureSampler textureUniform;
				textureUniform.name = name;
				textureUniform.value = texture;
				m_Textures.emplace_back(textureUniform);
			}
			else 
			{

			}
			
		}

		void Material::AddInt(const std::string& name, int value)
		{
			auto it = std::find_if(m_IntUniforms.begin(), m_IntUniforms.end(), 
			[&](const auto& elem) 
			{
				return elem.name.compare(name) == 0;
			});

			if (it == m_IntUniforms.end())
			{
				UniformInt uInt;
				uInt.name = name;
				uInt.value = value;
				m_IntUniforms.emplace_back(uInt);
				m_Shader->AddUniform(name);
				m_Shader->LoadInteger(name, value);
			}
			else
			{
				auto uniform = *it;
				uniform.value = value;
				m_IntUniformsUpdated.emplace_back(uniform);
			}
		}

		void Material::AddFloat(const std::string& name, float value)
		{
			auto it = std::find_if(m_FloatUniforms.begin(), m_FloatUniforms.end(),
				[&](const auto& elem)
			{
				return elem.name.compare(name) == 0;
			});

			if (it == m_FloatUniforms.end())
			{
				UniformFloat uFloat;
				uFloat.name = name;
				uFloat.value = value;
				m_FloatUniforms.emplace_back(uFloat);
				m_Shader->AddUniform(name);
				m_Shader->LoadFloat(name, value);
			}
			else
			{
				auto uniform = *it;
				uniform.value = value;
				m_FloatUniformsUpdated.emplace_back(uniform);
			}
		}

		void Material::AddVec2(const std::string& name, Vec2f value)
		{
			auto it = std::find_if(m_Vec2Uniforms.begin(), m_Vec2Uniforms.end(),
				[&](const auto& elem)
			{
				return elem.name.compare(name) == 0;
			});

			if (it == m_Vec2Uniforms.end())
			{
				UniformVector2f uVec2;
				uVec2.name = name;
				uVec2.value = value;
				m_Vec2Uniforms.emplace_back(uVec2);
				m_Shader->AddUniform(name);
				m_Shader->LoadVector2f(name, value);
			}
			else
			{
				auto uniform = *it;
				uniform.value = value;
				m_Vec2UniformsUpdated.emplace_back(uniform);
			}
		}

		void Material::AddVec3(const std::string& name, Vec3f value)
		{
			auto it = std::find_if(m_Vec3Uniforms.begin(), m_Vec3Uniforms.end(),
				[&](const auto& elem)
			{
				return elem.name.compare(name) == 0;
			});

			if (it == m_Vec3Uniforms.end())
			{
				UniformVector3f uVec3;
				uVec3.name = name;
				uVec3.value = value;
				m_Vec3Uniforms.emplace_back(uVec3);
				m_Shader->AddUniform(name);
				m_Shader->LoadVector3f(name, value);
			}
			else
			{
				auto uniform = *it;
				uniform.value = value;
				m_Vec3UniformsUpdated.emplace_back(uniform);
			}
		}

		void Material::AddMat4(const std::string& name, Mat4f value)
		{
			auto it = std::find_if(m_Mat4Uniforms.begin(), m_Mat4Uniforms.end(),
				[&](const auto& elem)
			{
				return elem.name.compare(name) == 0;
			});

			if (it == m_Mat4Uniforms.end())
			{
				UniformMatrix4f uMat4;
				uMat4.name = name;
				uMat4.value = value;
				m_Mat4Uniforms.emplace_back(uMat4);
				m_Shader->AddUniform(name);
				m_Shader->LoadMatrix4f(name, value);
			}
			else
			{
				auto uniform = *it;
				uniform.value = value;
				m_Mat4UniformsUpdated.emplace_back(uniform);
			}
		}

		void Material::UpdateUniforms()
		{
			for (const auto& uniform : m_TexturesUpdated) 
			{
				//m_Shader->LoadInteger(uniform.name, uniform.)
			}

			for (const auto& uniform : m_IntUniformsUpdated)
			{
				m_Shader->LoadInteger(uniform.name, uniform.value);
			}

			m_IntUniformsUpdated.clear();

			for (const auto& uniform : m_FloatUniformsUpdated)
			{
				m_Shader->LoadFloat(uniform.name, uniform.value);
			}

			m_FloatUniformsUpdated.clear();

			for (const auto& uniform : m_Vec2UniformsUpdated)
			{
				m_Shader->LoadVector2f(uniform.name, uniform.value);
			}

			m_Vec2UniformsUpdated.clear();

			for (const auto& uniform : m_Vec3UniformsUpdated)
			{
				m_Shader->LoadVector3f(uniform.name, uniform.value);
			}

			m_Vec3UniformsUpdated.clear();

			for (const auto& uniform : m_Mat4UniformsUpdated)
			{
				m_Shader->LoadMatrix4f(uniform.name, uniform.value);
			}

			m_Mat4UniformsUpdated.clear();
		}
	}
}