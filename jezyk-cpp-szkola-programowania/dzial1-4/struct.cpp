#include <iostream>

using namespace std;

struct game
{
	char name[30];
	float price;
	float rate;
};

int main(int argc, char ** argv)
{
	game astro= {"Astro", 9.99, 3.2};
	game lab= {"Darkness", 4.99, 4.1};
	
	cout << "Gra 1: " << astro.name << endl;
	cout << "Gra 2: " << lab.name << endl;
	
	return 0;
}