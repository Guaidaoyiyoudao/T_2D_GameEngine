
#include "Animation.h"

Animation::Animation(const std::string& path,Render* renderer,const std::string& name,const SDL_Rect& src, int frames)
{

	_name = name;

	_animation = new TTexture(renderer);
	_animation->loadFromFile(path);

	//
	_src = src;
	_current_frame = 0;
	_frames = frames;
	_animation_finished = false;
}

Animation::Animation(TTexture* texture, const std::string& name, const SDL_Rect& src, int frames):
	_animation(texture),_name(name),_src(src),_frames(frames),_current_frame(0),_animation_finished(false)
{
}

void Animation::render(const SDL_Rect& dst)
{
	SDL_Rect tmp = _src;

	tmp.x = tmp.w*_current_frame;

	_animation->render(&tmp, &dst);
	
	_animation_finished = false;
	_current_frame++;

	if (_current_frame >= _frames - 1)
	{
		_current_frame = 0;
		_animation_finished = true;
	}

}

bool Animation::isFinished() const
{
	return _animation_finished;
}


Animation::~Animation()
{

	delete _animation;
}
