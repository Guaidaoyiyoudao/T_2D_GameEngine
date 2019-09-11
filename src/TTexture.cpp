#include "TTexture.h"
#include "Camera.h"
#include "Render.h"
#include "TWindow.h"
TTexture::TTexture(Render* renderer)
{
	_width = 0;
	_height = 0;
	_texture = nullptr;
	_renderer = renderer;
}

TTexture::~TTexture()
{
	free();
}
void TTexture::free()
{
	if (_texture != nullptr)
	{
		SDL_DestroyTexture(_texture);
		_width = 0;
		_height = 0;
		_texture = nullptr;
	}
}

bool TTexture::loadFromFile(std::string path)
{
	//s释放已经加载的texture
	free();

	SDL_Texture* newTexture = nullptr;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface != nullptr)
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 113, 102, 79));

		//创建texture

		newTexture = SDL_CreateTextureFromSurface(_renderer->getRenderer(), loadedSurface);

		_width = loadedSurface->w;
		_height = loadedSurface->h;
	}

	SDL_FreeSurface(loadedSurface);


	_texture = newTexture;

	return _texture != nullptr;
}

bool TTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{


	return true;


}

SDL_Texture* TTexture::getTexture() const
{
	return this->_texture;
}


// srcRect是物体的材质渲染坐标,rendererRect是物体在世界中的坐标
void TTexture::render(const SDL_Rect* srcRect,const SDL_Rect* renderRect)
{
	SDL_Rect screen_coor = *renderRect;
	int width, height;
	SDL_GetWindowSize(TWindow::GetWindow()->getWindow(), &width, &height);
	screen_coor.x = renderRect->x - Camera::getCamera()->getX();
	screen_coor.y = renderRect->y - Camera::getCamera()->getY();
	//位于屏幕里面才渲染
	if(screen_coor.x>-screen_coor.w&&screen_coor.x<width&&screen_coor.y>-screen_coor.h&&screen_coor.y<height)
		SDL_RenderCopy(_renderer->getRenderer(), _texture, srcRect, &screen_coor);

}
void TTexture::setBlendMode(const SDL_BlendMode& blending)
{
	SDL_SetTextureBlendMode(this->_texture, blending);
}

int TTexture::getHeight()const
{
	return _height;
}
int TTexture::getWidth()const
{
	return _width;
}