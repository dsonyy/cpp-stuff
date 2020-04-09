#include <iostream>
#include <string>
#include <random>
#include <windows.h>

// colors macros
#define RED SetConsoleTextAttribute(hOut, FOREGROUND_RED);
#define GREEN SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
#define BLUE SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);

#define LRED SetConsoleTextAttribute(hOut, FOREGROUND_RED + FOREGROUND_INTENSITY);
#define LGREEN SetConsoleTextAttribute(hOut, FOREGROUND_GREEN + FOREGROUND_INTENSITY);
#define LBLUE SetConsoleTextAttribute(hOut, FOREGROUND_BLUE + FOREGROUND_INTENSITY);

#define YELLOW SetConsoleTextAttribute(hOut, FOREGROUND_RED + FOREGROUND_GREEN);
#define PINK SetConsoleTextAttribute(hOut, FOREGROUND_BLUE + FOREGROUND_RED);
#define CYAN SetConsoleTextAttribute(hOut, FOREGROUND_BLUE + FOREGROUND_GREEN);

#define LYELLOW SetConsoleTextAttribute(hOut, FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_INTENSITY);
#define LPINK SetConsoleTextAttribute(hOut, FOREGROUND_BLUE + FOREGROUND_RED + FOREGROUND_INTENSITY);
#define LCYAN SetConsoleTextAttribute(hOut, FOREGROUND_BLUE + FOREGROUND_GREEN + FOREGROUND_INTENSITY);

#define NORMAL SetConsoleTextAttribute(hOut, FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_BLUE);
#define LNORMAL SetConsoleTextAttribute(hOut, FOREGROUND_RED + FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_INTENSITY);

using namespace std;

// WinAPI - add colors and other shit
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

// using for random
mt19937 gen(random_device{}());

// places name table
string t_name[][11] = { { "Donut","Ice Cream","Cookie", "Coffee", "Milky", "Lost", "Forgotten", "Rainbow", "Secret", "Mysterious", "Nightmare" },
						{ "Underground","Shaft","Cave","Tunnel", "Mine", "Passage", "Dungeon", "Room", "Place", "Abyss", "Cellar" } };

// all using ores
struct usefull_stuff
{
	int broken_pickaxe;
	int talisman_of_unluck;
	int destroyed_teleporter;
	int chaingun_without_ammo;
	int late_watch;
	int old_socks;
	int garden_gnome;
	int tale_book;
	int phone_without_battery;
	int can_of_spam;
	int lost_tomato;
	int dishwasher;
};
class M
{
	// the ores drop probability
	int COAL = 40;
	int IRON = 35;
	int COPP = 25;
	int HALI = 25;
	int STON = 70; // while diging

	int TOPA = 10;
	int EMER = 7;
	int SAPP = -7;
	int LAPI = -18;
	int RUBY = -22;

	int SILV = 7;
	int LIFE = 7;
	int GOLD = 3;
	int PHIL = 3;
	int DIAM = 1;

public:
	int coal, iron, hali, copp, ston; // common
	int sapp, emer, ruby, topa, lapi; // gems
	int gold, silv, diam, life, phil; // other

	M(int=0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
	
	// random ores number
	void rand(int);
};
class Chest
{
public:
	bool is_opened;
	bool is_locked;
	bool is_empty;
	M items;

	Chest(bool);
	void open(void);
	void take();
	void run(void);
};
class Npc
{
	bool need;
	int what_need; // 0-coal 1-iron 2-hali 3-copp 4-stone
	int how_much;

	string des;
	string sdes;

	string name0;
	string name1;

	string p_name;
	
public:
	Npc();
	void hi(void);
	void speak(void);
	void problem(void);
	void thank(void);
	void run(void);
	void proverb(void);
};
class Room
{
	int skill_lev;
	M m;
	Chest * ch;
	Npc * npc;

public:
	Room(int);
	Room(int, M);
	~Room();
	void show(void);
	void mine(string);
	string run(void);
private:
	void dig(string ore, int & number, int * miner); // ore type, ore bytes, player ores
};
class Tunnel
{
	string name;
	int skill_lev;
	int r_num;
	int pos;
	Room ** room;

