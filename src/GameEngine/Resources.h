#pragma once
#ifndef  RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <string>
#include <memory>

#include "VertexArray.h"

class MeshRenderer;
class Material;
class Sound;

struct MatResource
{
	std::string path;
	GLuint id;
};

struct MeshResource
{
	std::string path;
	VertexArray data;
};

class Resources
{
public:
	bool CheckMeshUsed(std::string _path);
	bool CheckMaterialUsed(std::string _path);
	bool CheckSoundUsed(std::string _path);

	std::shared_ptr<VertexArray> GetMeshData(std::string _path);
	GLuint GetMatId(std::string _path);

	void AddMeshData(std::shared_ptr<VertexArray> _data, std::string _path);
	void AddMatData(std::string _path, GLuint _id);
	
	std::shared_ptr<VertexArray> GetSoundData();
	void AddSoundData(std::shared_ptr<VertexArray> _data, std::string _path);


private:
	std::vector<std::shared_ptr<VertexArray>> meshResources;
	std::vector<std::string> meshPaths;
	
	std::vector<unsigned char*> materialResources;
	std::vector<std::string> materialPaths;

	std::vector<std::shared_ptr<VertexArray>> soundResources;
	std::vector<std::string> soundPaths;

	std::vector<MatResource> materialsUsed;
	std::vector<MeshResource> meshsUsed;

	
};

#endif // ! RESOURCES_H
