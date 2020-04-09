#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define W 800
#define H 600

void draw_man(int x, int y);

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;

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

	al_init_primitives_addon();

	al_clear_to_color(al_map_rgb(127, 127, 255));

	float river[] = {W/7, H/2, W/7, H/4*3, W/7*2, H/4*3, W/4*3, H+25};

	for (int i = 0; i < W; ++i)
	{

		al_draw_filled_rectangle(0, 300, 800, 600, al_map_rgb(0,127,0));				// grass
		al_draw_filled_rectangle(500, 200, 700, 400, al_map_rgb(255,255,255));			// wall of house
		al_draw_filled_triangle(600, 100, 450, 200, 750, 200, al_map_rgb(255, 0, 0));	// roof
		al_draw_line(300, 400, 300, 350, al_map_rgb(127,0,0), 15);						// stump
		al_draw_filled_ellipse(300, 250, 50, 100, al_map_rgb(127,255,127));				// tree
		al_draw_spline(river, al_map_rgb(0, 0, 255), 50);								// river

		draw_man(i,400);

		al_flip_display();
		al_rest(0.01);
	}

	al_destroy_display(display);

	return 0;
}

void draw_man(int x, int y)
{
	al_draw_filled_rectangle(x,y,x+50,y+100, al_map_rgb(0,0,0));
}