#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char ** argv)
{
	const int SIZE = 20;
	char dessert[SIZE];
	char name[SIZE];
	
	cout << "What's your name?\n";
	cin.getline(name, SIZE);
	cout << "What's your favourite dessert?\n";
	cin.getline(dessert, SIZE);
	cout << "OK " << name << ", I've got " << dessert << " for you.\n";
	
	return 0;
}