#pragma once

#include"constness.h"

class TObject;
class Camera
{
	const int CAMERA_SPEED = 16;
public:

	static Camera* getCamera()
	{
		static Camera camera;
		return &camera;
	}

	void Init(int, int);
	//����ƶ�
	void move(MOVE_DIRECTION);
	//follow��ζ�Ÿ����彫һֱ������Ļ����
	void follow(TObject*);
	void unfollow();

	int getX()const;
	int getY()const;

	void setX(int x);
	void setY(int y);
	void setXY(int x, int y);

	//
	Camera& operator=(const Camera&) = delete;
	Camera(const Camera&) = delete;
	~Camera();
private:
	Camera();
	bool _following = false;
	TObject* _obj_followed;
	int _x, _y;

};




