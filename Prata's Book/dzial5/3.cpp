#include <iostream>
using namespace std;

int main()
{
	int num;
	int count = 0;
	cout << "Podawaj liczby.\n";
	while (1)
	{
		cin >> num;
		count += num;
		cout << "Suma liczb to " << count << endl;
		if (num == 0) break;
	}
	return 0;
}