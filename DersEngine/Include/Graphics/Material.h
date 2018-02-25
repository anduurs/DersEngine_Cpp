#pragma once

#include <vector>

#include "Graphics\Texture.h"


namespace DersEngine
{
	namespace Graphics
	{
		struct Vector2f;
		struct Vector3f;
		class Shader;

		struct UniformBool
		{
			std::string name;
			char value;
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
			Vector2f value;
		};

		struct UniformVector3f
		{
			std::string name;
			Vector3f value;
		};

		struct Material
		{
			unsigned int id;

			Shader* shader;

			std::vector<Texture> textures;
			std::vector<UniformBool> uniforms_bool;
			std::vector<UniformInt> uniforms_int;
			std::vector<UniformFloat> uniforms_float;
			std::vector<UniformVector2f> uniforms_vector2D;
			std::vector<UniformVector3f> uniforms_ vector3D;
		};

		
	}
}
