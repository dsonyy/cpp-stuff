#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	int size;
	int * tab;
	
	cout << "Podaj rozmiar tablicy\n";
	cin >> size;
	tab = new int [size];
	for (int i = 0; i < size; ++i)
	{
		cout << "Podaj wartosc " << i+1 << ".\n";
		cin >> tab[i];
	}
	cout << "OK Gotowe!\n";
	for (int i = 0; i < size; ++i)
	{
		cout << "Wartosc " << i+1 << " = " << tab[i] << "\n";
	
	}
	delete [] tab;
	return 0;
}