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


void TTexture::render(SDL_Rect* srcRect,SDL_Rect* renderRect)
{
	int width, height;
	SDL_GetWindowSize(TWindow::GetWindow()->getWindow(), &width, &height);
	int screen_x = renderRect->x - Camera::getCamera()->getX();
	int screen_y = renderRect->y - Camera::getCamera()->getY();
	if(screen_x>0&&screen_x<width&&screen_y>0&&screen_y<height)
		SDL_RenderCopy(_renderer->getRenderer(), _texture,srcRect,renderRect);
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