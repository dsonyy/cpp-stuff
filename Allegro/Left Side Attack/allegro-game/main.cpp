#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "objects.h"

const int WIDTH = 800;
const int HEIGHT = 400;   

const int BULLETS_NUM = 3;
const int COMETS_NUM = 10;
const int FPS = 120;
enum KEY { UP, DOWN, LEFT, RIGHT, SPACE};
bool key[5] = { false, false, false, false, false};

// prototypes
void initShip(SpaceShip &);
void drawShip(SpaceShip &);
void moveShip(SpaceShip &, KEY);

void initBullet(Bullet [], int);
void drawBullet(Bullet [], int);
void fireBullet(Bullet [], int, SpaceShip &);
void updateBullet(Bullet [], int);

void initComet(Comet [], int);
void drawComet(Comet [], int);
void startComet(Comet [], int);
void updateComet(Comet [], int);

void collideBullet(Bullet [], int, Comet [], int);
void collideComet(Comet [], int, SpaceShip &);


int main()
{
	// primitive variables
	bool done = false;
	bool redraw = true;

	// object variables
	SpaceShip ship;
	Bullet bullets[BULLETS_NUM];
	Comet comets[COMETS_NUM];

	// allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;


	// initialization functions
	if (!al_init())
		return -1;

	display = al_create_display(WIDTH, HEIGHT);
	if (!display)
		return -1;

	event_queue = al_create_event_queue();
	if (!event_queue)
		return -1;

	timer = al_create_timer(1.0 / FPS);
	if (!timer)
		return -1;


	al_init_primitives_addon();
	al_install_keyboard();

	srand(time(NULL));
	initShip(ship);
	initBullet(bullets, BULLETS_NUM);
	initComet(comets, COMETS_NUM);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_start_timer(timer);
	// main game loop
	while (!done)
	{
		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
			drawShip(ship);
			drawBullet(bullets, BULLETS_NUM);
			drawComet(comets, COMETS_NUM);

			al_flip_display();
		}

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);


		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			if (key[UP]) moveShip(ship, UP);
			if (key[DOWN]) moveShip(ship, DOWN);
			//if (key[LEFT]) moveShip(ship, LEFT);
			//if (key[RIGHT]) moveShip(ship, RIGHT);

			updateBullet(bullets, BULLETS_NUM);
			startComet(comets, COMETS_NUM);
			updateComet(comets, COMETS_NUM);
			collideBullet(bullets, BULLETS_NUM, comets, COMETS_NUM);
			collideComet(comets, COMETS_NUM, ship);

			if (ship.lives == 0) done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				key[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				key[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[RIGHT] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				key[SPACE] = true;
				fireBullet(bullets, BULLETS_NUM, ship);
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				key[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				key[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				key[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[RIGHT] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				key[SPACE] = false;
				break;
			}
		}
	}

	al_destroy_display(display);
	return 0;
}

void initShip(SpaceShip & ship)
{
	ship.x = 50;
	ship.y = HEIGHT / 2;
	ship.ID = PLAYER;
	ship.lives = 1;
	ship.speed = 2;
	ship.boundx = 6;
	ship.boundy = 7;
	ship.score = 0;
}

void drawShip(SpaceShip & ship)
{
	al_draw_filled_triangle(ship.x - 15, ship.y - 15, ship.x + 15, ship.y, ship.x - 15, ship.y + 15, al_map_rgb(0,255,0));
	al_draw_filled_triangle(ship.x - 15, ship.y - 15, ship.x + 5, ship.y, ship.x - 15, ship.y + 15, al_map_rgb(0, 0, 0));
}

void moveShip(SpaceShip & ship, KEY dir)
{
	if		(dir == UP)		ship.y -= ship.speed;
	else if (dir == DOWN)	ship.y += ship.speed;
	else if (dir == LEFT)	ship.x -= ship.speed;
	else if (dir == RIGHT)	ship.x += ship.speed;

	if		(ship.y < 0)		ship.y = 0;
	else if (ship.y > HEIGHT)	ship.y = HEIGHT;
	else if (ship.x < 0)		ship.x = 0;
	else if (ship.x > WIDTH)	ship.x = WIDTH;
}	

void initBullet(Bullet bullet[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		bullet[i].ID = BULLET;
		bullet[i].speed = 10;
		bullet[i].live = false;
	}
}

void drawBullet(Bullet bullet[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (bullet[i].live)
			al_draw_line(bullet[i].x, bullet[i].y, bullet[i].x + 10, bullet[i].y, al_map_rgb(255, 0, 0), 2);
	}
}

void fireBullet(Bullet bullet[], int size, SpaceShip & ship)
{
	for (int i = 0; i < size; ++i)
	{
		if (!bullet[i].live)
		{
			bullet[i].x = ship.x + 17;
			bullet[i].y = ship.y;
			bullet[i].live = true;
			break;
		}
	}
}

void updateBullet(Bullet bullet[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (bullet[i].live)
		{
			bullet[i].x += bullet[i].speed;
			if (bullet[i].x > WIDTH)
				bullet[i].live = false;
		}
	}
}


void initComet(Comet comet[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		comet[i].ID = ENEMY;
		comet[i].live = false;
		comet[i].speed = 2;
		comet[i].boundx = 18;
		comet[i].boundy = 18;
	}
}

void drawComet(Comet comet[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (comet[i].live)
		{
			al_draw_filled_triangle(comet[i].x + 15, comet[i].y + 15, comet[i].x - 15, comet[i].y, comet[i].x + 15, comet[i].y - 15, al_map_rgb(255, 255, 255));
			al_draw_filled_triangle(comet[i].x + 15, comet[i].y + 15, comet[i].x - 5, comet[i].y, comet[i].x + 15, comet[i].y - 15, al_map_rgb(0, 0, 0));
		}
	}
}
void startComet(Comet comet[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (!comet[i].live)
		{
			if (rand() % 1000 == 0)
			{
				comet[i].live = true;
				comet[i].x = WIDTH;
				comet[i].y = 30 + rand() % (HEIGHT - 60);
				break;
			}
		}
	}
}
void updateComet(Comet comet[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (comet[i].live)
		{
			comet[i].x -= comet[i].speed;
		}
	}
}

void collideBullet(Bullet bullet[], int bSize, Comet comet[], int cSize)
{ 
	for (int i = 0; i < bSize; ++i)
	{
		if (bullet[i].live)
		{
			for (int j = 0; j < cSize; j++)
			{
				if (comet[j].live)
				{
					if (bullet[i].x > (comet[j].x - comet[j].boundx) &&
						bullet[i].x < (comet[j].x + comet[j].boundx) &&
						bullet[i].y > (comet[j].y - comet[j].boundy) &&
						bullet[i].y < (comet[j].y + comet[j].boundy))
					{
						bullet[i].live = false;
						comet[j].live = false;
					}

				}
			}
		}
	}
}

void collideComet(Comet comet[], int cSize, SpaceShip & ship)
{
	for (int i = 0; i < cSize; ++i)
	{
		if (comet[i].live)
		{
			if (comet[i].x - comet[i].boundx < ship.x + ship.boundx &&
				comet[i].x + comet[i].boundx > ship.x - ship.boundx &&
				comet[i].y - comet[i].boundy < ship.y + ship.boundy &&
				comet[i].y + comet[i].boundy > ship.y - ship.boundy)
			{
				ship.lives--;
				comet[i].live = false;
			}
			else if (comet[i].x < 0)
			{
				comet[i].live = false;
				ship.lives--;
			}		
		}
	}
}