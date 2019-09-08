#include "TWindow.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
TWindow::~TWindow()
{
	//释放窗口
	if (this->_window != nullptr)
		SDL_DestroyWindow(this->_window);
	//释放对象
	for (auto obj : objects)
		delete obj;
	//释放渲染器
	delete this->_renderer;

	//释放地图
	delete map;


	//
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
}
TWindow::TWindow()
{}

void TWindow::Init(const std::string &t, unsigned int x = SDL_WINDOWPOS_CENTERED, unsigned int y = SDL_WINDOWPOS_CENTERED, const int w = 640, const int h = 480)
{
	_title = t;
	_x = x;
	_y = y;
	_height = h;
	_width = w;

	//初始化
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_PNG);	
	TTF_Init();

	//初始化相机
	Camera::getCamera()->Init(0,0);
	

	//创建窗口
	this->_window = SDL_CreateWindow(_title.c_str(), _x, _y, _width, _height, SDL_WINDOW_RESIZABLE);

	//初始化渲染器
	this->_renderer = new Render(this->_window);

	//初始化地图,地图初始化应该在渲染器后面
	map = new Map(_renderer);
	map->loadMap("C:\\Users\\Guaidaoyiyoudao\\Pictures\\Battleground2.png");

}


SDL_Window* TWindow::getWindow() const
{
	return _window;
}

void TWindow::addObject(TObject* obj)
{
	objects.push_back(obj);
}


//渲染物体
void TWindow::renderObjects()const
{
	//地图优先渲染
	map->renderMap();

	for (auto obj : objects)
	{
		obj->show();
	}
	_renderer->present();
}

Render* TWindow::getRenderer()const
{
	return this->_renderer;
}

//为物体提供事件
void TWindow::responseEvent(const SDL_Event& e)
{
	for (auto obj : objects)
	{
		obj->handleEvent(e);
	}
}

void TWindow::nothingHappen()
{
	for (auto obj : objects)
	{
		obj->doNothing();
	}
}
