#include "Utils\FileManager.h"
#include "Debug\DebugLogging.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace DersEngine
{
	namespace Utils
	{
		std::string ReadFile(const std::string& fileName)
		{
			std::ifstream inputStream(fileName.c_str(), 
				std::ios::in | std::ios::binary | std::ios::ate);

			if (inputStream)
			{
				size_t fileSize = inputStream.tellg();
				inputStream.seekg(0, std::ios::beg);

				std::string readBuffer(fileSize, '\0');
				inputStream.read(&readBuffer[0], fileSize);

				return readBuffer;
			}

			Debug::Log("Could not read file: ", fileName.c_str());
			return "file not found";
		}

		void LoadModel(std::string path)
		{
			Assimp::Importer import;
			const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

			if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
			{
				Debug::Log("ERROR::ASSIMP::", import.GetErrorString());
				return;
			}
		}
	}
}