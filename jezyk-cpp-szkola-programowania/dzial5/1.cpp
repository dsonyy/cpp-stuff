#include <iostream>
using namespace std;

int main()
{
	int a, b, count = 0;
	
	cout << "Podaj liczbe #1.\n";
	cin >> a;
	cout << "Podaj liczbe #2 - wieksza od poprzedniej.\n";
	cin >> b;
	cout << "Ok, program poda sume liczb calkowytych od "
		 << a << " do " << b << ".\n";
	
	for (;a <= b;++a)
		count += a;
	
	cout << "Gotowe! Jest to " << count << "!\n";
	return 0;
}