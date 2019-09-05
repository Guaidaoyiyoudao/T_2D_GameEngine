/*
该类用于处理事件
*/
#pragma once

#include<SDL_events.h>
class EventHanlder
{

public:

	void EventListen();


private:

	SDL_Event _event;

};


