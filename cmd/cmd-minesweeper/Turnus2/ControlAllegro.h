#pragma once

#include <allegro5\allegro.h>
#include <allegro5\events.h>
#include "Control.h"

class ControlAllegro
	: public Control
{
public:
	const double TimerFrequency = 1.0 / 30.0;
	const double EventTimeout = 0.1;

	ControlAllegro();
	~ControlAllegro();
	
//	// derived from Controler
//	virtual void Init();
//	virtual void EventLoop();
//	virtual bool IsRunning() { return running_; }
//
//	virtual void GetEvent();
//	virtual bool CheckCloseButton();
//
//	virtual Coord GetCursorPos();
//
//private:
//	bool running_;
//
//	ALLEGRO_TIMER * timer_;
//	ALLEGRO_EVENT_QUEUE * event_queue_;
};