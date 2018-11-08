#include "Resources.h"
#include "VertexArray.h"

#include <iostream>

bool Resources::CheckMeshUsed(std::string _path)
{
	for (size_t i = 0; i < meshPaths.size(); i++)
	{
		if (meshPaths.at(i) == _path)
		{
			index = i;
			return true;
		}
	}

	meshPaths.push_back(_path);
	return false;
}

bool Resources::CheckMaterialUsed(std::string _path)
{
	for (size_t i = 0; i < materialPaths.size(); i++)
	{
		if (materialPaths.at(i) == _path)
		{
			index = i;
			return true;
		}
	}

	materialPaths.push_back(_path);
	return false;
}

bool Resources::CheckSoundUsed(std::string _path)
{
	for (size_t i = 0; i < soundPaths.size(); i++)
	{
		if (soundPaths.at(i) == _path)
		{
			index = i;
			return true;
		}
	}

	soundPaths.push_back(_path);
	return false;
}

std::shared_ptr<VertexArray> Resources::GetMeshData()
{
	return meshResources.at(index);
}

unsigned char* Resources::GetMatData()
{
	return materialResources.at(index);
}

std::shared_ptr<VertexArray> Resources::GetSoundData()
{
	return soundResources.at(index);
}

void Resources::AddMeshData(std::shared_ptr<VertexArray> _data)
{
	meshResources.push_back(_data);
}

void Resources::AddMatData(unsigned char* _data)
{
	materialResources.push_back(_data);
}

void Resources::AddSoundData(std::shared_ptr<VertexArray> _data)
{
	soundResources.push_back(_data);
}
