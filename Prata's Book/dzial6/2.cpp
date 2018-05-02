#include <iostream>
#include <array>
using namespace std;

const int AR_SIZE = 10;

int main()
{
	array<double, AR_SIZE> donates;
	double total = 0;
	double avarage;
	int used = 0;
	
	cout << "Podawaj sumy datkow w zl. Wprowadz wartosc nieliczbowa aby zakonczyc.\n";
	for (int i = 0; i < AR_SIZE; ++i)
	{
		if (!cin.good())
		{
			donates[i] = 0;
			continue;
		}
		cout << "Datek " << i+1 << ": ";
		cin >> donates[i];
		total += donates[i];
		if (cin.good())
			++used;
	}
	avarage = total / double(used);
	cout << "======================\n"
			<< "Srednia = " << avarage << endl
			<< "Datki powyzej sredniej:\n";
	for (int i = 0; i < used; ++i)
		if (donates[i] > avarage)
			cout << "Datek " << i+1 << " = " << donates[i] << endl;
	cout << "Dowidzienia\n";
	
	
}