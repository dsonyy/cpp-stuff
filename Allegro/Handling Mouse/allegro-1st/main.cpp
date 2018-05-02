#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#define W 800
#define H 600

#define FPS 60

enum KEY {UP, DOWN, LEFT, RIGHT};


int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_FONT *font = NULL;


	if (!al_init())
	{
		fprintf(stderr, "o shit, failed to initialize allegro!");
		return -1;
	}
	
	display = al_create_display(W, H);
	if (!display)
	{
		fprintf(stderr, "o shit, failed to initialize display!");
		return -1;
	}

	event_queue = al_create_event_queue();
	if (!event_queue)
	{
		fprintf(stderr, "o shit, failed to initialize queue!");
		return -1;
	}
	
	timer = al_create_timer(1.0 / FPS);

	font = al_create_builtin_font();

	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	bool done = false;
	bool draw = true;
	bool redraw = true;

	int posX = W/2;
	int posY = H/2;
	int count = 0;

	bool keys[4] = {false, false, false, false};

	al_hide_mouse_cursor(display);
	al_start_timer(timer);

	while (!done)
	{
		count++;

		if (redraw && al_is_event_queue_empty(event_queue))
		{
			if (draw)
				al_draw_filled_rectangle(posX, posY, posX + 50, posY + 50, al_map_rgb(255, 0, 0));

			al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, 0, "Allegro 1st");
			al_draw_textf(font, al_map_rgb(255, 255, 255), 10, 25, 0, "Total FPS: %i", count);
			al_draw_text(font, al_map_rgb(255, 255, 255), 10, 40, 0, "Damn dat font is pretty good!");

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}


		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
			}
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			done = true;
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			posX = ev.mouse.x - 25;
			posY = ev.mouse.y - 25;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 2)
				done = true;
			else if (ev.mouse.button & 1)
				draw = !draw;
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
				posY -= keys[UP] * 10;
				posY += keys[DOWN] * 10;
				posX -= keys[LEFT] * 10;
				posX += keys[RIGHT] * 10;

				redraw = true;
		}


	}

	al_destroy_display(display);
	return 0;
}
