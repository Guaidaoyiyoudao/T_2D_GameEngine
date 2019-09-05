#pragma once
#include"TObject.h"

TObject::TObject(const SDL_Rect& dst,const SDL_Rect& src,const std::string& path,
	const std::string& name,int& frames, Render* renderer,int render_priority)
{
	
	_Animation = new Animation(path, renderer,name,src,frames);



	_dst = dst;

	_render_priority = render_priority;

}



TObject::~TObject()
{
	

	delete _Animation;
}

void TObject::show()
{
	_Animation->render(_dst);
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

void TObject::setPriorty(int priority)
{
	_render_priority = priority;
}