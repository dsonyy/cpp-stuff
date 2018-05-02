// dzial 7 strona 328
// funptr.cpp -- wskazniki na funkcje
#include <iostream>

using namespace std;

double betsy(int);
double pam(int);
void estimate(int, double (*)(int));

int main()
{
	int code;
	
	cout << "Ile wierszy kodu nalezy napisac.\n";
	cin >> code;
	cout << "Oszacowanie Betsy:\n";
	estimate(code, betsy);
	cout << "Oszacowanie Pam:\n";
	estimate(code, pam);
	
	return 0;
}

double betsy(int a)
{
	return a * 0.05;
}

double pam(int a)
{
	return a * 0.03 + a * a * 0.004; 
}

void estimate(int lines, double (*pf)(int))
{
	cout << lines << " wiersy wymaga ";
	cout << (*pf)(lines) << " godzin pracy.\n";
}