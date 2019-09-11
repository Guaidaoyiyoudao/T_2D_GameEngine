#pragma once
#include "TTexture.h"
#include <string>
class Map
{

public:
	Map(Render* renderer);

	~Map();
	

	bool loadMap(std::string path);
	void  renderMap()const;



private:



	//根据相机位置加载地图
	TTexture* _map;


};

