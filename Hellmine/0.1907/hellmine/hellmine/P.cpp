#include "mine.h"

P::P(int hp)
{
	bag = new Bag("Bag on ores");
	this->hp = hp;
	key = 0;
}
P::P(M item, int hp)
{
	bag = new Bag("Bag on ores");
	this->hp = hp;
	bag->in(item);
	key = 0;
}
P::P(Bag backpack, int hp)
{
	bag = new Bag("Bag on ores");
	this->hp = hp;
	*bag = backpack;
	key = 0;
}

void P::in(string name, int number)
{
	bag->in(name, number);
}
void P::out(string name, int number, int * to)
{
	bag->out(name, number, to);
}
void P::out(string name, int * to)
{
	bag->out(name, to);
}

void P::iKey(int number)
{
	key += number;
}
void P::oKey(int number)
{
	if (key <= 0) cout << " You don't have enought keys.\n";
	else --key;
}

void P::inv()
{

}