#include "Camera.h"
#include "TObject.h"
Camera::Camera()
{
}
void Camera::Init(int x=0, int y=0)
{
	_x = x;
	_y = y;

}

void Camera::move(MOVE_DIRECTION direction)
{
	//Ã»ÓÐ¸úËæ
	if (!_following)
	{
		switch (direction)
		{
		case MOVE_DIRECTION::UP:
			if (_y >= CAMERA_SPEED)
				_y -= CAMERA_SPEED;
			else
				_y = 0;
			break;
		case MOVE_DIRECTION::DOWN:
			_y += CAMERA_SPEED;
			break;
		case MOVE_DIRECTION::LEFT:
			if (_x >= CAMERA_SPEED)
				_x -= CAMERA_SPEED;
			else
				_x = 0;
			break;
		case MOVE_DIRECTION::RIGHT:
			_x += CAMERA_SPEED;
			break;
		default:
			break;
		}



	}
	else
	{


	}

}

void Camera::follow(TObject* obj)
{
	_following = true;
	_obj_followed = obj;
}

void Camera::unfollow()
{
	if (_following)
	{
		_following = false;
		_obj_followed = nullptr;
	}
}

int Camera::getX() const
{
	return _x;
}

int Camera::getY() const
{
	return _y;
}

void Camera::setX(int x)
{
	_x = x;
}

void Camera::setY(int y)
{
	_y = y;
}

void Camera::setXY(int x, int y)
{
	_x = x;
	_y = y;
}

Camera::~Camera()
{
}