	int coal, iron, hali, copp;
	int sapp, emer, ruby, topa, lapi;

public:
	Tunnel(int, int);
	void show(void);
	void run();
	~Tunnel(void);
};

// player info
int p_hp = 999;
int p_coal = 0,
p_iron = 0,
p_hali = 0,
p_copp = 0,
p_ston = 0,

p_sapp = 0,
p_emer = 0,
p_ruby = 0,
p_topa = 0,
p_lapi = 0,

p_gold = 0,
p_silv = 0,
p_diam = 0,
p_life = 0,
p_phil = 0;

void inv(void);			// show the invetory
void cmds(string);		// check the given command
bool prob(int);			// random a number of specified probability
int random(int, int);	// random a number of specified range

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	Tunnel x{ 0,10 };
	x.run();

	return 0;
}

Room::Room(int skill_lev)
{
	if (skill_lev > 25 || skill_lev < 0) this->skill_lev = 25;
	else this->skill_lev = skill_lev;
	m.rand(skill_lev);

	if (prob(10)) ch = new Chest(prob(25));
	else ch = 0;

	if (prob(10)) npc = new Npc;
	else npc = 0;
}
Room::Room(int skill_lev, M m)
{
	this->m = m;
	Room::Room(skill_lev);
}
Room::~Room()
{
	delete ch;
	delete npc;
}
void Room::show()
{
	// cout << " Znajdzujesz sie w dlugim, ciemnym pomieszczeniu.\n W oddali slyszysz niepokojace dzwieki.\n Ogarnia cie strach...\n\n";
	bool isempty = true;

	cout << "\n You are in the full of darkness room.\n The cold walls and ceiling make a sound\n like they were immediately collapse.\n You're terrified but You can't turn back now.\n";
	
	if (npc != 0)
	{
		cout << "\n At the end of tunnel you see small strange\n creature diging stone.\n";
	}
	cout << "\n Things in your area:\n";

	if (m.coal > 0)
	{ 
		cout << " - ore of COAL\n";
		isempty = false;
	}
	if (m.iron > 0)
	{
		cout << " - ore of IRON\n";
		isempty = false;
	}
	if (m.hali > 0)
	{
		cout << " - ore of HALITE (rock salt)\n";
		isempty = false;
	}
	if (m.copp > 0)
	{
		cout << " - ore of COPPER\n";
		isempty = false;
	}
	if (m.sapp > 0)
	{
		cout << " - ore of ";
		LBLUE cout << "SAPPHIRE\n"; NORMAL
		isempty = false;
	}
	if (m.emer > 0)
	{
		cout << " - ore of ";
		LGREEN cout << "EMERALD\n"; NORMAL
			isempty = false;
	}
	if (m.ruby > 0)
	{
		cout << " - ore of ";
		LRED cout << "RUBY\n"; NORMAL
			isempty = false;
	}
	if (m.topa > 0)
	{
		cout << " - ore of ";
		YELLOW cout << "TOPAZ\n"; NORMAL
			isempty = false;
	}
	if (m.lapi > 0)
	{
		cout << " - ore of ";
		LBLUE cout << "LAPIS LAZULI\n"; NORMAL
			isempty = false;
	}

	if (m.gold > 0)
	{
		cout << " - ore of ";
		LYELLOW cout << "GOLD\n"; NORMAL
			isempty = false;
	}
	if (m.silv > 0)
	{
		cout << " - ore of ";
		LNORMAL cout << "SILVER\n"; NORMAL
			isempty = false;
	}
	if (m.diam > 0)
	{
		cout << " - ore of ";
		LCYAN cout << "DIAMOND\n"; NORMAL
			isempty = false;
	}
	if (m.life > 0)
	{
		cout << " - ore of ";
		LRED cout << "LIFE CRYSTAL\n"; NORMAL
			isempty = false;
	}
	if (m.phil > 0)
	{
		cout << " - ore of ";
		LPINK cout << "PHILOSOPHER'S STONE\n"; NORMAL
			isempty = false;
	}
	if (ch != 0 && ch->is_locked == true) // chest
	{
		cout << " - locked CHEST\n";
		isempty = false;
	}
	else if (ch != 0 && ch->is_empty == true)
	{
		cout << " - empty CHEST\n";
		isempty = false;
	}
	else if (ch != 0)
	{
		cout << " - CHEST\n";
		isempty = false;
	}
	if (isempty == true) cout << " - nothing special\n";
	
}
void Room::mine(string ore)
{
	if (ore == "coal" && m.coal > 0) dig(ore, m.coal, &p_coal);
	else if (ore == "iron" && m.iron > 0) dig(ore, m.iron, &p_iron);
	else if (ore == "halite" && m.hali > 0) dig(ore, m.hali, &p_hali);
	else if (ore == "copper" && m.copp > 0) dig(ore, m.copp, &p_copp);

	else if (ore == "sapphire" && m.sapp > 0) dig(ore, m.sapp, &p_sapp);
	else if (ore == "emerald" && m.emer > 0) dig(ore, m.emer, &p_emer);
	else if (ore == "ruby" && m.ruby > 0) dig(ore, m.ruby, &p_ruby);
	else if (ore == "topaz" && m.topa > 0) dig(ore, m.topa, &p_topa);
	else if (ore == "lapis" && m.lapi > 0) dig(ore, m.lapi, &p_lapi);

	else if (ore == "gold" && m.gold > 0) dig(ore, m.gold, &p_gold);
	else if (ore == "silver" && m.silv > 0) dig(ore, m.silv, &p_silv);
	else if (ore == "diamond" && m.diam > 0) dig(ore, m.diam, &p_diam);
	else if (ore == "life" && m.life > 0) dig(ore, m.life, &p_life);
	else if (ore == "phil" && m.phil > 0) dig(ore, m.phil, &p_phil);

	else cout << " Oops... There are no such ore to mine.\n";

}
void Room::dig(string ore, int & number, int * miner)
{
	int snumber = number;
	int stone = 0;
	if (number > 1)
	{
		cout << " You see " << number << " bytes of " << ore << ".\n";
		while (number > 0)
		{
			string cmd;
			cout << " ";
			getline(cin, cmd);

			if (cmd == "d" || cmd == "dig")
			{
				cout << " DIG DIG DIG!\n";
				--number; ++(*miner);
				stone += rand() % 3;
			}
			else cmds(cmd);
		}
	}
	else
	{
		cout << " DIG DIG DIG!\n";
		--number; ++(*miner);
		stone += rand() % 3;
	}
	p_ston += stone;

	cout << " " << ore << " = " << snumber << endl;
	cout << " stone = " << stone << endl;

}
string Room::run()
{
	show();

	string cmd;
	cout << " ";
	getline(cin, cmd);
	 
	while (cin.good() && cmd != "go" && cmd != "g" && cmd != "back" && cmd != "now" && cmd != "n" && cmd != "b" && cmd != "quit" )
	{
		if ((cmd.length() == 1 && cmd == "m") || (cmd.length() == 4 && cmd == "mine")) cout << " Mine... but what?\n";
		else if (cmd.substr(0, 4) == "mine") mine(cmd.substr(5));
		else if (cmd.substr(0, 1) == "m") mine(cmd.substr(2));

		else if ((cmd.length() == 4 && cmd == "open") || (cmd.length() == 1 && cmd == "o")) cout << " Open <what>\n";
		else if (cmd == "open chest" && ch != 0) ch->run();
		else if (cmd == "open chest" && ch == 0) cout << " There are no any chest.\n";
		else if (cmd == "tell" && npc != 0) npc->run();
		else cmds(cmd);

		cout << " ";
		getline(cin, cmd);
	}
	return cmd;
}

