#pragma once
#ifndef  RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <string>
#include <memory>
#include <AL\al.h>

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

struct SoundResource
{
	std::string path;
	ALuint id;
};

class Resources
{
public:
	bool CheckMeshUsed(std::string _path);
	bool CheckMaterialUsed(std::string _path);
	bool CheckSoundUsed(std::string _path);

	std::shared_ptr<VertexArray> GetMeshData(std::string _path);
	GLuint GetMatId(std::string _path);
	ALuint GetSoundId(std::string _path);

	void AddMeshData(std::shared_ptr<VertexArray> _data, std::string _path);
	void AddMatData(std::string _path, GLuint _id);
	void AddSoundData(std::string _path, ALuint _id);


private:
	std::vector<std::shared_ptr<VertexArray>> meshResources;
	std::vector<std::string> meshPaths;
	
	std::vector<std::string> materialPaths;
	std::vector<std::string> soundPaths;

	std::vector<MatResource> materialsUsed;
	std::vector<MeshResource> meshsUsed;
	std::vector<SoundResource> soundsUsed;

	
};

#endif // ! RESOURCES_H
