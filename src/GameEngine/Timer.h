#pragma once
#ifndef TIMER_H
#define TIMER_H

#include <time.h>

namespace GameEngine
{
	/**
	* Allows a countdown timer to be added
	*/
	class Timer
	{
	public:
		/// Constructor
		Timer();
		/// Destructor
		~Timer();
		/// Initialisation and set end time also starts timer
		void Start(float _endTime);
		/// Checks if the timer has finished or is still running
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
