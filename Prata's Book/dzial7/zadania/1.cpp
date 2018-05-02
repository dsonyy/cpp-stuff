#include <iostream>
using namespace std;

double count();

int main()
{		
	double avarage;
	
	avarage = count();
	while (avarage != 0)
	{
		cout << "Srednia harmoniczna: " << avarage;
		cout << "\n==========================\n";
		avarage = count();
	}
	
	cout << "Do widzenia!\n";
	return 0;
}

double count()
{
	double x, y;
	
	cout << "Rzuc no liczbe X: ";
	cin >> x;
	if (x == 0) 
		return 0;
	
	cout << "Rzuc no liczbe Y: ";
	cin >> y;
	if (y == 0)
		return 0;
	else
		return 2.0 * x * y / (x + y);
}