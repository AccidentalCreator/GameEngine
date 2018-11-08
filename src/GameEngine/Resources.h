#pragma once
#ifndef  RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <string>
#include <memory>

class MeshRenderer;
class Material;
class Sound;

// Need to:
// Store the resources - add to vector
// Check resources

class VertexArray;

class Resources
{
public:
	bool CheckMeshUsed(std::string _path);
	bool CheckMaterialUsed(std::string _path);
	bool CheckSoundUsed(std::string _path);

	std::shared_ptr<VertexArray> GetMeshData();
	unsigned char* GetMatData();
	std::shared_ptr<VertexArray> GetSoundData();

	void AddMeshData(std::shared_ptr<VertexArray> _data);
	void AddMatData(unsigned char* _data);
	void AddSoundData(std::shared_ptr<VertexArray> _data);

private:
	std::vector<std::shared_ptr<VertexArray>> meshResources;
	std::vector<std::string> meshPaths;
	
	std::vector<unsigned char*> materialResources;
	std::vector<std::string> materialPaths;

	std::vector<std::shared_ptr<VertexArray>> soundResources;
	std::vector<std::string> soundPaths;

	int index;
	

};

#endif // ! RESOURCES_H
