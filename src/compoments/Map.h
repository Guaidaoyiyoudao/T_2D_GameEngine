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



	//�������λ�ü��ص�ͼ
	TTexture* _map;


};

