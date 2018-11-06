#pragma once
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment
{
public:
	float GetDeltaTime() { return deltaTime; }
	void CalculateDeltaTime();

private:
	
	double deltaTime;
	double newTime;
	double lastTime;
};

#endif