#include "TWindow.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
TWindow::~TWindow()
{
	//�ͷŴ���
	if (this->_window != nullptr)
		SDL_DestroyWindow(this->_window);
	//�ͷŶ���
	for (auto obj : objects)
		delete obj;
	//�ͷ���Ⱦ��
	delete this->_renderer;

	//�ͷŵ�ͼ
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

	//��ʼ��
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_PNG);	
	TTF_Init();

	//��ʼ�����
	Camera::getCamera()->Init(0,0);
	

	//��������
	this->_window = SDL_CreateWindow(_title.c_str(), _x, _y, _width, _height, SDL_WINDOW_RESIZABLE);

	//��ʼ����Ⱦ��
	this->_renderer = new Render(this->_window);

	//��ʼ����ͼ,��ͼ��ʼ��Ӧ������Ⱦ������
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


//��Ⱦ����
void TWindow::renderObjects()const
{
	//��ͼ������Ⱦ
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

//Ϊ�����ṩ�¼�
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
