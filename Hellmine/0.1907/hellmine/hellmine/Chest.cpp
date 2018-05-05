#include "mine.h"

Chest::Chest()
{
	rename();
	items.rand(25);

	is_opened = false;
	is_locked = prob(33);
	is_empty = items.isempty();
}
Chest::Chest(bool is_locked)
{
	rename();
	items.rand(25);

	is_opened = false;
	this->is_locked = is_locked;
	is_empty = items.isempty();
}
Chest::Chest(M stuff)
{
	rename();
	items = stuff;

	is_opened = false;
	is_locked = prob(33);
	is_empty = items.isempty();
}
Chest::Chest(bool is_locked, M stuff)
{
	rename();
	items = stuff;

	is_opened = false;
	this->is_locked = is_locked;
	is_empty = items.isempty();
}

void Chest::show()
{
	if (is_empty == false)
	{
		cout << "\n You open the chest. Inside you find:\n";
		if (items.coal > 0) cout << " - some of COAL\n";
		if (items.iron > 0) cout << " - ore of IRON\n";
		if (items.hali > 0)	cout << " - ore of HALITE (rock salt)\n";
		if (items.copp > 0)	cout << " - ore of COPPER\n";
		if (items.sapp > 0)
		{
			cout << " - ore of ";
			LBLUE cout << "SAPPHIRE\n"; NORMAL		 
		}
		if (items.emer > 0)
		{
			cout << " - ore of ";
			LGREEN cout << "EMERALD\n"; NORMAL
		}
		if (items.ruby > 0)
		{
			cout << " - ore of ";
			LRED cout << "RUBY\n"; NORMAL
		}
		if (items.topa > 0)
		{
			cout << " - ore of ";
			YELLOW cout << "TOPAZ\n"; NORMAL
		}
		if (items.lapi > 0)
		{
			cout << " - ore of ";
			LBLUE cout << "LAPIS LAZULI\n"; NORMAL
		}

		if (items.gold > 0)
		{
			cout << " - ore of ";
			LYELLOW cout << "GOLD\n"; NORMAL
		}
		if (items.silv > 0)
		{
			cout << " - ore of ";
			LNORMAL cout << "SILVER\n"; NORMAL				 
		}
		if (items.diam > 0)
		{
			cout << " - ore of ";
			LCYAN cout << "DIAMOND\n"; NORMAL
		}
		if (items.life > 0)
		{
			cout << " - ore of ";
			LRED cout << "LIFE CRYSTAL\n"; NORMAL
		}
		if (items.phil > 0)
		{
			cout << " - ore of ";
			LPINK cout << "PHILOSOPHER'S STONE\n"; NORMAL
		}
	}
	else cout << " This chest is empty.\n";
}
void Chest::in(string name, int number)
{
	int * p = type(name);
	*p += number;
}
void Chest::out(M * to)
{
	(to->coal) += items.coal; items.coal = 0;
	(to->iron) += items.iron; items.iron = 0;
	(to->hali) += items.hali; items.hali = 0;
	(to->copp) += items.copp; items.copp = 0;
	(to->ston) += items.ston; items.ston = 0;

	(to->sapp) += items.sapp; items.sapp = 0;
	(to->emer) += items.emer; items.emer = 0;
	(to->ruby) += items.ruby; items.ruby = 0;
	(to->topa) += items.topa; items.topa = 0;
	(to->lapi) += items.lapi; items.lapi = 0;

	(to->gold) += items.gold; items.gold = 0;
	(to->silv) += items.silv; items.silv = 0;
	(to->diam) += items.diam; items.diam = 0;
	(to->life) += items.life; items.life = 0;
	(to->phil) += items.phil; items.phil = 0;
}
void Chest::out(string name, int number, int * to)
{
	int * p = type(name);

	if (number > *p && *p <= 0) cout << " There are too few items!\n";
	else
	{
		*p -= number;
		*to += number;
	}
}
void Chest::out(string name, int * to)
{
	int * n = type(name);

	if (*n <= 0) cout << " There are too few items!\n";
	else
	{
		*to += *n;
		*n = 0;
	}
}

void Chest::rename()
{
	const int Num0 = 13;
	const int Num1 = 16;

	string name0[Num0]
	{
		"Lost",
		"Dirty",
		"Big",
		"Small",
		"Wooden",

		"Large",
		"Long",
		"Heavy",
		"Iron",
		"Black",

		"Dark",
		"Red",
		"Brown"
	};
	string name1[Num1]
	{
		"Crate",
		"Chest",
		"Case",
		"Coffer",
		"Container"
	};

	name = name0[random(0, Num0 - 1)] + " " + name1[random(0, Num1 - 1)];
}
void Chest::rename(string name)
{
	this->name = name;
}

int * Chest::type(string name)
{
	if (name == "coal") return &items.coal;
	else if (name == "iron") return &items.iron;
	else if (name == "halite") return &items.hali;
	else if (name == "copper") return &items.copp;
	else if (name == "stone") return &items.ston;
	else if (name == "sapphire") return &items.sapp;
	else if (name == "emerald") return &items.emer;
	else if (name == "ruby") return &items.ruby;
	else if (name == "topaz") return &items.topa;
	else if (name == "lapis lazuli") return &items.lapi;
	else if (name == "gold") return &items.gold;
	else if (name == "silver") return &items.silv;
	else if (name == "diamond") return &items.diam;
	else if (name == "life crystal") return &items.life;
	else if (name == "philosopher's stone") return &items.phil;

}