M::M(int coal, int iron, int hali, int copp, int ston,
	 int sapp, int emer, int ruby, int topa, int lapi,
	 int gold, int silv, int diam, int life, int phil)
{
	this->coal = coal;
	this->iron = iron;
	this->hali = hali;
	this->copp = copp;
	this->ston = ston;

	this->sapp = sapp;
	this->emer = emer;
	this->ruby = ruby;
	this->topa = topa;
	this->lapi = lapi;

	this->gold = gold;
	this->silv = silv;
	this->diam = diam;
	this->life = life;
	this->phil = phil;
}
void M::rand(int skill_lev)
{
	while (prob(COAL)) coal++;
	while (prob(IRON)) iron++;
	while (prob(HALI)) hali++;
	while (prob(COPP)) copp++;

	while (prob(TOPA + skill_lev)) topa++;
	while (prob(EMER + skill_lev)) emer++;
	while (prob(LAPI + skill_lev)) lapi++;
	while (prob(SAPP + skill_lev)) sapp++;
	while (prob(RUBY + skill_lev)) ruby++;

	while (prob(GOLD)) gold++;
	while (prob(SILV)) silv++;
	while (prob(DIAM)) diam++;
	while (prob(LIFE)) life++;
	while (prob(PHIL)) phil++;
}

