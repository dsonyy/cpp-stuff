#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	char filename[60];
	double val;
	double sum = 0.0;
	int count = 0;
	ifstream fin;
	
	cout << "Podaj nazwe pliku.\n";
	cin.getline(filename, 60);
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Otwarcie pliku nie powiodlo sie :(\n";
		exit(EXIT_FAILURE);
	}
	/*
	do
	{
		fin >> val;
		if (fin)
		{
			cout << "Odczytano " << val << endl;
			++count;
		}
	} while (fin);
	*/
	fin >> val;
	while (fin.good())
	{
			cout << "Odczytano " << val << endl;
			++count;
			fin >> val;
	}
	
	
	if (fin.eof())
		cout << "Koniec pliku.\n";
	else if (fin.fail())
		cout << "Blad podczas odczytywania danych.\n";
	if (count == 0)
		cout << "Nie wczytano zadnych danych.\n";
	else
		cout << "Wczytano elementow: " << count << endl;
		
	return 0;
}