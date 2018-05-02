#include <iostream>
using namespace std;

int main()
{
	int tab[10] = {0,1,2,3,4,5,6,7,8,9};
	int * p1 = &tab[5];
	int * p2 = &tab[3];
	
	cout << "Adres p1 = " << p1 << endl;
	cout << "Adres p2 = " << p2 << endl;
	cout << "p1 - p2  = " << p1 - p2 << endl;
	
	
	
	return 0;
}