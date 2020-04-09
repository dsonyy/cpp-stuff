// lotto.cpp -- prawdopodobienstwo wygranej
// dzial 7, strona 290
#include <iostream>

double probability(unsigned NUMBERS, unsigned PICKS);
	// zwraca prawdopodobienstwo trafnego wybrania PICKS z NUMBERS mozliwych

int main()
{
	using namespace std;
	double total;
	double choices;
	
	cout << "Podaj najwieksza liczbe jaka mozna wybrac, oraz liczbe skreslen.\n";
	while ((cin >> total >> choices) && choices <= total )
	{
		cout << "Szansa wygranej to jeden do ";
		cout << probability(total, choices);
		cout << ".\n";
		cout << "Nastepe dwie liczby (q, aby zakonczyc): ";
	}
	
	cout << "Do widziena\n";
	return 0;
}
 
double probability(unsigned numbers, unsigned picks)
{
	double result = 1.0;
	double n;
	unsigned p;
	
	for (n = numbers, p = picks; p > 0; --n, --p)
		result = result * n / p;
	
	return result;
}