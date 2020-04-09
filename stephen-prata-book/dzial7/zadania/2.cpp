#include <iostream>
using namespace std;

const int Array_size = 10;

int    ScoreSet(int[Array_size]);
void   ScoreShow(const int[Array_size]);
double ScoreAvarage(const int[Array_size]);


int main()
{
	int score[Array_size];
	
	cout << "Podaj do dziecieciu wynikow golfowych.\n";
	cout << "Wprowadz wartosc ujemna aby zakonczyc wprowadzanie\n";
	ScoreSet(score);
	
	cout << "===========================\n";
	ScoreShow(score);
	
	cout << "Do widzenia!\n";
	return 0;
}

int ScoreSet(int tab[Array_size])
{
	for (int i = 0; i < Array_size; i++)
	{
		cout << "Wynik " << i+1 << ": ";
		cin >> tab[i];
		if (tab[i] < 0)
			break;
	}
}

void ScoreShow(const int tab[Array_size])
{
	for (int i = 0; i < Array_size; i++)
	{	
		if (tab[i] < 0)
			break;
		cout << "Wynik " << i+1 << ": " << tab[i] << endl;
	}
	cout << "\nSrednia: " << ScoreAvarage(tab) << endl;
}

double ScoreAvarage(const int tab[Array_size])
{
	double avarage = 0.0;
	int i;
	
	for (i = 0; i < Array_size; i++)
	{	
		if (tab[i] < 0)
			break;
		avarage += tab[i];
	}
	
	if (i == 0)
		return 0;
	else
		return avarage / double(i);
}