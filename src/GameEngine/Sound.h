#pragma once
#ifndef SOUND_H
#define SOUND_H

#include <memory>
#include <string>

#include "Component.h"

namespace GameEngine
{

	struct SoundInit;
	/**
	*	Handles sound
	*/
	class Sound : public Component
	{
		std::shared_ptr<SoundInit> soundInit;

	public:
		/// Initialisation
		void Start(std::string _filePath);

		/// Loads the data from the given file path
		void Load(std::string _filePath);
		/// Outputs the sound of the file
		void Play(float _volume, float _varMin, float _varMax);
		/// Outputs the sound of the file
		void Play();

	private:
		bool dirty;
	};

}

#endif // !SOUND_H