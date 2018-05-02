#include <iostream>
#include <cstring>
using namespace std;

const int BUFFER_SIZE = 50;

int main()
{
	char buffer[BUFFER_SIZE];
	//char * buffer = new char [BUFFER_SIZE];
	char * txt;
	
	cout << "Podaj slowo.\n";
	cin >> buffer;
	
	txt = new char [strlen(buffer) + 1];
	strcpy(txt, buffer);
	
	cout << "\nZawartosc buforu   = " << buffer << endl;
	cout << "Zawartosc zmiennej = " << txt << endl;
	cout << "Adres buforu   = " << &buffer << endl;
	cout << "Adres zmiennej = " << &txt << endl;
	cout << "Rozmiar buforu   = " << sizeof(buffer) << endl;
	cout << "Rozmiar zmiennej = " << strlen(buffer) + 1 << endl;
	
	// rob cos ze zmienna txt ...
	
	delete [] txt;
	
	return 0;
}