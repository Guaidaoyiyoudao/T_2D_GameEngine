#include"EventHandler.h"
#include "Player.h"
#include "TWindow.h"
#include "Timer.h"
#include "constness.h"
#include "Camera.h"
/*
该函数负责响应与具体对象无关的事件:
	1.窗口事件
	2.部分按键事件

*/
void EventHanlder::EventListen()
{
	TWindow* window = TWindow::GetWindow();
	window->Init("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 640);

	//帧率控制为60帧每秒
	Timer frameTimer;
	bool quit = false;
	while (!quit)
	{

		frameTimer.start();
		
		window->getRenderer()->clear();
		window->renderObjects();
		if (SDL_PollEvent(&_event) != 0)
		{
			
			if (_event.type == SDL_QUIT)
				quit = true;
			//ESC程序退出
			if (_event.type == SDL_KEYDOWN)
			{
				switch (_event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					quit = true;
					break;
				default:
					break;
				}
			}
			//鼠标单击事件
			if (_event.type == SDL_MOUSEBUTTONDOWN&&_event.button.button==SDL_BUTTON_LEFT)	
			{
				
				int x = _event.button.x;
				int y = _event.button.y;
				SDL_Rect dst = { x,y,64,64 };
				SDL_Rect src = { 0,0,144,64 };
				int frames = 22;
				Player* p = 
					new Player(dst,src,
						"C:\\Users\\Guaidaoyiyoudao\\Pictures\\KnightAttack_strip.png",
						"NPC Death",frames,window->getRenderer());

				window->addObject(p);

	
				
			}

			//相机移动 Q->left,E->right;
			
			if (_event.type == SDL_KEYDOWN)
			{
				switch (_event.key.keysym.sym)
				{
					MOVE_DIRECTION direction;
				case SDLK_q:
					direction = MOVE_DIRECTION::LEFT;
					Camera::getCamera()->move(direction);
					break;
				case SDLK_e:
					direction = MOVE_DIRECTION::RIGHT;
					Camera::getCamera()->move(direction);
					break;
			
				default:
					break;
				}
			}


			//对象自处理事件
			
			window->responseEvent(_event);
		}

		int frameTicks = frameTimer.getTicks();
		if (frameTicks < FRAME_PER_SECOND)
		{
			SDL_Delay(FRAME_PER_SECOND - frameTicks);
		}

		

	}
	
}