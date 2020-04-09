#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	char automobile[50];
	int year;
	double a_price;
	double b_price;
	ofstream fout;
	fout.open("_carinfo");
	
	cout << "Podaj marke i model samochodu.\n";
	cin.getline(automobile, 50);
	cout << "Podaj rok produkcji.\n";
	cin >> year;
	cout << "Podaj cene wyjsciowa.\n";
	cin >> a_price;
	b_price = 0.913 * a_price;
	
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "\nMarka i model: " << automobile << endl;
	cout << "Rok: " << year << endl;
	cout << "Cena wywolawcza: " << a_price << endl;
	cout << "Cena biezaca: " << b_price << endl;
	
	fout << fixed;
	fout.precision(2);
	fout.setf(ios_base::showpoint);
	fout << "\nMarka i model: " << automobile << endl;
	fout << "Rok: " << year << endl;
	fout << "Cena wywolawcza: " << a_price << endl;
	fout << "Cena biezaca: " << b_price << endl;
	
	
	fout.close();
	return 0;
}