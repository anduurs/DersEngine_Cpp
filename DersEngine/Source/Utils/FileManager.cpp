#include "Utils\FileManager.h"
#include "Debug\DebugLogging.h"
#include <iostream>
#include <fstream>
#include <vector>

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
	}
}