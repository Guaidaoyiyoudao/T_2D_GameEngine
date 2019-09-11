#include "Map.h"
#include "Render.h"
#include "TWindow.h"
#include"Camera.h"
Map::Map(Render* renderer)
{
	_map = new TTexture(renderer);
}

Map::~Map()
{

	delete _map;
}

bool Map::loadMap(std::string path)
{
	return _map->loadFromFile(path);
}

void Map::renderMap() const
{

	int width, height;
	int x, y;
	x = Camera::getCamera()->getX();
	y = Camera::getCamera()->getY();
	SDL_GetWindowSize(TWindow::GetWindow()->getWindow(), &width, &height);
	SDL_Rect dst = { x,y,width,height };
	SDL_Rect src = { x,y,width,height };
	_map->render(&src,&dst);
}
