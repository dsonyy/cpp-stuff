#include "mine.h"

Inv::Inv()
{
	key = 0;
	key_red = 0;
	key_blue = 0;

	Bag * bag = new Bag[Bag_max];
	bag_main = 0;
}
Inv::Inv(Bag b)
{
	key = 0;
	key_red = 0;
	key_blue = 0;

	Bag * bag = new Bag[Bag_max];
	bag_main = 0;
}

void Inv::in(int key, int red, int blue)
{
	this->key += key;
	key_red += red;
	key_blue += blue;
}

void Inv::in(Bag b)
{

}