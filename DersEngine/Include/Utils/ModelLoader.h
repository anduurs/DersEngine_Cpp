#pragma once

#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Graphics\Mesh.h"
#include "Graphics\Texture.h"
#include "Graphics\Model.h"

namespace DersEngine
{
	namespace Utils
	{
		using namespace Graphics;

		Model LoadModel(const std::string& path, Model& model);

		void ProcessNode(aiNode* node, const aiScene* scene, Model& model);

		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene, Model& model);
	}
}