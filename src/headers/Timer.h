#pragma once
#include<SDL.h>
class Timer
{
public:
	
	Timer();
	~Timer();

	void start();
	void pause();
	void stop();
	void unpause();

	int getTicks()const;

private:
	bool started;
	bool paused;

	int startTicks;
	int pauseTicks;

};

