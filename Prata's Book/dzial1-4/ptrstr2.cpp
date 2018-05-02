#include <iostream>
#include <cstring>
using namespace std;

const int BUFFER_SIZE = 50;

int main()
{
	char   buffer1[BUFFER_SIZE];
	char * buffer2 = new char [BUFFER_SIZE];
	char * txt1;
	char * txt2;
	
	cout << "Podaj slowo do boforu 1.\n";
	cin >> buffer1;
	cout << "Podaj slowo do boforu 2.\n";
	cin >> buffer2;
	
	txt1 = new char [strlen(buffer1) + 1];
	strcpy(txt1, buffer1);
	
	txt2 = new char [strlen(buffer2) + 1];
	strcpy(txt2, buffer2);
	
	
	cout << "\nZawartosc buforu 1 = " << buffer1 << endl;
	cout << "Zawartosc buforu 2 = " << buffer2 << endl;
	cout << "Zawartosc zmiennej 1 = " << txt1 << endl;
	cout << "Zawartosc zmiennej 2 = " << txt2 << endl;
	cout << "Rozmiar buforu 1 = " << sizeof(buffer1) << endl;
	cout << "Rozmiar buforu 2 = " << BUFFER_SIZE << endl;
	cout << "Rozmiar zmiennej 1 = " << strlen(buffer1) + 1 << endl;
	cout << "Rozmiar zmiennej 2 = " << strlen(buffer2) + 1 << endl;
	
	
	delete [] buffer2;
	delete [] txt1;
	delete [] txt2;
	
	return 0;
}