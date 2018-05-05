#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>


#include "Board.h"
#include "Player.h"
#include "Display.h"

class DisplayAllegro
	: public Display
{
public:
	enum Sprite {
		BLANK,
		UNKNOWN,
		SPRITES_NUMBER
	};

	enum { 
		LEFT_OFFSET = 10, 
		RIGHT_OFFSET = 10,
		TOP_OFFSET = 50,
		BOTTOM_OFFSET = 10
	};

	DisplayAllegro();
	~DisplayAllegro();

	// derived from Display
	virtual void DrawBoard(const Player * player, const Board * board);
	virtual void KillScreen(const Player * player, const Board * board);

	Coord GetBlockPos(const Coord & pos, const Board * board) const;
	
	void DrawBlock(const Coord & pos, const Board * board);

private:

	ALLEGRO_FONT * font_;
	ALLEGRO_DISPLAY * display_;
	ALLEGRO_BITMAP * bitmap[SPRITES_NUMBER];

	const Board * current_board_;
};