#include <iostream>

using namespace std;

struct game
{
	char name[30];
	float price;
	float rate;
};

void swap(game & a, game & b)
{
	game temp = a;
	a = b;
	b = temp;
}

int main(int argc, char ** argv)
{
	game astro= {"Astro", 9.99, 3.2};
	game lab= {"Darkness", 4.99, 4.1};
	
	cout << "Gra 1: " << astro.name << endl;
	cout << "Gra 2: " << lab.name << endl;
	cout << "ZAMIANA - przypisanie z uwzglednieniem pol\n";
	swap(astro, lab);
	cout << "Gra 1: " << astro.name << endl;
	cout << "Gra 2: " << lab.name << endl;
		
	return 0;
}