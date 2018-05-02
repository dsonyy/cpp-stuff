#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	int nights = 1001;
	cout << "Wartosc zmiennej   = " << nights << endl;
	cout << "Polozenie zmiennej = " << &nights << endl << endl;
	
	
	int * pt = new int; // nowy objekt danych
	*pt = 1001;
	cout << "Utworzenie nowego objektu danych." << endl;
	cout << "Wartosc objektu   = " << *pt << endl;
	cout << "Polozenie objektu = " << pt << endl;
	cout << "Wielkosc objektu  = " << sizeof(*pt) << endl;
	cout << "Wielkosc wskaznika= " << sizeof(pt) << endl << endl;
	
	double * pd = new double;
	*pd = 89.11;
	cout << "Utworzenie nowego objektu danych." << endl;
	cout << "Wartosc objektu   = " << *pd << endl;
	cout << "Polozenie objektu = " << pd << endl;
	cout << "Wielkosc objektu  = " << sizeof(*pd) << endl;
	cout << "Wielkosc wskaznika= " << sizeof(pd) << endl;
	
	delete pt;
	delete pd;
	return 0;
}