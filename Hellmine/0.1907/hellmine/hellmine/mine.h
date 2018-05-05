#include <iostream>
#include <string>
#include <random>
#include <cctype>
#include <windows.h>

using namespace std;

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

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
mt19937 gen(random_device{}());

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// places name table
string t_name[][11] = { { "Donut","Ice Cream","Cookie", "Coffee", "Milky", "Lost", "Forgotten", "Rainbow", "Secret", "Mysterious", "Nightmare" },
{ "Underground","Shaft","Cave","Tunnel", "Mine", "Passage", "Dungeon", "Room", "Place", "Abyss", "Cellar" } };

// the ores drop probability
int COAL = 45;
int IRON = 35;
int COPP = 25;
int HALI = 25;

int TOPA = 15;
int EMER = 10;
int SAPP = -7;
int LAPI = -18;
int RUBY = -22;

int SILV = 7;
int LIFE = 7;
int GOLD = 5;
int PHIL = 5;
int DIAM = 1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*struct stuff
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
};*/
class M
{
	int next_drop = 65;

public:
	int coal, iron, hali, copp, ston; // common
	int sapp, emer, ruby, topa, lapi; // gems
	int gold, silv, diam, life, phil; // other

	M(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);

	// random ores number
	void rand(int);
private:
	void next(int*, int);
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

class Key
{
	string name;
public:
	Key(void);
	Key(string);

	string info(void);
	void take(void);
};

class Chest
{
	string name;
	M items;

	int * type(string); /// ore name --to--> pointer to ore in "item"
public:
	bool is_opened;
	bool is_locked;
	bool is_empty;

	Chest(void);
	Chest(bool);
	Chest(M);
	Chest(bool, M);

	void show(void);
	void in(string, int);
	void out(M*);
	void out(string, int, int*);
	void out(string, int*);

	void rename(void);
	void rename(string);

	void run(void);
};
class Bag
{
	string name;
	M item; /// content
	bool is_empty;

	int * type(string); /// ore name --to--> pointer to ore in "item"
public:
	Bag(void);
	Bag(M); // extra ores

	void show(string); // one ore info
	void show(void); // every ores info

	void in(M); // add M to "item"
	void in(string, int); // add one ore type to "item" -- ore name, ores number 

	void out(M*); // take off M
	void out(string, int, int*); // take off one ores type -- ore name, ores number, pointer to destination
	void out(string, int*);
};
class Inv
{
	const int Bag_max = 2;
	int bag_main;

	int key;
	int key_red;
	int key_blue;

	Bag * bag;

public:
	Inv(void);
	Inv(Bag);
	
	void in(int, int, int);
	void in(Bag);

	void out(int, int, int);
	void out(Bag);

	void show(void);
};
class P
{
	int hp;
	int key;
	Bag * bag; /// bag on ores

public:
	P(int = 999);
	P(M, int = 999); // bonus ores on start
	P(Bag, int = 999); 

	void in(string, int); // ores input -- ore name, ores number
	void out(string, int*); // ores output -- ore name, pointer to the destination
	void out(string, int, int*); // ores output -- ore name, ores number, pointer to the destination
	
	void iKey(int);
	void oKey(int);

	void inv(void);
};

void cmds(string);		// check the given command
bool prob(int);			// random a number of specified probability
int random(int, int);	// random a number of specified range
