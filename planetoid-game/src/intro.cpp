#include "graphic-manager-interface.h"
#include "intro.h"
#include "error.h"

Intro::~Intro()
{
	if (initialized_)
	{
		Cleanup();
	}
}

void Intro::Init()
{
	initialized_ = true;
	paused_ = false;

	rectangle_ = { 100, 100, 50, 50 };
	rectangle_.forces = { 0.0f, 0.0f }; 

	ground_ = { 0, 360, 1280, 360 };


	go_down = false;
}

void Intro::Cleanup()
{
	initialized_ = false;
}

void Intro::Pause()
{
	paused_ = true;
}

void Intro::Resume()
{
	paused_ = false;
}

void Intro::Update()
{
	rectangle_.x += 1;
	rectangle_.y += 1;

}

void Intro::Render(IGraphicManager * graphic_manager, float interpolation)
{
	graphic_manager->FillColor({ 30, 50, 60 });

	float view_x = rectangle_.x + (rectangle_.forces.x * interpolation);
	float view_y = rectangle_.y + (rectangle_.forces.y * interpolation);

	graphic_manager->DrawRectangle(
	{ ground_.x, ground_.y, ground_.width, ground_.height },
	{ 75, 110, 130 });

	graphic_manager->DrawRectangle(
	{ view_x, view_y, rectangle_.width, rectangle_.height },
	{ 230, 240, 255 });

	graphic_manager->Render(interpolation);
}

inline bool Intro::IsInitialized()
{
	return initialized_;
}

inline bool Intro::IsPaused()
{
	return paused_;
}
