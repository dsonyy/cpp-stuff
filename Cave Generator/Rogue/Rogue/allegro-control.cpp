#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include "allegro-control.h"

AllegroControl::AllegroControl()
{
	running_ = true;
	fps_counter_ = 0;
	Init();
}


AllegroControl::~AllegroControl()
{

}


void AllegroControl::Loop()
{
	bool running = true;
	bool redraw = true;

	while (running)
	{


		while (true)
		{
			ALLEGRO_EVENT current_event;

			al_wait_for_event(event_queue_, &current_event);
			if (current_event.type == ALLEGRO_EVENT_TIMER)
			{
				if (current_event.timer.source == logic_timer_)
				{
					++fps_counter_;
				}
				if (current_event.timer.source == display_timer_)
				{
					if (true)
					{
						Draw();
						redraw = false;
					}
				}
			}
			else if (al_event_queue_is_empty(event_queue_))
			{
				break;
			}
		}
	}
}

void AllegroControl::CatchEvent()
{
	al_wait_for_event(event_queue_, &current_event);
}

 AllegroControl::ExecuteEvent()
{
	if (current_event.type == ALLEGRO_EVENT_TIMER)
	{
		if (current_event.timer.source == logic_timer_)
		{
			++fps_counter_;
		}
		if (current_event.timer.source == display_timer_)
		{
			if (true)
			{
				Draw();
				redraw = false;
			}
		}
	}
	else if (al_event_queue_is_empty(event_queue_))
	{
		break;
	}
}

void AllegroControl::Draw()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_textf(basic_font_, al_map_rgb(255, 0, 0), 10, 10, NULL, "FPS: %i", fps_counter_);
	al_flip_display();
}

bool AllegroControl::Init()
{
	if (!al_init())
	{
		ShowError("Unable to initialize allegro");
		return false;
	}

	if (!al_init_image_addon())
	{
		ShowError("Unable to initialize image addon");
		return false;
	}
	
	if (!al_install_keyboard())
	{
		ShowError("Unable to install kayboard addon");
		return false;
	}


	display_ = al_create_display(640, 480);
	if (!display_)
	{
		ShowError("Unable to initialize display");
		return false;
	}

	logic_timer_ = al_create_timer(1.0 / 100.0);
	if (!logic_timer_)
	{
		ShowError("Unable to initialize logic timer");
		return false;
	}

	display_timer_ = al_create_timer(1.0 / 60.0);
	if (!display_timer_)
	{
		ShowError("Unable to initialize display timer");
		return false;
	}

	event_queue_ = al_create_event_queue();
	if (!event_queue_)
	{
		ShowError("Unable to initialize event queue");
		return false;
	}

	basic_font_ = al_create_builtin_font();

	al_register_event_source(event_queue_, al_get_display_event_source(display_));
	al_register_event_source(event_queue_, al_get_timer_event_source(logic_timer_));
	al_register_event_source(event_queue_, al_get_timer_event_source(display_timer_));

	al_start_timer(logic_timer_);
	al_start_timer(display_timer_);
}

void AllegroControl::ShowError(const char * text) const
{
	al_show_native_message_box(al_get_current_display(),
		"Game", "Fatal Error", text, NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void AllegroControl::Close()
{
	running_ = false;
}
