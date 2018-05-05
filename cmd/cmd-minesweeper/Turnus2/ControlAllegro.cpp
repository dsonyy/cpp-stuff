#include "ControlAllegro.h"

ControlAllegro::ControlAllegro()
{
	//running_ = true;
}

ControlAllegro::~ControlAllegro()
{
}

//}
//
//void ControlAllegro::Init()
//{
//	al_install_mouse();
//
//	event_queue_ = al_create_event_queue();
//	timer_		 = al_create_timer(TimerFrequency);
//
//	al_register_event_source(event_queue_, al_get_display_event_source(al_get_current_display()));
//	al_register_event_source(event_queue_, al_get_mouse_event_source());
//}
//
//void ControlAllegro::EventLoop()
//{
//	ALLEGRO_EVENT ev;
//
//	while (!al_is_event_queue_empty(event_queue_))
//	{
//		switch (ev.type)
//		{
//		case ALLEGRO_EVENT_DISPLAY_CLOSE:
//			running_ = false;
//			break;
//		}
//	}
//}
//
//void ControlAllegro::GetEvent()
//{
//	//_wait_for_event_timed(event_queue_, &current_event_, TimerFrequency);
//
//
//}
//
//bool ControlAllegro::CheckCloseButton()
//{
//	if (current_event_.type = ALLEGRO_EVENT_DISPLAY_CLOSE)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//Coord ControlAllegro::GetCursorPos()
//{
//	Coord a;
//	al_get_mouse_cursor_position(&a.x, &a.y);
//
//	return a;
//}