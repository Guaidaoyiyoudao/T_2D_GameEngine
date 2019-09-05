#pragma once
#include <string>
#include <SDL.h>
#include <SDL_events.h>
#include "Animation.h"
#include "Render.h"


class TObject
{
public:


	TObject(const SDL_Rect& dst,const SDL_Rect& src, const std::string& path, const std::string& name, int& frames, Render* renderer, int render_priority );
	virtual ~TObject();


	//在屏幕上渲染对象
	virtual void show();


	//TObject不实现该函数，每个物体都有自己相应的行为响应
	virtual void handleEvent(const SDL_Event& e) = 0;

	//属性相关
	int getWidth()const;
	int getHeight()const;

	//坐标
	inline void setX(int);
	inline void setY(int);
	void setXY(int x, int y);
	int getX()const;
	int getY()const;

	void setPriorty(int priorty);
	

private:

	Animation*  _Animation;
	SDL_Rect _dst;

	/*
		渲染优先级:
		0最高
		越大越低

	*/
	int _render_priority;

	
};

