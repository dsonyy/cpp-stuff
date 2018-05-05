#include <iostream>
#include <string>
using namespace std;

int main()
{
	int rows;
	
	
	cout << "Podaj liczbe wierszy.\n";
	cin >> rows;
	
	cout << endl;
	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < rows-y; ++x)
		{
			cout << " ";
		}
		for (int x = 0; x < y+1; ++x)
		{
			cout << "*";
		}
		for (int x = 0; x < y; ++x)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}