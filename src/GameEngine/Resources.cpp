#include "Resources.h"
#include "VertexArray.h"

#include <iostream>

bool Resources::CheckMeshUsed(std::string _meshPath)
{
	for (size_t i = 0; i < meshPaths.size(); i++)
	{
		if (meshPaths.at(i) == _meshPath)
		{
			meshIndex = i;
			std::cout << meshIndex << std::endl;
			return true;
		}
	}

	meshPaths.push_back(_meshPath);
	return false;
}

std::shared_ptr<VertexArray> Resources::GetMeshData()
{
	std::cout << meshIndex << std::endl;
	return meshResources.at(meshIndex);
}

void Resources::AddMeshData(std::shared_ptr<VertexArray> _meshData)
{
	meshResources.push_back(_meshData);
}
