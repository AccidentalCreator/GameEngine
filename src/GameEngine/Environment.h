#pragma once
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

namespace GameEngine
{

	class Environment
	{
	public:
		Environment();
		~Environment();
		float GetDeltaTime() { return deltaTime; }
		void CalculateDeltaTime();

	private:
	
		double deltaTime;
		double newTime;
		double lastTime;
	};

}


#endif