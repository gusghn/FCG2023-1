#pragma once

#include <chrono>
#include <thread>
#include <ctime>

class Timer
{
protected:
	std::chrono::time_point<std::chrono::system_clock>begin, end;
public:
	Timer() {}

	void start() 
	{
		begin = std::chrono::system_clock::now();
	}

	void finish()
	{
		end = std::chrono::system_clock::now();
	}

	double getElapsedTimeMs()
	{
		std::chrono::duration<double> elapsed_seconds = end - begin;
		return elapsed_seconds.count() * 1000;
	}

	double getElapsedTime()
	{
		std::chrono::duration<double> elapsed_seconds = end - begin;
		return elapsed_seconds.count();
	}

	double calcWaitingTime(int fps, double elapsedTime) 
	{
		return 1000 / (double)fps - elapsedTime;
	}

	void sleepFps(int fps) 
	{
		double waitingTime = calcWaitingTime(fps, getElapsedTimeMs());

		if (waitingTime)
			std::this_thread::sleep_for(std::chrono::milliseconds((int)waitingTime));
	}
};