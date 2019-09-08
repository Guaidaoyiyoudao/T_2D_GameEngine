
#include "Player.h"


//dst是物体的坐标，src是渲染材质的坐标
Player::Player(const SDL_Rect& dst,const SDL_Rect& src,const std::string& path, const std::string& name, int& frames, Render* renderer)
	:TObject(dst,src,name,frames,0)
{

	int x = 0;

	TTexture* texture = new TTexture(renderer);
	texture->loadFromFile(path);
	//paths按照站立，行走，攻击，死亡，跳跃顺序
	for (int i=0;i<ANIMATION_DIRECTION_NUM;i++)
	{
		//TODO: 优化内存使用
		
		//行走
		SDL_Rect tmp = src;
		tmp.y = (8 + i) * 64;
		_walk_animation.push_back(new Animation(texture, name, tmp, 9));
		//攻击
		tmp.y = (16 + i) * 64;
		_attack_animation.push_back(new Animation(texture, name, tmp, 13));
		// 站立
		tmp.y = (12 + i) * 64;
		_stand_animation.push_back(new Animation(texture, name, tmp, 6));


	}

	pre_animation = nullptr;




}

Player::~Player()
{
	if (_walk_animation[0] != nullptr)
		delete _walk_animation[0];
	if (_attack_animation[0] != nullptr)
		delete _attack_animation[0];
	if (_stand_animation[0] != nullptr)
		delete _stand_animation[0];
}

void Player::handleEvent(const SDL_Event& e)
{
	
	//鼠标点击
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
	//键盘移动
	if (e.type == SDL_KEYDOWN)
	{
		int x = this->getX();
		int y = this->getY();
		switch (e.key.keysym.sym)
		{
		//************* 移动控制

		case SDLK_w:
			this->setState(STATE::WALK);
			this->setDirection(Animation_DIRECTION::ANIMATION_UP);
			if (y > MOVE_SPEED_Y)
				this->setY(y - MOVE_SPEED_Y);
			else
				this->setY(0);
			break;
		case SDLK_a:
			this->setState(STATE::WALK);
			this->setDirection(Animation_DIRECTION::ANIMATION_LEFT);
			if (x > MOVE_SPEED_X)
				this->setX(x - MOVE_SPEED_X);
			else
				this->setX(0);
			break;
		case SDLK_d:
			this->setState(STATE::WALK);
			this->setDirection(Animation_DIRECTION::ANIMATIOn_RIGHT);
			
			this->setX(x + MOVE_SPEED_X);
			break;
		case SDLK_s:
			this->setState(STATE::WALK);
			this->setDirection(Animation_DIRECTION::ANIMATION_DOWN);

			this->setY(y+MOVE_SPEED_Y);
			break;
		//************移动控制结束
		//************攻击动画
		case SDLK_j:
			this->setState(STATE::ATTACK);
			break;
		default:
			break;
		}

	}

}
void Player::doNothing()
{
	//如果先前的动画还没有完成，先不设置站立状态
	if (pre_animation->isFinished())
		this->setState(STATE::STAND);
}


//根据物体的不同运动状态展示动画
void Player::show()
{
	//获取物体状态方向位置
	STATE current_state = this->getState();
	Animation_DIRECTION direction = this->getDirection();
	const SDL_Rect& pos = this->getXY();

	switch (current_state)
	{
	case STATE::WALK:
		_walk_animation[static_cast<int>(direction)]->render(pos);
		pre_animation = _walk_animation[static_cast<int>(direction)];
		break;
	case STATE::ATTACK:
		_attack_animation[static_cast<int>(direction)]->render(pos);
		pre_animation = _attack_animation[static_cast<int>(direction)];
		break;
	case STATE::DEATH:
		_death_animation[static_cast<int>(direction)]->render(pos);
		pre_animation = _death_animation[static_cast<int>(direction)];
		break;
	case STATE::JUMP:
		_jump_animation[static_cast<int>(direction)]->render(pos);
		pre_animation = _jump_animation[static_cast<int>(direction)];
		break;
	case STATE::STAND:
		_stand_animation[static_cast<int>(direction)]->render(pos);
		pre_animation = _stand_animation[static_cast<int>(direction)];
		break;
	case STATE::FALL:
		break;
	default:
		break;
	}


}
