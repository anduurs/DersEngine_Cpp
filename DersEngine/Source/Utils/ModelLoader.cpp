#include "Utils\ModelLoader.h"
#include "Debug\DebugLogging.h"
#include "Graphics\Vertex.h"

namespace DersEngine
{
	namespace Utils
	{
		Model LoadModel(const std::string& path)
		{
			// Imports a model and stores it into a assimp scene structure
			Assimp::Importer importer;
			// aiProcess_Triangulate = transform all the model's primitive shapes to triangles 
			// if the model does not (entirely) consist of triangles
			// aiProcess_FlipUVs = flips the texture coordinates on the y-axis where necessary during processing
			const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

			if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
			{
				Debug::Log("ERROR::ASSIMP::", importer.GetErrorString());
				return {};
			}

			Model model;

			model.directory = path.substr(0, path.find_last_of('/'));
		
			ProcessNode(scene->mRootNode, scene, model);

			return model;
		}

		void ProcessNode(aiNode* node, const aiScene* scene, Model& model)
		{
			for (u32 i = 0; i < node->mNumMeshes; i++)
			{
				aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
				model.meshes.emplace_back(ProcessMesh(mesh, scene, model));
			}

			for (u32 i = 0; i < node->mNumChildren; i++)
			{
				ProcessNode(node->mChildren[i], scene, model);
			}
		}

		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene, Model& model)
		{
			Mesh resultMesh;

			std::vector<Vertex> vertices;
			std::vector<u32> indices;

			u32 numOfVertices = mesh->mNumVertices;

			for (u32 i = 0; i < numOfVertices; i++)
			{
				Vertex vertex;

				vertex.position.x = mesh->mVertices[i].x;
				vertex.position.y = mesh->mVertices[i].y;
				vertex.position.z = mesh->mVertices[i].z;

				vertex.normal.x = mesh->mNormals[i].x;
				vertex.normal.y = mesh->mNormals[i].y;
				vertex.normal.z = mesh->mNormals[i].z;

				if (mesh->mTextureCoords[0])
				{
					vertex.textureCoordinate.x = mesh->mTextureCoords[0][i].x;
					vertex.textureCoordinate.y = mesh->mTextureCoords[0][i].y;
				}
				else
				{
					vertex.textureCoordinate.x = 0.0f;
					vertex.textureCoordinate.y = 0.0f;
				}

				vertices.emplace_back(vertex);
			}

			for (u32 i = 0; i < mesh->mNumFaces; i++)
			{
				aiFace face = mesh->mFaces[i];

				for (u32 j = 0; j < face.mNumIndices; j++)
				{
					indices.emplace_back(face.mIndices[i]);
				}
			}

			if (mesh->mMaterialIndex >= 0)
			{
				u32 materialIndex = mesh->mMaterialIndex;
				aiMaterial* material = scene->mMaterials[materialIndex];
				//Material* mat = resultMesh.material;

				std::vector<Texture> diffuseMaps =
					LoadMaterialTextures(material, aiTextureType_DIFFUSE, TextureType::DIFFUSE, model);

				//meshMaterial->textures.insert(meshMaterial->textures.end(), diffuseMaps.begin(), diffuseMaps.end());

				std::vector<Texture> specularMaps =
					LoadMaterialTextures(material, aiTextureType_SPECULAR, TextureType::SPECULAR, model);

				//meshMaterial->textures.insert(meshMaterial->textures.end(), specularMaps.begin(), specularMaps.end());

				std::vector<Texture> normalMaps =
					LoadMaterialTextures(material, aiTextureType_HEIGHT, TextureType::NORMAL, model);

				//meshMaterial->textures.insert(meshMaterial->textures.end(), normalMaps.begin(), normalMaps.end());
			}

			resultMesh.indices = indices.size();
			resultMesh.id = OpenGL::UploadMeshData(vertices, indices);

			return resultMesh;
		}

		std::vector<Texture> LoadMaterialTextures(aiMaterial* material,
			aiTextureType type, TextureType textureType, Model& model)
		{
			std::vector<Texture> textures;

			for (u32 i = 0; i < material->GetTextureCount(type); i++)
			{
				aiString textureFilePath;
				material->GetTexture(type, i, &textureFilePath);

				bool skip = false;

				for (u32 j = 0; j < model.loadedTextures.size(); j++)
				{
					if (std::strcmp(model.loadedTextures[j].path.data(), textureFilePath.C_Str()) == 0)
					{
						textures.emplace_back(model.loadedTextures[j]);
						skip = true;
						break;
					}
				}

				if (!skip)
				{
					Texture texture;
					texture.id = OpenGL::LoadTextureFromFile(textureFilePath.C_Str(), model.directory);
					texture.type = textureType;
					texture.textureSlot = i;
					texture.path = textureFilePath.C_Str();
					textures.emplace_back(texture);
					model.loadedTextures.emplace_back(texture);
				}
			}

			return textures;
		}
	}
}