Chest::Chest(bool is_locked)
{
	is_opened = false;
	this->is_locked = is_locked;
	items.rand(25);

	if (items.coal == 0 && items.iron == 0 && items.hali == 0 && items.copp == 0 && items.ston == 0 && 
		items.sapp == 0 && items.emer == 0 && items.ruby == 0 && items.topa == 0 && items.lapi == 0 && 
		items.gold == 0 && items.silv == 0 && items.diam == 0 && items.life == 0 && items.phil == 0) is_empty = true;
	else is_empty = false;
}
void Chest::open()
{
	if (is_empty == false)
	{
		cout << "\n You open the chest. Inside you find:\n";
		if (items.coal > 0)
		{
			cout << " - some of COAL\n";
			is_empty = false;
		}
		if (items.iron > 0)
		{
			cout << " - ore of IRON\n";
			is_empty = false;
		}
		if (items.hali > 0)
		{
			cout << " - ore of HALITE (rock salt)\n";
			is_empty = false;
		}
		if (items.copp > 0)
		{
			cout << " - ore of COPPER\n";
			is_empty = false;
		}

		if (items.sapp > 0)
		{
			cout << " - ore of ";
			LBLUE cout << "SAPPHIRE\n"; NORMAL
				is_empty = false;
		}
		if (items.emer > 0)
		{
			cout << " - ore of ";
			LGREEN cout << "EMERALD\n"; NORMAL
				is_empty = false;
		}
		if (items.ruby > 0)
		{
			cout << " - ore of ";
			LRED cout << "RUBY\n"; NORMAL
				is_empty = false;
		}
		if (items.topa > 0)
		{
			cout << " - ore of ";
			YELLOW cout << "TOPAZ\n"; NORMAL
				is_empty = false;
		}
		if (items.lapi > 0)
		{
			cout << " - ore of ";
			LBLUE cout << "LAPIS LAZULI\n"; NORMAL
				is_empty = false;
		}

		if (items.gold > 0)
		{
			cout << " - ore of ";
			LYELLOW cout << "GOLD\n"; NORMAL
				is_empty = false;
		}
		if (items.silv > 0)
		{
			cout << " - ore of ";
			LNORMAL cout << "SILVER\n"; NORMAL
				is_empty = false;
		}
		if (items.diam > 0)
		{
			cout << " - ore of ";
			LCYAN cout << "DIAMOND\n"; NORMAL
				is_empty = false;
		}
		if (items.life > 0)
		{
			cout << " - ore of ";
			LRED cout << "LIFE CRYSTAL\n"; NORMAL
				is_empty = false;
		}
		if (items.phil > 0)
		{
			cout << " - ore of ";
			LPINK cout << "PHILOSOPHER'S STONE\n"; NORMAL
				is_empty = false;
		}
	}
	else cout << " This chest is empty.\n";
}
void Chest::run()
{
	if (is_locked == true) cout << " You need a key to open this chest.\n";
	else if (is_empty == true) cout << " This chest is empty.\n";
	else
	{
		open();
		string cmd;
		cout << " ";
		getline(cin, cmd);
		while (cmd != "close" && is_empty == false)
		{
			if (cmd == "take") take();
			if (is_empty == false)
			{
				cout << " ";
				getline(cin, cmd);
			}
		}
	}

}
void Chest::take()
{
	if (is_empty == false)
	{
		p_coal += items.coal; items.coal = 0;
		p_iron += items.iron; items.iron = 0;
		p_hali += items.hali; items.hali = 0;
		p_copp += items.copp; items.copp = 0;
		p_ston += items.ston; items.ston = 0;

		p_sapp += items.sapp; items.sapp = 0;
		p_emer += items.emer; items.emer = 0;
		p_ruby += items.ruby; items.ruby = 0;
		p_topa += items.topa; items.topa = 0;
		p_lapi += items.lapi; items.lapi = 0;
		
		p_gold += items.gold; items.gold = 0;
		p_silv += items.silv; items.silv = 0;
		p_diam += items.diam; items.diam = 0;
		p_life += items.life; items.life = 0;
		p_phil += items.phil; items.phil = 0;
		cout << " You take all chest content.\n";
		is_empty = true;
	}
	else cout << " There isn't this item.\n";
}

