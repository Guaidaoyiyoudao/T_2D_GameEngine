#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Render.h"

class TTexture
{
public:

	TTexture(Render* renderer);
	~TTexture();
	void free();

	//��·���м���һ��ͼƬ
	bool loadFromFile(std::string path);
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);


	SDL_Texture* getTexture()const;

	//����͸����
	void setBlendMode(const SDL_BlendMode& blending);

	void render(SDL_Rect* srcRect, SDL_Rect* renderRect);

	int getWidth()const;
	int getHeight()const;

private:

	Render* _renderer;

	SDL_Texture* _texture;
	int _width;
	int _height;
};






