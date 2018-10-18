#pragma once

#ifndef SOUND_H
#define SOUND_H

#include <memory>
#include <string>

struct SoundInit;

class Sound
{
	std::shared_ptr<SoundInit> soundInit;

public:
	Sound();
	Sound(std::string _filePath);


	void Load(std::string _filePath);
	void Play(float _volume, float _varMin, float _varMax);
	void Play();

private:
	bool dirty;
};

#endif // !SOUND_H