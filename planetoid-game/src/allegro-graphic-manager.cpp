#include "error.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "allegro-graphic-manager.h"

AllegroGraphicManager::AllegroGraphicManager()
{

}

AllegroGraphicManager::~AllegroGraphicManager()
{

}

error AllegroGraphicManager::Init(int width, int heigth)
{
	al_init();
	
	al_init_primitives_addon();

	display_ = al_create_display(width, heigth);

	return error::EMPTY;
}

void AllegroGraphicManager::Cleanup()
{

}

error AllegroGraphicManager::Render(float interpolation)
{
	al_flip_display();
	return error::EMPTY;
}

void AllegroGraphicManager::FillColor(RGBAColor rgbacolor)
{
	al_clear_to_color(
		al_map_rgba(rgbacolor.r, rgbacolor.g, rgbacolor.b, rgbacolor.a));
}

void AllegroGraphicManager::DrawRectangle(const Rect & rect, RGBAColor rgbacolor)
{
	al_draw_filled_rectangle(
		rect.x,
		rect.y,
		rect.x + rect.w,
		rect.y + rect.h,
		al_map_rgba(rgbacolor.r, rgbacolor.g, rgbacolor.b, rgbacolor.a)
	);
}