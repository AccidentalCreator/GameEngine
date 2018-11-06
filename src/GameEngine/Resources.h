#pragma once
#ifndef  RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <string>
#include <memory>

class MeshRenderer;
class Material;
//class Sound;

// Need to:
// Store the resources - add to vector
// Check resources

class VertexArray;

class Resources
{
public:
	bool CheckMeshUsed(std::string _meshPath);
	std::shared_ptr<VertexArray> GetMeshData();
	void AddMeshData(std::shared_ptr<VertexArray> _meshData);

private:
	std::vector<std::shared_ptr<VertexArray>> meshResources;
	std::vector<std::string> meshPaths;
	

	//std::vector<MeshRenderer> soundResources;
	//std::vector<Sound> materialResources;

	std::vector<std::string> soundPaths;
	std::vector<std::string> materialPaths;

	int meshIndex;
	

};

#endif // ! RESOURCES_H
