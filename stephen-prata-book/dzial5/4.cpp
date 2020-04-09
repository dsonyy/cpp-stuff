#include <iostream>
using namespace std;

int main()
{
	float Dafne = 100.0;
	float Cleo = 100.0;
	int year;
	
	for (year = 1; Cleo <= Dafne; ++year)
	{
		Dafne += 100 * 0.1;
		Cleo += Cleo * 0.05;
		cout << "==ROK " << year << "==" << endl;
		cout << "Saldo Dafne = " << Dafne << endl;
		cout << "Saldo Cleo  = " << Cleo << endl;
	}
	
	return 0;
}