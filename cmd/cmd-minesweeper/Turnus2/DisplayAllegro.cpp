#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include "DisplayAllegro.h"

DisplayAllegro::DisplayAllegro()
{
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	display_ = al_create_display(400, 500);
	font_ = al_load_ttf_font("res/font/Bubblegum.ttf", 18, 0);

	bitmap[BLANK] = al_load_bitmap("res/img/blank.png");
	bitmap[UNKNOWN] = al_load_bitmap("res/img/unknown.png");


}


DisplayAllegro::~DisplayAllegro()
{
	
}


void DisplayAllegro::KillScreen(const Player * player, const Board * board)
{
	DrawBoard(player, board);

	al_draw_filled_rectangle(
		al_get_display_width(display_) / 2 - 100,
		al_get_display_height(display_) / 2 - 50,
		al_get_display_width(display_) / 2 + 100,
		al_get_display_height(display_) / 2 + 50,
		al_map_rgb(0, 0, 0));
}



void DisplayAllegro::DrawBoard(const Player * player, const Board * board)
{
	if (current_board_ != board)
	{
		al_resize_display(
			display_, 
			LEFT_OFFSET + board->GetSizeX() * al_get_bitmap_width(bitmap[BLANK]) + RIGHT_OFFSET,
			TOP_OFFSET + board->GetSizeY() * al_get_bitmap_height(bitmap[BLANK]) + BOTTOM_OFFSET
		);
	}

	al_clear_to_color(al_map_rgb(0, 0,127));

	for (int y = 0; y < board->GetSizeY(); y++)
	{
		for (int x = 0; x < board->GetSizeX(); x++)
		{
			DrawBlock({ y,x }, board);
		}
	}

	al_draw_rectangle(
		LEFT_OFFSET, 
		TOP_OFFSET, 
		LEFT_OFFSET + 1 + board->GetSizeX() * 22, 51 + board->GetSizeY() * 22, al_map_rgb(0, 0, 0), 1);


	al_flip_display();
}

void DisplayAllegro::DrawBlock(const Coord & pos, const Board * board)
{
	Coord a = GetBlockPos(pos, board);

	if (!board->GetBlock({ pos.x, pos.y }).clicked)
	{
		al_draw_bitmap(bitmap[UNKNOWN], a.x, a.y, 0);
	}
	else if (board->GetBlock({ pos.x, pos.y }).flag)
	{
		al_draw_bitmap(bitmap[BLANK], a.x, a.y, 0);
		al_draw_text(font_, al_map_rgb(255, 0, 0), a.x, a.y, 0, "/*");
	}
	if (board->GetBlock({ pos.x, pos.y }).number == Block::BOMB)
	{
		al_draw_bitmap(bitmap[BLANK], a.x, a.y, 0);
		al_draw_text(font_, al_map_rgb(0, 0, 0), a.x, a.y, 0, "X");
	}
	else if (board->GetBlock({ pos.x, pos.y }).number == Block::EMPTY)
	{
		al_draw_bitmap(bitmap[BLANK], a.x, a.y, 0);
	}
	else
	{
		al_draw_bitmap(bitmap[BLANK], a.x, a.y, 0);
		al_draw_textf(font_, al_map_rgb(0, 0, 255), a.x, a.y, 0, "%i", board->GetBlock({ pos.x, pos.y }).number);
	}

}

Coord DisplayAllegro::GetBlockPos(const Coord & pos, const Board * board) const
{
	if (board->ValidCoord(pos))
	{
		Coord a;
		a.x = LEFT_OFFSET + pos.x * al_get_bitmap_width(bitmap[BLANK]);
		a.y = TOP_OFFSET + pos.y * al_get_bitmap_height(bitmap[BLANK]);

		return a;
	}

	return { 0,0 };
}