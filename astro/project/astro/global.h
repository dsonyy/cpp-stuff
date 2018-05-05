#ifndef _H_GLOBAL
#define _H_GLOBAL

//=====================================================
//	MISCELLANOUS
//=====================================================

const int WIDTH = 1000;
const int HEIGHT = 500;
const int USED_KEYS = 5;
const int USED_COLORS = 3;

const int FRAME_PER_SEC = 60;
const int LOGIC_PER_SEC = 120;

const int GAME_TIME = 60;
const int TIME_BONUS = 2;

enum COLOR { PURPLE, BLUE, GREEN };
enum KEY { UP, DOWN, LEFT, RIGHT, SPACE, Z};
enum SIZE { SMALL, MEDIUM, BIG};

const float ROCK_ALPHA = 1.0;
const float ROCK_ALPHA2 = 0.25;

//=====================================================
// COLORS
//=====================================================

const ALLEGRO_COLOR GAME_COLOR[USED_COLORS] = 
{
	al_map_rgba_f(1.0 * ROCK_ALPHA, 0 * ROCK_ALPHA, 0 * ROCK_ALPHA, ROCK_ALPHA),
	al_map_rgba_f(0 * ROCK_ALPHA, 1.0 * ROCK_ALPHA, 0 * ROCK_ALPHA, ROCK_ALPHA),
	al_map_rgba_f(0 * ROCK_ALPHA, 0 * ROCK_ALPHA, 1.0 * ROCK_ALPHA, ROCK_ALPHA),
};

const ALLEGRO_COLOR GAME_COLOR2[USED_COLORS] =
{
	al_map_rgba_f(1.0 * ROCK_ALPHA2, 0.1 * ROCK_ALPHA2, 0.1 * ROCK_ALPHA2, ROCK_ALPHA2),
	al_map_rgba_f(0.1 * ROCK_ALPHA2, 1.0 * ROCK_ALPHA2, 0.1 * ROCK_ALPHA2, ROCK_ALPHA2),
	al_map_rgba_f(0.1 * ROCK_ALPHA2, 0.1 * ROCK_ALPHA2, 1.0 * ROCK_ALPHA2, ROCK_ALPHA2),
};

//=====================================================
//	PLAYERS
//=====================================================

const int MAX_PLAYERS = 1;

const int PLAYER_LEFT_BOUND = 600;
const int PLAYER_RIGHT_BOUND = 990;

const int PLAYER_SPAWN_X = 700;
const int PLAYER_SPAWN_Y = 234;

const int PLAYER_SPEED = 1;
const int PLAYER_BOOST_SPEED = 2;


//=====================================================
//	ROCKS
//=====================================================

const int MAX_ROCKS_IN_ONE_COLOR = 3;
const int MAX_ROCKS = MAX_ROCKS_IN_ONE_COLOR * USED_COLORS;

const int ROCKS_LEFT_BOUND = 100;
const int ROCKS_RIGHT_BOUND = 500;

const int USED_ROCK_SIZE = 3;
const int USED_ROCK_TYPES = 5;

const int MAX_ROCK_SPEED = 150;

const int MAX_DUST = 3;

//=====================================================
//	BULLET
//=====================================================

const int MAX_BULLET = 1;
const int BULLET_SPEED = 10;

//=====================================================
//	POINTS
//=====================================================

const int POINTS_HIT_0 = 30;
const int POINTS_HIT_1 = 20;
const int POINTS_HIT_2 = 10;

#endif
