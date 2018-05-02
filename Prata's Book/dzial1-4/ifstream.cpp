#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int SIZE = 60;

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
	
	fin >> val; // tutaj wbija na eof
	while (fin.good())
	{
		++count;
		sum += val;
		cout << "OK\n";
		fin >> val;
	}
	if (fin.eof())
		cout << "Koniec pliku.\n";
	else if (fin.fail())
		cout << "Blad podczas odczytywania danych.\n";
	else
		cout << "Wczytywanie przerwane, przyczyna nieznana.\n";
	if (count == 0)
		cout << "Nie wczytano zadnych danych.\n";
	else
	{
		cout << "Wczytano elementow: " << count << endl;
		cout << "Suma: " << sum << endl;
		cout << "Srednia: " << sum/count << endl;
	}
	
	fin.close();	
	return 0;
}