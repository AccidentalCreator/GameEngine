#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment
{
public:
	float GetDeltaTime() { return deltaTime; }

private:
	float deltaTime;
};

#endif