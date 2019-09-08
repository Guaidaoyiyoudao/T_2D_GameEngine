
#pragma once




#include <string>
#include "TTexture.h"
#include "Render.h"
#include "constness.h"

class Animation
{

public:

	Animation(const std::string& path, Render* renderer, const std::string& name, const SDL_Rect& src, int frames);
	Animation(TTexture* texture, const std::string& name, const SDL_Rect& src, int frames);
	void render(const SDL_Rect& dst);
	bool isFinished()const;
	~Animation();

private:
	//��������
	std::string _name;

	//�����Ƿ����
	bool _animation_finished;
	//
	TTexture* _animation;


	//��һ֡��λ��
	SDL_Rect _src;


	int _frames;
	int _current_frame;



};





