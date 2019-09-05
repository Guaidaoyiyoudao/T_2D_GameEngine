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
	//相机移动
	void move(MOVE_DIRECTION);
	//follow意味着该物体将一直处于屏幕中央
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




