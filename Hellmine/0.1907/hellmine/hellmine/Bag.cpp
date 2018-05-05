#include "mine.h"

Bag::Bag()
{
	const int Num0 = 19;
	const int Num1 = 4;

	string name0[Num0]
	{
		"Leaky",
		"Old",
		"Dirty",
		"Red",
		"Orange",

		"Yellow",
		"Green",
		"Blue",
		"Purple",
		"Black",

		"Gray",
		"White",
		"Dark",
		"Light",
		"Small",

		"Large",
		"Heavy",
		"Big",
		"Torn"
	};
	string name1[Num1]
	{
		"Bag",
		"Backpack",
		"Pouch",
		"Sack"
	};

	name = name0[random(0, Num0 - 1)] + " " + name1[random(0, Num1 - 1)];
	item.rand(25);
	if (item.isempty()) is_empty = true;
	else is_empty = false;
}
Bag::Bag(M item)
{
	const int Num0 = 19;
	const int Num1 = 4;

	string name0[Num0]
	{
		"Leaky",
		"Old",
		"Dirty",
		"Red",
		"Orange",

		"Yellow",
		"Green",
		"Blue",
		"Purple",
		"Black",

		"Gray",
		"White",
		"Dark",
		"Light",
		"Small",

		"Large",
		"Heavy",
		"Big",
		"Torn"
	};
	string name1[Num1]
	{
		"Bag",
		"Backpack",
		"Pouch",
		"Sack"
	};

	name = name0[random(0, Num0 - 1)] + " " + name1[random(0, Num1 - 1)];
	this->item = item;

	if (item.isempty()) is_empty = true;
	else is_empty = false;
}

void Bag::show(string name)
{
	int * n = type(name);
	cout << " In " << name << " are " << *n << "B of " << name << " \n";
}
void Bag::show()
{
	cout << "\n In " << name << " are:\n";

	cout << " COAL  IRON  HALI  COPP  STON\n ";
	cout.width(4); cout << right << item.coal << "  ";
	cout.width(4); cout << right << item.iron << "  ";
	cout.width(4); cout << right << item.hali << "  ";
	cout.width(4); cout << right << item.copp << "  ";
	cout.width(4); cout << right << item.ston << "\n\n";

	cout << " SAPP  EMER  RUBY  TOPA  LAPI\n ";
	cout.width(4); cout << right << item.sapp << "  ";
	cout.width(4); cout << right << item.emer << "  ";
	cout.width(4); cout << right << item.ruby << "  ";
	cout.width(4); cout << right << item.topa << "  ";
	cout.width(4); cout << right << item.lapi << "\n\n";

	cout << " GOLD  SILV  DIAM  LIFE  PHIL\n ";
	cout.width(4); cout << right << item.gold << "  ";
	cout.width(4); cout << right << item.silv << "  ";
	cout.width(4); cout << right << item.diam << "  ";
	cout.width(4); cout << right << item.life << "  ";
	cout.width(4); cout << right << item.phil << "\n\n";
}

void Bag::in(M source)
{
	item.coal += (source.coal);
	item.iron += (source.iron);
	item.hali += (source.hali);
	item.copp += (source.copp);
	item.ston += (source.ston);

	item.sapp += (source.sapp);
	item.emer += (source.emer);
	item.ruby += (source.ruby);
	item.topa += (source.topa);
	item.lapi += (source.lapi);

	item.gold += (source.gold);
	item.silv += (source.silv);
	item.diam += (source.diam);
	item.life += (source.life);
	item.phil += (source.phil);

}
void Bag::in(string name, int number)
{
	int * n = type(name);
	*n += number;
}

void Bag::out(M * to)
{
	(to->coal) += item.coal; item.coal = 0;
	(to->iron) += item.iron; item.iron = 0;
	(to->hali) += item.hali; item.hali = 0;
	(to->copp) += item.copp; item.copp = 0;
	(to->ston) += item.ston; item.ston = 0;

	(to->sapp) += item.sapp; item.sapp = 0;
	(to->emer) += item.emer; item.emer = 0;
	(to->ruby) += item.ruby; item.ruby = 0;
	(to->topa) += item.topa; item.topa = 0;
	(to->lapi) += item.lapi; item.lapi = 0;

	(to->gold) += item.gold; item.gold = 0;
	(to->silv) += item.silv; item.silv = 0;
	(to->diam) += item.diam; item.diam = 0;
	(to->life) += item.life; item.life = 0;
	(to->phil) += item.phil; item.phil = 0;
}
void Bag::out(string name, int number, int * to)
{
	int * n = type(name);

	if (number > *n && *n <= 0) cout << " There are too few items!\n";
	else
	{
		*n -= number;
		*to += number;
	}
}
void Bag::out(string name, int * to)
{
	int * n = type(name);

	if ( *n <= 0 ) cout << " There are too few items!\n";
	else
	{
		*to += *n;
		*n = 0;
	}
}

int * Bag::type(string name)
{
	if (name == "coal") return &item.coal;
	else if (name == "iron") return &item.iron;
	else if (name == "halite") return &item.hali;
	else if (name == "copper") return &item.copp;
	else if (name == "stone") return &item.ston;
	else if (name == "sapphire") return &item.sapp;
	else if (name == "emerald") return &item.emer;
	else if (name == "ruby") return &item.ruby;
	else if (name == "topaz") return &item.topa;
	else if (name == "lapis lazuli") return &item.lapi;
	else if (name == "gold") return &item.gold;
	else if (name == "silver") return &item.silv;
	else if (name == "diamond") return &item.diam;
	else if (name == "life crystal") return &item.life;
	else if (name == "philosopher's stone") return &item.phil;

}