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


	//����Ļ����Ⱦ����
	virtual void show() = 0;


	//TObject��ʵ�ָú�����ÿ�����嶼���Լ���Ӧ����Ϊ��Ӧ
	virtual void handleEvent(const SDL_Event& e) = 0;

	//û���¼�����
	virtual void doNothing() = 0;

	//�������
	int getWidth()const;
	int getHeight()const;
	
	//setter getter
	//����
	inline void setX(int);
	inline void setY(int);
	void setXY(int x, int y);
	int getX()const;
	int getY()const;
	const SDL_Rect& getXY()const;
	//״̬
	STATE getState()const;
	void setState(STATE state);
	//����
	Animation_DIRECTION getDirection()const;
	void setDirection(Animation_DIRECTION direction);



	void setPriorty(int priorty);
	

private:
	
	//��������
	//std::string name;

	//��������
	SDL_Rect _dst;

	/*
		��Ⱦ���ȼ�(�߶�)
		0���
		Խ��Խ��

	*/
	int _render_priority;

	//����״̬
	STATE _state;

	//�����泯����
	Animation_DIRECTION _direction;
	
};

