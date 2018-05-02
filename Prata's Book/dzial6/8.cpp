#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char name[50];
	int count = 0;
	
	cout << "Podaj nazwe pliku:";
	cin.getline(name, 50);
	ifstream fin(name);
	
	fin.get();
	while (fin.good())
	{
		++count;
		fin.get();
	}
	cout << "Znaleziono " << count << " znakow.\n";
	
	fin.close();
	return 0;
}