/*
该类用于渲染程序中的UI，Object
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
	使用单例模式
*/

class TWindow
{

public:

	//获取实例
	static TWindow* GetWindow()
	{
		static TWindow window;
		return &window;
	}

	//初始化
	void Init(const std::string& t, unsigned int x, unsigned int y, const int w, const int h);
	//析构
	~TWindow();

	//禁止复制赋值构造
	TWindow(TWindow& t) = delete;
	TWindow& operator =(TWindow& t) = delete;


	//get window
	SDL_Window* getWindow()const;
	void addObject(TObject*);
	void renderObjects()const;

	Render* getRenderer()const;

	//负责为各个组件
	void responseEvent(const SDL_Event& e);
	void nothingHappen();




private:
	TWindow();


	/*
		************************** 属性 **************************
	*/
	std::string _title;
	int _x;
	int _y;
	int _width;
	int _height;


	/*
		************************** 组件 **************************
	*/

	SDL_Window* _window = nullptr;
	Render* _renderer;
	//地图
	Map* map;
	std::vector<TObject*> objects;

	/*
		************************** 计时器 **************************
	*/




};


