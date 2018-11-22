#include "Sound.h"
#include "Resources.h"
#include "Core.h"

#include <AL\al.h>
#include <vorbis\vorbisfile.h>
#include <iostream>
#include <vector>

struct SoundInit
{
	ALuint id;

	~SoundInit()
	{
		alDeleteBuffers(1, &id);
	}

	void load_ogg(std::string _filePath, std::vector<char> &_buffer,
		ALenum &_format, ALsizei &_freq)
	{
		int endian = 0;
		int bitStream = 0;
		long bytes = 0;
		char array[2048] = { 0 };
		vorbis_info *pInfo = NULL;
		OggVorbis_File oggFile = { 0 };

		// Use inbuilt fopen to create file desciptor
		if (ov_fopen(_filePath.c_str(), &oggFile) != 0)
		{
			std::cout << "Failed to open file '" << _filePath << std::endl;
			throw std::exception();
		}

		// Extract information from  file header
		pInfo = ov_info(&oggFile, -1);

		// Record the format required by OpenAL
		if (pInfo->channels == 1)
		{
			_format = AL_FORMAT_MONO16;
		}
		else
		{
			_format = AL_FORMAT_STEREO16;
		}

		// Record the sample rate 
		_freq = pInfo->rate;

		// Keep reading bytes from the file to populate the output buffer
		while (true)
		{
			// Read bytes into temp array
			bytes = ov_read(&oggFile, array, 2048, endian, 2, 1, &bitStream);

			if (bytes < 0)
			{
				ov_clear(&oggFile);
				std::cout << "Failed to decode file '" << _filePath << std::endl;
				throw std::exception();
			}
			else if (bytes == 0)
			{
				break;
			}

			// Copy from temporary array into output buffer
			_buffer.insert(_buffer.end(), array, array + bytes);
		}

		// Clean up and close file
		ov_clear(&oggFile);
	}
};

void Sound::Start(std::string _path)
{
	Load(_path);
}

void Sound::Load(std::string _path)
{
	std::shared_ptr<Resources> resources = GetCore()->GetResources();

	soundInit = std::make_shared<SoundInit>();

	if (resources->CheckSoundUsed(_path))
	{
		soundInit->id = resources->GetSoundId(_path);
	}
	else
	{
		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;

		alGenBuffers(1, &soundInit->id);

		soundInit->load_ogg(_path.c_str(), bufferData, format, freq);

		alBufferData(soundInit->id, format, &bufferData[0],
			static_cast<ALsizei>(bufferData.size()), freq);

		resources->AddSoundData(_path, soundInit->id);
	}


}

void Sound::Play()
{
	ALuint sid = 0;
	alGenSources(1, &sid);
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(sid, AL_BUFFER, soundInit->id);
	alSourcePlay(sid);
}

void Sound::Play(float _vol, float _varMin, float _varMax)
{
	_varMin *= 1000.0f;
	_varMax *= 1000.0f;

	float variance = (std::rand() % ((int)_varMin + 1 - (int)_varMax) + (int)_varMin) / 1000.0f;

	ALuint sid = 0;
	alGenSources(1, &sid);
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(sid, AL_BUFFER, soundInit->id);
	alSourcef(sid, AL_PITCH, variance);
	alSourcef(sid, AL_GAIN, _vol);
	alSourcePlay(sid);
}