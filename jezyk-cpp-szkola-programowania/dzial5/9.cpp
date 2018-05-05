#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	int count = 0;
	cout << "Podawaj slowa, kiedy skonczysz napisz 'gotowe'.\n";
	
	cin >> word;
	while (word != "gotowe")
	{
		++count;
		cin >> word;
	}
	cout << "Podano " << count << " slow (chyba).\n";
	
	return 0;
}