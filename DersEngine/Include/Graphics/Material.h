#pragma once

#include <vector>

#include "MathLibrary\MathHeaders.h"
#include "Graphics\Texture.h"


namespace DersEngine
{
	namespace Graphics
	{
		using namespace Maths;
		class Shader;

		struct UniformTextureSampler
		{
			std::string name;
			Texture value;
		};

		struct UniformInt
		{
			std::string name;
			int value;
		};

		struct UniformFloat
		{
			std::string name;
			float value;
		};

		struct UniformVector2f
		{
			std::string name;
			Vec2f value;
		};

		struct UniformVector3f
		{
			std::string name;
			Vec3f value;
		};

		struct UniformMatrix4f
		{
			std::string name;
			Mat4f value;
		};

		class Material
		{
		protected:
			Shader* m_Shader;

			std::vector<UniformTextureSampler> m_Textures;
			std::vector<UniformTextureSampler> m_TexturesUpdated;

			std::vector<UniformInt> m_IntUniforms;
			std::vector<UniformInt> m_IntUniformsUpdated;

			std::vector<UniformFloat> m_FloatUniforms;
			std::vector<UniformFloat> m_FloatUniformsUpdated;

			std::vector<UniformVector2f> m_Vec2Uniforms;
			std::vector<UniformVector2f> m_Vec2UniformsUpdated;

			std::vector<UniformVector3f> m_Vec3Uniforms;
			std::vector<UniformVector3f> m_Vec3UniformsUpdated;

			std::vector<UniformMatrix4f> m_Mat4Uniforms;
			std::vector<UniformMatrix4f> m_Mat4UniformsUpdated;

		public:
			unsigned int ID;

			Material(Shader* shader);
			~Material();

			void AddTexture(const std::string& name, Texture texture);
			void AddInt(const std::string& name, int value);
			void AddFloat(const std::string& name, float value);
			void AddVec2(const std::string& name, Vec2f value);
			void AddVec3(const std::string& name, Vec3f value);
			void AddMat4(const std::string& name, Mat4f value);

			void UpdateUniforms();

			inline Shader* GetShader() const { return m_Shader; }
		};

		
	}
}
