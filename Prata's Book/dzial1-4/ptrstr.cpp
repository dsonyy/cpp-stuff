#include <iostream>
using namespace std;

int main()
{
	char animal[] = "niedzwiedz";
	const char * bird = "orzel";
	char * ptr;
	
	cout << animal << endl;
	cout << bird << endl;
	cout << ptr << endl;
	
	ptr = new char [20];
	cout << "Podaj nazwe zwierzecia.\n";
	cin >> ptr;
	
	cout << endl << "zmienna animal = " << animal << endl;
	cout << "zmienna bird   = " << bird << endl;
	cout << "zmienna ptr    = " << ptr << endl;
	
	return 0;
}