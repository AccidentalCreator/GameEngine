#include "Timer.h"

namespace GameEngine
{

	Timer::Timer()
	{
		running = false;
	}

	Timer::~Timer()
	{
	}

	void Timer::Start(float _endTime)
	{
		running = true;
		seconds = 0;
		endTime = _endTime;
		startTime = time(&timer2);
	}

	bool Timer::Running()
	{
		seconds = difftime(time(&timer2), startTime);
		if (seconds >= endTime)
		{
			return false;
		}
		return true;
		
	}

}
