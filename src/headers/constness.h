#pragma once
/*
	֡�����
*/
constexpr int FRAME = 120;
constexpr int FRAME_PER_SECOND = 1000 / FRAME;
constexpr int ANIMATION_DIRECTION_NUM = 4;



//����ƶ�
enum class Animation_DIRECTION
{
	ANIMATION_UP,
	ANIMATION_LEFT,
	ANIMATION_DOWN,
	ANIMATIOn_RIGHT,
	DIRECTION_NUMBERS
};

//�ƶ�����
enum class MOVE_DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};