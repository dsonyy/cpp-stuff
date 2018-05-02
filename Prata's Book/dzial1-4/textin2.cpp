#include <iostream>
using namespace std;

int main()
{
	int ch;
	int count = 0;
	
	while ((ch = cin.get()) != -1)
	{
		cout.put(ch);
		++count;
	}
	cout << endl << "wczytano " << count << " znakow.\n";
	return 0;
}