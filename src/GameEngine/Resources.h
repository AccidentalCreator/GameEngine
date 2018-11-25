#pragma once
#ifndef  RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <string>
#include <memory>
#include <AL\al.h>

#include "VertexArray.h"

namespace GameEngine
{

	class MeshRenderer;
	class Material;
	class Sound;

	/// Stores material path and buffer id
	struct MatResource
	{
		std::string path;
		GLuint id;
	};

	/// Stores mesh path and mesh data
	struct MeshResource
	{
		std::string path;
		VertexArray data;
	};

	/// Stores sound path and sound buffer id
	struct SoundResource
	{
		std::string path;
		ALuint id;
	};

	/**
	* Checks if a asset has preiviously been used. If so returns the buffer location to be reused
	*/
	class Resources
	{
	public:
		/// Checks if the mesh has been preiviously loaded
		bool CheckMeshUsed(std::string _path);
		/// Checks if the material has been prieviously loaded
		bool CheckMaterialUsed(std::string _path);
		/// Checks if the sound has been prieviously loaded
		bool CheckSoundUsed(std::string _path);

		/// Retrieves the mesh data
		std::shared_ptr<VertexArray> GetMeshData(std::string _path);
		/// Retrieves the material buffer id
		GLuint GetMatId(std::string _path);
		/// Retrieves the sound buffer id
		ALuint GetSoundId(std::string _path);

		/// Adds a mesh path and data to a list
		void AddMeshData(std::shared_ptr<VertexArray> _data, std::string _path);
		/// Adds a material path and data to a list
		void AddMatData(std::string _path, GLuint _id);
		/// Adds sound path and data to a list
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

}


#endif // ! RESOURCES_H
