#pragma once
#ifndef TIMER_H
#define TIMER_H
#include <time.h>

namespace GameEngine
{

	class Timer
	{
	public:
		Timer();
		~Timer();

		void Start(float _endTime);
		bool Running();
	private:
		bool running;

		time_t timer2;
		double startTime;
		float endTime;
		double seconds;
	};

}


#endif // !TIMER_H
