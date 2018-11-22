#pragma once

#ifndef SOUND_H
#define SOUND_H

#include <memory>
#include <string>

#include "Component.h"

struct SoundInit;

class Sound : public Component
{
	std::shared_ptr<SoundInit> soundInit;

public:
	void Start(std::string _filePath);


	void Load(std::string _filePath);
	void Play(float _volume, float _varMin, float _varMax);
	void Play();

private:
	bool dirty;
};

#endif // !SOUND_H