#include <iostream>
using namespace std;

int main()
{
	char ch;
	int count = 0;
	
	while (cin.get(ch))
	{
		cout.put(ch);
		++count;
	}
	cout << endl << "wczytano " << count << " znakow.\n";
	return 0;
}