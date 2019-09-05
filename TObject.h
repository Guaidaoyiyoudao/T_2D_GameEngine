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


	//����Ļ����Ⱦ����
	virtual void show();


	//TObject��ʵ�ָú�����ÿ�����嶼���Լ���Ӧ����Ϊ��Ӧ
	virtual void handleEvent(const SDL_Event& e) = 0;

	//�������
	int getWidth()const;
	int getHeight()const;

	//����
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
		��Ⱦ���ȼ�:
		0���
		Խ��Խ��

	*/
	int _render_priority;

	
};

