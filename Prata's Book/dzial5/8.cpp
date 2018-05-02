#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char tab[50];
	int count = 0;
	cout << "Podawaj slowa, kiedy skonczysz napisz 'gotowe'.\n";
	
	cin >> tab;
	while (strcmp(tab, "gotowe") != 0)
	{
		++count;
		cin >> tab;
	}
	cout << "Podano " << count << " slow (chyba).\n";
	
	return 0;
}