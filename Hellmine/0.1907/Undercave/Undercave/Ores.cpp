#include "undermine.h"

Ores::Ores( int coal= 0, int iron= 0, int hali= 0, int copp= 0, int ston= 0,
			int sapp= 0, int emer= 0, int ruby= 0, int topa= 0, int lapi= 0,
			int gold= 0, int silv= 0, int diam= 0, int life= 0, int phil= 0)
{
	this->coal = coal;	Coal = 35;
	this->iron = iron;	Iron = 27;
	this->hali = hali;	Hali = 20;
	this->copp = copp;	Copp = 20;
	this->ston = ston;	Ston = 75;

	this->sapp = sapp;	Sapp = -7;
	this->emer = emer;	Emer = 7;
	this->ruby = ruby;  Ruby = -15;
	this->topa = topa;  Topa = 10;
	this->lapi = lapi;  Lapi = 0;
		
	this->gold = gold;  Gold = 7;
	this->silv = silv;  Silv = 10;
	this->diam = diam;  Diam = 1;
	this->life = life;  Life = 10;
	this->phil = phil;  Phil = 7;
}

void Ores::rand(int add)
{
	if (add > 25) add = 25;

	wrand(&coal, Coal);
	wrand(&iron, Iron);
	wrand(&hali, Hali);
	wrand(&copp, Copp);
	wrand(&ston, Ston);

	wrand(&sapp, Sapp + add);
	wrand(&emer, Emer + add);
	wrand(&ruby, Ruby + add);
	wrand(&topa, Topa + add);
	wrand(&lapi, Lapi + add);

	wrand(&gold, Gold);
	wrand(&silv, Silv);
	wrand(&diam, Diam);
	wrand(&life, Life);
	wrand(&phil, Phil);
}

bool Ores::isempty()
{
	if (coal <= 0 && iron <= 0 && hali <= 0 && copp <= 0 && ston <= 0 &&
		sapp <= 0 && emer <= 0 && ruby <= 0 && topa <= 0 && lapi <= 0 &&
		gold <= 0 && silv <= 0 && diam <= 0 && life <= 0 && phil <= 0)
		return true;
	else return false;
}

void Ores::wrand(int * what, int proba)
{
	if (prob(proba))
	{
		++*what;
		while (prob(50))++*what;
	}
}