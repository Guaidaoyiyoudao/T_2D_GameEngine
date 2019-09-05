#pragma once

#include <string>
#include <SDL.h>
#include "TObject.h"


class Player :
	public TObject
{

public:

	const int MOVE_SPEED_X = 5;
	const int MOVE_SPEED_Y = 5;

	Player(const SDL_Rect& dst, const SDL_Rect& src, const std::string& path, const std::string& name, int& frames, Render* renderer);
	~Player();
	void handleEvent(const SDL_Event& e);



private:
};




