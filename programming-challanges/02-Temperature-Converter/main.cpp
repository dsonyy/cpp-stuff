#include <iostream>

#include "conv.h"
using namespace std;

int main()
{
	int nav;
	double deg;
	double K, C, F, R, N;

	cout << "Choose the basic unit:\n"
		<< "- [1] Kelvin degrees\n"
		<< "- [2] Celsius degrees\n"
		<< "- [3] Fahrenheit degrees\n"
		<< "- [4] Rankine degrees\n"
		<< "- [5] Newton degrees\n";
	cin >> nav;
	while (!cin || nav < 0 || nav > 6)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "What?!\n";
		cin >> nav;
	}

	cout << "\nEnter the number of degrees.\n";
	cin >> deg;
	while (!cin)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "What?!\n";
		cin >> deg;
	}

	if (nav == 1)
	{
		K = deg;
		C = K + 273.15;
		F = (C * 1.8) + 32;
		R = (C + 273.15) * 1.8;
		N = C * 33 / 100;
	}
	else if (nav == 2)
	{
		C = deg;
		K = C + 273.15;
		F = (C * 1.8) + 32;
		R = (C + 273.15) * 1.8;
		N = C * 33 / 100;
	}
	else if (nav == 3)
	{
		F = deg;
		C = (F - 32) / 1.8;
		K = (F + 459.67) * 5 / 9;
		R = F + 459.67;
		N = (F - 32) * 11 / 60;
	}
	else if (nav == 4)
	{
		R = deg;
		C = (R - 491.67) * (5.0/9.0);
		F = (C * 1.8) + 32;
		K = C + 273.15;
		N = C * 33.0 / 100.0;
	}
	else if (nav == 5)
	{
		N = deg;
		C = N * (100/33);
		F = (C * 1.8) + 32;
		K = C + 273.15;
		R = (C + 273.15) * 1.8;
	}
	else
		cout << "HOLY SHIT! AN ERROR OCCURED.\n";

	cout << "\nKelvin =\t" << K << endl
		<< "Celsius =\t" << C << endl
		<< "Fahrenheit =\t" << F << endl
		<< "Rankine =\t" << R << endl
		<< "Newton =\t" << N << endl;

	while (cin.get() != '\n');
	cin.get();
	return 0;
}