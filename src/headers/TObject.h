#pragma once
#include <string>
#include <SDL.h>
#include <SDL_events.h>
#include "Animation.h"
#include "Render.h"


enum class STATE
{
	WALK,
	ATTACK,
	DEATH,
	JUMP,
	STAND,
	FALL
};

class TObject
{
public:


	TObject(const SDL_Rect& dst,const SDL_Rect& src,const std::string& name, int& frames,int render_priority );
	virtual ~TObject();


	//在屏幕上渲染对象
	virtual void show() = 0;


	//TObject不实现该函数，每个物体都有自己相应的行为响应
	virtual void handleEvent(const SDL_Event& e) = 0;

	//没有事件发生
	virtual void doNothing() = 0;

	//属性相关
	int getWidth()const;
	int getHeight()const;
	
	//setter getter
	//坐标
	inline void setX(int);
	inline void setY(int);
	void setXY(int x, int y);
	int getX()const;
	int getY()const;
	const SDL_Rect& getXY()const;
	//状态
	STATE getState()const;
	void setState(STATE state);
	//方向
	Animation_DIRECTION getDirection()const;
	void setDirection(Animation_DIRECTION direction);



	void setPriorty(int priorty);
	

private:
	
	//物体名称
	//std::string name;

	//物体坐标
	SDL_Rect _dst;

	/*
		渲染优先级(高度)
		0最高
		越大越低

	*/
	int _render_priority;

	//物体状态
	STATE _state;

	//物体面朝方向
	Animation_DIRECTION _direction;
	
};

