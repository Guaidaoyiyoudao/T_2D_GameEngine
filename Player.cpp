
#include "Player.h"

Player::Player(const SDL_Rect& dst,const SDL_Rect& src, const std::string& path, const std::string& name, int& frames, Render* renderer)
	:TObject(dst,src,path,name,frames,renderer,0)
{
}

Player::~Player()
{
}

void Player::handleEvent(const SDL_Event& e)
{
	
	//Êó±êµã»÷
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		int x = 0, y = 0;
		switch (e.button.button)
		{

		case SDL_BUTTON_RIGHT:
			x = e.button.x;
			y = e.button.y;
			this->setXY(x, y);
			break;
			
		default:
			break;
		}
	}
	//¼üÅÌÒÆ¶¯
	if (e.type == SDL_KEYDOWN)
	{
		int x = this->getX();
		int y = this->getY();
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			if (y > MOVE_SPEED_Y)
				this->setY(y - MOVE_SPEED_Y);
			else
				this->setY(0);
			break;
		case SDLK_a:
			if (x > MOVE_SPEED_X)
				this->setX(x - MOVE_SPEED_X);
			else
				this->setX(0);
			break;
		case SDLK_d:
			
			this->setX(x + MOVE_SPEED_X);
			break;
		case SDLK_s:

			this->setY(y+MOVE_SPEED_Y);
			break;

		default:
			break;
		}

	}

}