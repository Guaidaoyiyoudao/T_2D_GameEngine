#pragma once

#include<SDL.h>
class Render
{
public:
	Render(SDL_Window*);
	~Render();

	void present() const;

	void clear();

	SDL_Renderer* getRenderer()const;

private:

	SDL_Renderer* _renderer;
	SDL_Texture* _texture;

};





