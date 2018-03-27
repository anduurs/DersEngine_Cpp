#pragma once

#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Graphics\Mesh.h"
#include "Graphics\Texture.h"
#include "Graphics\Model.h"
#include "Platform\OpenGL\GLTextureLoader.h"
#include "Platform\OpenGL\GLRenderingUtil.h"

namespace DersEngine
{
	namespace Utils
	{
		using namespace Graphics;
		using namespace Platform;

		Model LoadModel(const std::string& path);

		void ProcessNode(aiNode* node, const aiScene* scene, Model& model);

		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene, Model& model);

		std::vector<Texture> LoadMaterialTextures(aiMaterial* material,
			aiTextureType type, TextureType textureType, Model& model);
	}
}