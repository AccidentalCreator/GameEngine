#pragma once
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

namespace GameEngine
{
	/**
	* Handles delta time
	*/
	class Environment
	{
	public:
		/// Environment constructor
		Environment();
		/// Environment destructor
		~Environment();
		/// Returns delta time
		float GetDeltaTime() { return deltaTime; }
		/// Calculates deta time
		void CalculateDeltaTime();

	private:
	
		double deltaTime;
		double newTime;
		double lastTime;
	};

}


#endif