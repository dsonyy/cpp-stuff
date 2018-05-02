#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
	int home = 32;
	int * sign = &home;
	
	cout << "Wartosc zmiennej home = " << home << endl;
	cout << "Adres zmiennej home = "	 	<< &home <<endl << endl;
	cout << "Wartosc zmiennej sign = " << sign << endl;
	cout << "Adres zmiennej sign = " << &sign << endl;
	cout << "Wartosc wskazywana przez zmienna sign = " << *sign << endl;
	
	return 0;
}