#include "Resources.h"
#include "VertexArray.h"

#include <iostream>

bool Resources::CheckMeshUsed(std::string _path)
{
	for (size_t i = 0; i < meshsUsed.size(); i++)
	{
		if (meshsUsed.at(i).path == _path)
		{
			return true;
		}
	}
	MeshResource r;
	r.path = _path;
	meshsUsed.push_back(r);
	return false;
}

bool Resources::CheckMaterialUsed(std::string _path)
{
	for (size_t i = 0; i < materialsUsed.size(); i++)
	{
		if (materialsUsed.at(i).path == _path)
		{
			return true;
		}
	}
	MatResource r;
	r.path = _path;
	materialsUsed.push_back(r);
	return false;
}

bool Resources::CheckSoundUsed(std::string _path)
{
	for (size_t i = 0; i < soundPaths.size(); i++)
	{
		if (soundPaths.at(i) == _path)
		{
			return true;
		}
	}

	soundPaths.push_back(_path);
	return false;
}

std::shared_ptr<VertexArray> Resources::GetMeshData(std::string _path)
{
	for (size_t i = 0; i < meshsUsed.size(); i++)
	{
		if (meshsUsed.at(i).path == _path)
		{
			return std::make_shared<VertexArray>(meshsUsed.at(i).data);
		}
	}
}

GLuint Resources::GetMatId(std::string _path)
{
	for (size_t i = 0; i < materialsUsed.size(); i++)
	{
		if (materialsUsed.at(i).path == _path)
		{
			return materialsUsed.at(i).id;
		}
	}
}

std::shared_ptr<VertexArray> Resources::GetSoundData()
{
	return soundResources.at(0);
}

void Resources::AddMeshData(std::shared_ptr<VertexArray> _data, std::string _path)
{
	for (size_t i = 0; i < meshsUsed.size(); i++)
	{
		if (meshsUsed.at(i).path == _path)
		{
			meshsUsed.at(i).data = *_data.get();
		}
	}
}

void Resources::AddMatData(std::string _path, GLuint _id)
{
	for (size_t i = 0; i < materialsUsed.size(); i++)
	{
		if (materialsUsed.at(i).path == _path)
		{
			materialsUsed.at(i).id = _id;
		}
	}
}

void Resources::AddSoundData(std::shared_ptr<VertexArray> _data, std::string _path)
{
	soundResources.push_back(_data);
}
