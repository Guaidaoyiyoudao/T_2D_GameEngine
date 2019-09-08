
#include "Player.h"


//dst����������꣬src����Ⱦ���ʵ�����
Player::Player(const SDL_Rect& dst,const SDL_Rect& src,const std::string& path, const std::string& name, int& frames, Render* renderer)
	:TObject(dst,src,name,frames,0)
{

	int x = 0;

	TTexture* texture = new TTexture(renderer);
	texture->loadFromFile(path);
	//paths����վ�������ߣ���������������Ծ˳��
	for (int i=0;i<ANIMATION_DIRECTION_NUM;i++)
	{
		//TODO: �Ż��ڴ�ʹ��
		
		//����
		SDL_Rect tmp = src;
		tmp.y = (8 + i) * 64;
		_walk_animation.push_back(new Animation(texture, name, tmp, 9));
		//����
		tmp.y = (16 + i) * 64;
		_attack_animation.push_back(new Animation(texture, name, tmp, 13));
		// վ��
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
	
	//�����
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
	//�����ƶ�
	if (e.type == SDL_KEYDOWN)
	{
		int x = this->getX();
		int y = this->getY();
		switch (e.key.keysym.sym)
		{
		//************* �ƶ�����

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
		//************�ƶ����ƽ���
		//************��������
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
	//�����ǰ�Ķ�����û����ɣ��Ȳ�����վ��״̬
	if (pre_animation->isFinished())
		this->setState(STATE::STAND);
}


//��������Ĳ�ͬ�˶�״̬չʾ����
void Player::show()
{
	//��ȡ����״̬����λ��
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