Npc::Npc()
{
	string npc_name[][11] = { { "Deron","Shale", "Ganon","Botarlig", "Nundouth", "Hardril", "Gragraeg", "Olivier", "Hanumi","Glatgrath","Gatoc" },
							  { "Shadowthane","Stroker","Backfill", "Flintmaul", "Ironbringe", "Ironstone", "Silverborn", "Leadbender", "Leadback","Battlebeard","Goldenore" } };

	name0 = npc_name[0][random(0, 10)];
	name1 = npc_name[1][random(0, 10)];
	p_name = "";
	need = prob(50);
	if (need == true)
	{
		what_need = random(0, 4);
		how_much = random(5, 15);
	}
}
void Npc::hi()
{
	const int First = 2;
	const int About = 2;

	string first[First] = {" \n Hi!"," \n Hello!"};
	string about[About] = {" I'm one of the Mining Guys.\n We are very small people living underground.\n",
						   " I'm a dwarf from High Mountains.\n I come here with my companions to mine some GOLD!.\n"};

	cout << first[random(0, First-1)];
	cout << " My name is " << name0 << " " << name1 << ".\n";
	cout << about[random(0, About-1)];
}
void Npc::speak()
{
	const int Get = 3;
	string get_name[Get] = { "I hope I won't forget.\n", "I hope I will remember...\n", "I'll try to remember.\n"};

	cout << " And what's your name brother?\n ";
	getline(cin, p_name);
	while (p_name.empty())
	{
		cout << " What? Can you speak louder?\n";
		getline(cin, p_name);
	}
	if (need) cout << endl;
	cout << " " << get_name[random(0,Get-1)];

}
void Npc::problem()
{
	const int Prob = 1;
	string min;
	string cmd;
	string problem[Prob][3] = { {" I've got a problem.\n I have to quickly get some ", " but I don't have much time.\n Could you give me some ", " please? Of course if you have.\n"} };

	if (what_need == 0) min = "coal";
	else if (what_need == 1) min = "iron";
	else if (what_need == 2) min = "halite";
	else if (what_need == 3) min = "copper";
	else if (what_need == 4) min = "stone";

	//////////////////////////////////////////////////////////

	cout << problem[random(0, Prob - 1)][0]
		<< min
		<< problem[random(0, Prob - 1)][1]
		<< min
		<< problem[random(0, Prob - 1)][2];

	cout.put(' ');
	getline(cin, cmd);
	while (cmd != "yes" && cmd != "no")
	{
		cmds(cmd);
		getline(cin, cmd);
	}

	if (cmd == "yes")
	{
		if (what_need == 0)
			if (p_coal < how_much) cout << " You don't have enought coal.\n Tough luck, I'm going to mine again...\n";
			else {p_coal -= how_much; thank();}
		if (what_need == 1)
			if (p_iron < how_much) cout << " You don't have enought iron.\n Tough luck, I'm going to mine again...\n";
			else { p_iron -= how_much; thank(); }
		if (what_need == 2)
			if (p_hali < how_much) cout << " You don't have enought halite.\n Tough luck, I'm going to mine again...\n";
			else { p_hali -= how_much; thank(); }
		if (what_need == 3)
			if (p_copp < how_much) cout << " You don't have enought copper.\n Tough luck, I'm going to mine again...\n";
			else { p_copp -= how_much; thank(); }
		if (what_need == 4)
			if (p_ston < how_much) cout << " You don't have enought stone.\n Tough luck, I'm going to mine again...\n";
			else { p_ston -= how_much; thank(); }
		
	}
	else cout << " Tough luck, I'm going to mine again...\n";

}
void Npc::thank()
{
	int what = random(0,5);
	int number = random(1,3);
	string min;

	cout << "\n Thank you " << p_name << "!\n";

	if (number < 5)
	{
		if (what == 0)
		{
			min = "SAPPHIRE";
			p_sapp += number;
		}
		else if (what == 1)
		{
			min = "EMERALD";
			p_emer += number;
		}
		else if (what == 1)
		{
			min = "RUBY";
			p_ruby += number;
		}
		else if (what == 1)
		{
			min = "TOPAZ";
			p_topa += number;
		}
		else if (what == 1)
		{
			min = "LAPIS LAZULI";
			p_lapi += number;
		}
		cout << " Take this! It will be very usefull in fulture\n when you visit the deeper places of this mine.\n" << " You get " << number << " bytes of " << min << "!\n";
	}
}
void Npc::run()
{
	if (p_name.empty())
	{
		if (need)
		{
			hi();
			speak();
			problem();
		}
		else hi();
	}
	else proverb();
}
void Npc::proverb()
{
	const int num = 17;
	string pro[num]
	{
		"Actions speak louder than words.",
		"A room without books is a body without soul.",
		"Actions speak louder than words.",
		"A bad excuse is better than none.",
		"To understand recursion you first need to understand recursion.",
		"All that glitters is not gold.",
		"Among the blind one - eyed man is a king.",
		"Don't count your chickens before they're hatched.",
		"East or West home is best.",
		"Fortune favours the brave.",
		"Forbidden fruit is sweetest.",
		"It is a double pleasure to deceive the deceiver.",
		"It is a wise talker who knows when he has nothing to say.",
		"Opportunity makes a thief.",
		"Rome was not built in a day.",
		"Time is a great healer.",
		"When in Rome do as the Romans do."
	};

	cout << "\n " << pro[random(0, num-1)] << "\n";
}


