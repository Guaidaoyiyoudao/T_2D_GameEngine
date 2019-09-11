#pragma once
#include"TObject.h"

TObject::TObject(const SDL_Rect& dst,const SDL_Rect& src,
	const std::string& name,int& frame,int render_priority)
{
	//Ä¬ÈÏ×´Ì¬ÊÇ Õ¾Á¢
	_state = STATE::STAND;
	//Ä¬ÈÏ×´Ì¬ÊÇ ×ó±ß
	_direction = Animation_DIRECTION::ANIMATION_LEFT;




	_dst = dst;
	_render_priority = render_priority;

}



TObject::~TObject()
{
	
}



int TObject::getWidth() const
{
	return _dst.w;
}

int TObject::getHeight() const
{
	return _dst.h;
}

void TObject::setX(int x)
{
	_dst.x = x;
}

void TObject::setY(int y)
{
	_dst.y = y;
}

void TObject::setXY(int x, int y)
{
	setX(x);
	setY(y);
}

int TObject::getX() const
{
	return _dst.x;
}

int TObject::getY() const
{
	return _dst.y;
}

const SDL_Rect& TObject::getXY() const
{
	return _dst;
}

STATE TObject::getState() const
{
	return _state;
}

void TObject::setState(STATE state)
{
	_state = state;
}

Animation_DIRECTION TObject::getDirection() const
{
	return _direction;
}

void TObject::setDirection(Animation_DIRECTION direction)
{
	_direction = direction;
}



void TObject::setPriorty(int priority)
{
	_render_priority = priority;
}