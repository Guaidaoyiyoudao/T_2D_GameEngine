#include "Render.h"
#include <SDL.h>
Render::Render(SDL_Window * window)
{
	this->_texture = nullptr;
	this->_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(this->_renderer, 0x0, 0x0, 0x0,0x0);

}
Render::~Render()
{
	SDL_DestroyRenderer(this->_renderer);
}

void Render::present()const
{
		SDL_RenderPresent(this->_renderer);
}
void Render::clear()
{
	SDL_RenderClear(this->_renderer);
}
SDL_Renderer* Render::getRenderer() const
 {
	return this->_renderer;
} 