#include <iostream>
using namespace std;

int main()
{
	char ch;
	
	cout << "Pisz, a ja bede powtarzac.\n";
	cin.get(ch);
	while (ch != '.')
	{
		if (ch == '\n')
			cout << ch;
		else
			cout << ch + 1;
		cin.get(ch);
	}
	cout << "Prosze wybaczyc drobne niedociagnecia ;)\n";
	
	return 0;
}