Tunnel::Tunnel(int skill_lev, int r_num)
{
	coal = 5;	while (prob(50)) coal++;
	iron = 5;	while (prob(45)) iron++;
	hali = 5;	while (prob(35)) hali++;
	copp = 5;	while (prob(35)) copp++;

	topa = 0;	while (prob(10 + skill_lev))  topa++;
	emer = 0;	while (prob(5 + skill_lev))   emer++;
	lapi = 0;	while (prob(-5 + skill_lev))  lapi++;
	sapp = 0;	while (prob(-10 + skill_lev)) sapp++;
	ruby = 0;	while (prob(-15 + skill_lev)) ruby++;

	name = t_name[0][random(0,10)] + " " + t_name[1][random(0, 10)];
	this->skill_lev = skill_lev;
	this->r_num = r_num;
	pos = -1;
	room = new Room * [r_num];
	for (int i = 0; i < r_num; ++i)
		room[i] = new Room(skill_lev);
}
Tunnel::~Tunnel()
{
	for (int i = 0; i < r_num; ++i)
		delete room[i];
}
void Tunnel::show()
{
	cout << " You are in " << name << ".\n"
		<< " If You want to get out of here,\n You have to collect these items:\n";
	if (coal != 0) cout << " - " << coal << "B of coal\n";
	if (iron != 0) cout << " - " << iron << "B of iron\n";
	if (hali != 0) cout << " - " << hali << "B of halite\n";
	if (copp != 0) cout << " - " << copp << "B of copper\n";
	if (topa != 0) cout << " - " << topa << "B of topaz\n";
	if (emer != 0) cout << " - " << emer << "B of emerald\n";
	if (lapi != 0) cout << " - " << lapi << "B of lapis lazuli\n";
	if (sapp != 0) cout << " - " << sapp << "B of sapphire\n";
	if (ruby != 0) cout << " - " << ruby << "B of ruby\n";

	//for (int i = 0; i < r_num; ++i) cout << "-#";
	//cout << "-" << endl;
	//for (int i = 0; i < r_num; ++i) if (i == pos) cout << "^"; else cout << " ";
	//cout << endl;
}
void Tunnel::run()
{
	show();
	string cmd;
	cout << " ";
	getline(cin, cmd);

	while (true)
	{
		if (cmd == "go" || cmd == "g")
		{
			if (pos < r_num - 1)
			{
				cout << " You go ahead.\n";
				++pos;
				cmd =(*room[pos]).run();
			}
			else
			{
				cout << " You can't exit this place now.\n You still need:\n - foo foo foo\n";
				cout << " ";
				getline(cin, cmd);
			}
		}
		else if (cmd == "back" || cmd == "b")
		{
			if (pos > 0)
			{
				cout << " You go back.\n";
				--pos;
				cmd = (*room[pos]).run();
			}
			else
			{
				cout << " You can't go back.\n";
				cout << " ";
				getline(cin, cmd);
			}
		}
		else if (cmd == "now" || cmd == "n")
		{
			if (pos >= 0) cmd = (*room[pos]).run();
			else
			{
				show();
				cout << " ";
				getline(cin, cmd);
			}
		}
		else
		{
			cmds(cmd);
			cout << " ";
			getline(cin, cmd);
		}
	}
}


