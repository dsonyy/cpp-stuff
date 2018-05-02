#include <iostream>
#include <array>
using namespace std;

const int AR_SIZE = 100;

int main()
{
	array<long double, AR_SIZE> tab;
	tab[1] = tab[0] = 1LL;
	
	for (int i = 2; i < AR_SIZE; i++)
		tab[i] = i * tab[i-1];
	
	for (int i = 0; i < AR_SIZE; i++)
		cout << i << "! = " << tab[i] << endl;
	
	return 0;
}