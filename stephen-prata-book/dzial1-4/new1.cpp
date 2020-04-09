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
	
	pt = new int;
	*pt = 89.11;
	cout << "Utworzenie nowego objektu danych." << endl;
	cout << "Wartosc objektu   = " << *pt << endl;
	cout << "Polozenie objektu = " << pt << endl;
	cout << "Wielkosc objektu  = " << sizeof(*pt) << endl;
	cout << "Wielkosc wskaznika= " << sizeof(pt) << endl;
	
	delete pt;
	return 0;
}