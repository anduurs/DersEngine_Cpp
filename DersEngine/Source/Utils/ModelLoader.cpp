#include "Utils\ModelLoader.h"
#include "Debug\DebugLogging.h"
#include "Platform\OpenGL\GLTextureLoader.h"
#include "Platform\OpenGL\GLRenderer.h"
#include "Graphics\Vertex.h"

namespace DersEngine
{
	namespace Utils
	{
		Model LoadModel(const std::string& path, Model& model)
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
		
			ProcessNode(scene->mRootNode, scene, model);

			return model;
		}

		void ProcessNode(aiNode* node, const aiScene* scene, Model& model)
		{
			for (unsigned int i = 0; i < node->mNumMeshes; i++)
			{
				aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
				model.meshes.emplace_back(ProcessMesh(mesh, scene, model));
			}

			for (unsigned int i = 0; i < node->mNumChildren; i++)
			{
				ProcessNode(node->mChildren[i], scene, model);
			}
		}

		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene, Model& model)
		{
			Mesh resultMesh;

			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;

			unsigned int numOfVertices = mesh->mNumVertices;

			for (unsigned int i = 0; i < numOfVertices; i++)
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

			for (unsigned int i = 0; i < mesh->mNumFaces; i++)
			{
				aiFace face = mesh->mFaces[i];

				for (unsigned int j = 0; j < face.mNumIndices; j++)
				{
					indices.emplace_back(face.mIndices[i]);
				}
			}

			resultMesh.numOfIndices = indices.size();
			resultMesh.id = OpenGL_API::UploadMeshData(vertices, indices);

			return resultMesh;
		}
	}
}