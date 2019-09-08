#pragma once
/*
	帧率相关
*/
constexpr int FRAME = 120;
constexpr int FRAME_PER_SECOND = 1000 / FRAME;
constexpr int ANIMATION_DIRECTION_NUM = 4;



//玩家移动
enum class Animation_DIRECTION
{
	ANIMATION_UP,
	ANIMATION_LEFT,
	ANIMATION_DOWN,
	ANIMATIOn_RIGHT,
	DIRECTION_NUMBERS
};

//移动方向
enum class MOVE_DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};