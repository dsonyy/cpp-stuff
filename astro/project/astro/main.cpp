#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5\allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <cstdlib>
#include <time.h>
#include "global.h"
#include "Ship.h"
#include "Logic.h"


#include <iostream>
int main(int argc, char **argv)
{
	//=====================================================
	//	ALLEGRO VARIABLES
	//=====================================================

	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE * eventQueue = NULL;
	ALLEGRO_TIMER * timer = NULL;

	//=====================================================
	//	ALLEGRO INIT FUNCTIONS
	//=====================================================

	if (!al_init())
	{
		al_show_native_message_box(al_get_current_display(), "Game", "Fatal error:",
			"Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	display = al_create_display(WIDTH, HEIGHT);
	if (!display)
	{
		al_show_native_message_box(al_get_current_display(), "Game", "Fatal error:",
			"Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	eventQueue = al_create_event_queue();
	if (!eventQueue)
	{
		al_show_native_message_box(al_get_current_display(), "Game", "Fatal error:",
			"Failed to initialize event queue!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return -1;
	}

	timer = al_create_timer(1.0 / FRAME_PER_SEC);
	if (!timer)
	{
		al_show_native_message_box(al_get_current_display(), "Game", "Fatal error:",
		"Failed to initialize timer!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_event_queue(eventQueue);
		al_destroy_display(display);
		return -1;
	}

	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

	//=====================================================
	//	ADDON INSTALL
	//=====================================================

	al_init_image_addon();

	al_install_audio();
	al_init_acodec_addon();

	al_install_keyboard();

	//=====================================================
	//	EVENT SOURCES REGISTER
	//=====================================================

	//=====================================================
	//	GAME VARIABLES
	//=====================================================

	bool done = false;
	bool redraw = true;
	Logic gameLogic;

	//=====================================================
	//	MAIN GAME LOOP
	//=====================================================

	srand(time(NULL));

	ALLEGRO_EVENT_QUEUE * queue = al_create_event_queue();
	ALLEGRO_TIMER * logicTimer = al_create_timer(1.0 / LOGIC_PER_SEC);
	ALLEGRO_TIMER * displayTimer = al_create_timer(1.0 / FRAME_PER_SEC);
	ALLEGRO_TIMER * liveTimer = al_create_timer (1.0);


	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(logicTimer));
	al_register_event_source(queue, al_get_timer_event_source(displayTimer));
	al_register_event_source(queue, al_get_keyboard_event_source());

	al_start_timer(logicTimer);
	al_start_timer(displayTimer);



	al_start_timer(timer);
	/*
	while (!done)
	{	

		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		std::cout << gameLogic.getTime() << std::endl;

		if ( gameLogic.getTime() > 0)
		{
			if (!(al_get_timer_count(timer) % 60)) gameLogic.addTime(-1);

			if (redraw && al_is_event_queue_empty(queue))
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				gameLogic.draw();
				al_flip_display();

				redraw = false;
			}

			if (ev.type == ALLEGRO_EVENT_TIMER)
			{
				gameLogic.refresh();
				redraw = true;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_UP:
				case ALLEGRO_KEY_W:
					gameLogic.setKey(UP, true);
					break;
				case ALLEGRO_KEY_DOWN:
				case ALLEGRO_KEY_S:
					gameLogic.setKey(DOWN, true);
					break;
				case ALLEGRO_KEY_LEFT:
				case ALLEGRO_KEY_A:
					gameLogic.setKey(LEFT, true);
					break;
				case ALLEGRO_KEY_RIGHT:
				case ALLEGRO_KEY_D:
					gameLogic.setKey(RIGHT, true);
					break;
				case ALLEGRO_KEY_SPACE:
					gameLogic.setKey(SPACE, true);
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_UP:
				case ALLEGRO_KEY_W:
					gameLogic.setKey(UP, false);
					break;
				case ALLEGRO_KEY_DOWN:
				case ALLEGRO_KEY_S:
					gameLogic.setKey(DOWN, false);
					break;
				case ALLEGRO_KEY_LEFT:
				case ALLEGRO_KEY_A:
					gameLogic.setKey(LEFT, false);
					break;
				case ALLEGRO_KEY_RIGHT:
				case ALLEGRO_KEY_D:
					gameLogic.setKey(RIGHT, false);
					break;
				case ALLEGRO_KEY_SPACE:
					gameLogic.setKey(SPACE, false);
					break;
				}
			}
		}

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE ||
			ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			// TODO: saving score
			done = true;
		}

	}
	*/
	while (!done)
	{
		while (true)
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(queue, &ev);

			if		(ev.type == ALLEGRO_EVENT_KEY_DOWN || ev.type == ALLEGRO_EVENT_KEY_UP)
			{
				bool keyStatus;
				if (ev.type == ALLEGRO_EVENT_KEY_DOWN) keyStatus = true;
				else keyStatus = false;

				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_UP:
				case ALLEGRO_KEY_W:
					gameLogic.setKey(UP, keyStatus);
					break;
				case ALLEGRO_KEY_DOWN:
				case ALLEGRO_KEY_S:
					gameLogic.setKey(DOWN, keyStatus);
					break;
				case ALLEGRO_KEY_LEFT:
				case ALLEGRO_KEY_A:
					gameLogic.setKey(LEFT, keyStatus);
					break;
				case ALLEGRO_KEY_RIGHT:
				case ALLEGRO_KEY_D:
					gameLogic.setKey(RIGHT, keyStatus);
					break;
				case ALLEGRO_KEY_SPACE:
					gameLogic.setKey(SPACE, keyStatus);
					break;
				case ALLEGRO_KEY_Z:
					gameLogic.setKey(Z, keyStatus);
					break;
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_TIMER)
			{
				if (ev.timer.source == logicTimer)
				{
					if (gameLogic.getTime() > 0)
					{
						if (!(al_get_timer_count(logicTimer) % LOGIC_PER_SEC)) gameLogic.addTime(-1);
						gameLogic.refresh();
					}
				}
				else if (ev.timer.source == displayTimer)
				{
					redraw = true;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE ||
				ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				// TODO: saving score
				done = true;
			}

			if (al_is_event_queue_empty(queue)) break;
		}

		if (redraw)
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));
			gameLogic.draw();
			al_flip_display();

			redraw = false;
		}
	}

	
	al_destroy_timer(timer);
	al_destroy_event_queue(eventQueue);
	al_destroy_display(display);
	return 0;
}