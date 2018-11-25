#include "Resources.h"
#include "VertexArray.h"

namespace GameEngine
{

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
		for (size_t i = 0; i < soundsUsed.size(); i++)
		{
			if (soundsUsed.at(i).path == _path)
			{
				return true;
			}
		}
		SoundResource s;
		s.path = _path;
		soundsUsed.push_back(s);
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

	ALuint Resources::GetSoundId(std::string _path)
	{
		for (size_t i = 0; i < soundsUsed.size(); i++)
		{
			if (soundsUsed.at(i).path == _path)
			{
				return soundsUsed.at(i).id;
			}
		}
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

	void Resources::AddSoundData(std::string _path, ALuint _id)
	{
		for (size_t i = 0; i < soundsUsed.size(); i++)
		{
			if (soundsUsed.at(i).path == _path)
			{
				soundsUsed.at(i).id = _id;
			}
		}
	}

}

