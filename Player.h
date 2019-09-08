#pragma once

#include <string>
#include <SDL.h>
#include "TObject.h"
#include "Animation.h"
#include <vector>



class Player :
	public TObject
{

public:

	const int MOVE_SPEED_X = 5;
	const int MOVE_SPEED_Y = 5;

	Player(const SDL_Rect& dst, const SDL_Rect& src, const std::string& path, const std::string& name, int& frames, Render* renderer);
	~Player();
	void handleEvent(const SDL_Event& e);

	void show();
	void doNothing();



private:

	//TODO: ʵ��������ֶ�������Ⱦ
	//���ֶ���,�ĸ�����վ������·����������������Ծ

	std::vector<Animation*> _stand_animation;
	std::vector<Animation*> _walk_animation;
	std::vector<Animation*> _attack_animation;
	std::vector<Animation*> _death_animation;
	std::vector<Animation*> _jump_animation;


	Animation* pre_animation;


};




