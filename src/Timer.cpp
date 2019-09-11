#include "Timer.h"

Timer::Timer()
{
	started = false;
	paused = false;

	startTicks = 0;
	pauseTicks = 0;

}

Timer::~Timer()
{
}

void Timer::start()
{
	started = true;
	paused = false;

	startTicks = SDL_GetTicks();
	pauseTicks = 0;
}

void Timer::pause()
{
	if (started && !paused)
	{
		paused = true;

		pauseTicks = SDL_GetTicks() - startTicks;
		startTicks = 0;
	}
}

void Timer::stop()
{
	paused = false;
	started = false;

	startTicks = 0;
	pauseTicks = 0;
}

void Timer::unpause()
{
	if (started && paused)
	{
		paused = false;

		startTicks = SDL_GetTicks() - pauseTicks;
		pauseTicks = 0;
	}
}
//TODO: wancheng
int Timer::getTicks() const
{
	int time = 0;

	if (started)
	{
		if (paused)
		{
			time = SDL_GetTicks() - pauseTicks;
		}
		else
		{
			time = SDL_GetTicks() - startTicks;
		}

	}

	return time;
}
