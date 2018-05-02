#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

long long factorial(long long);

int main()
{
	long long n;
	cout << "Podaj n: ";
	cin >> n;
	cout << "Silnia z n = " << factorial(1000LL);
 	return 0;
}

long long factorial(long long a)
{
	if (a == 0LL)
		return 1LL;
	else
		return a * factorial(a - 1LL);
}