void inv()
{
	cout << " COAL  IRON  HALI  COPP  STON\n ";
	cout.width(4); cout << right << p_coal << "  ";
	cout.width(4); cout << right << p_iron << "  ";
	cout.width(4); cout << right << p_hali << "  ";
	cout.width(4); cout << right << p_copp << "  ";
	cout.width(4); cout << right << p_ston << "\n\n";

	cout << " SAPP  EMER  RUBY  TOPA  LAPI\n ";
	cout.width(4); cout << right << p_sapp << "  ";
	cout.width(4); cout << right << p_emer << "  ";
	cout.width(4); cout << right << p_ruby << "  ";
	cout.width(4); cout << right << p_topa << "  ";
	cout.width(4); cout << right << p_lapi << "\n\n";

	cout << " GOLD  SILV  DIAM  LIFE  PHIL\n ";
	cout.width(4); cout << right << p_gold << "  ";
	cout.width(4); cout << right << p_silv << "  ";
	cout.width(4); cout << right << p_diam << "  ";
	cout.width(4); cout << right << p_life << "  ";
	cout.width(4); cout << right << p_phil << "\n\n";

	cout << " UNIQUE ITEMS:\n none\n";

}
void cmds(string cmd)
{
	////////////////////////////////////

	if (cmd == "l" || cmd == "layer");
	else if (cmd == "dig" || cmd == "d") cout << " There are nothing to dig.\n";
	else if (cmd.substr(0, 1) == "m" || cmd.substr(0, 4) == "mine") cout << " You don't see anything to mine.\n";
	else if (cmd == "inventory" || cmd == "i") inv();
	// else if (cmd == "dwarfsgod") COAL = IRON = COPP = HALI = STON = TOPA = EMER = SAPP = LAPI = RUBY = SILV = LIFE = GOLD = PHIL = DIAM = 99;
	else if (cmd == "deathless") p_hp = 666666666;
	else if (cmd == "hp") cout << " Your health points = " << p_hp << endl;

	////////////////////////////////////
	else if (cmd.empty() == true) cout << " Type a command here.\n";
	else cout << " What?\n";

}
bool prob(int prob)
{
	uniform_int_distribution<> range(0, 100);
	if (range(gen) <= prob) return true;
	else return false;
}
int random(int a, int b)
{
	uniform_int_distribution<> range(a, b);
	return range(gen);
}
