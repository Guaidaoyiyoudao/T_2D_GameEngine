/*
����������Ⱦ�����е�UI��Object
*/
#pragma once


#include <string>
#include <vector>
#include <SDL.h>
#include <string>
#include "Map.h"
#include "TObject.h"
#include "Render.h"
#include "Camera.h"
/*
	ʹ�õ���ģʽ
*/

class TWindow
{

public:

	//��ȡʵ��
	static TWindow* GetWindow()
	{
		static TWindow window;
		return &window;
	}

	//��ʼ��
	void Init(const std::string& t, unsigned int x, unsigned int y, const int w, const int h);
	//����
	~TWindow();

	//��ֹ���Ƹ�ֵ����
	TWindow(TWindow& t) = delete;
	TWindow& operator =(TWindow& t) = delete;


	//get window
	SDL_Window* getWindow()const;
	void addObject(TObject*);
	void renderObjects()const;

	Render* getRenderer()const;

	//����Ϊ�������
	void responseEvent(const SDL_Event& e);
	void nothingHappen();




private:
	TWindow();


	/*
		************************** ���� **************************
	*/
	std::string _title;
	int _x;
	int _y;
	int _width;
	int _height;


	/*
		************************** ��� **************************
	*/

	SDL_Window* _window = nullptr;
	Render* _renderer;
	//��ͼ
	Map* map;
	std::vector<TObject*> objects;

	/*
		************************** ��ʱ�� **************************
	*/




};


