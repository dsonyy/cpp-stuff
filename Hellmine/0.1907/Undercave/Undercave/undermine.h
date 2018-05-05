#include <iostream>
#include <random>
using namespace std;

mt19937 gen(random_device{}());

bool prob(int);

///////////////////////////////////////////////////////////////////////////////////////////////

class Ores
{
	int coal, iron, hali, copp, ston;
	int sapp, emer, ruby, topa, lapi;
	int gold, silv, diam, life, phil;
		
	int Coal, Iron, Hali, Copp, Ston;
	int Sapp, Emer, Ruby, Topa, Lapi;
	int Gold, Silv, Diam, Life, Phil;

public:
	Ores(int = 0, int = 0, int = 0, int = 0, int = 0,
		 int = 0, int = 0, int = 0, int = 0, int = 0,
		 int = 0, int = 0, int = 0, int = 0, int = 0);

	void rand(int);
	bool isempty(void);
private:
	void wrand(int*, int);
};

class Itembox
{
	int i;
public:
	void x()
	{

	}
};

class Chest
{
	string name;
	Ores items;

	int * type(string); /// ore name --to--> pointer to ore in "items"
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
