// dzial 7 strona 301

#include <iostream>
using namespace std;

int sum_ar(const int BEGIN[], const int END[]);

const int AR_SIZE = 8;

int main()
{
	int cookies[] = {1,2,4,8,16,32,64,128};
	int sum = 0;
	
	sum = sum_ar(cookies, cookies + AR_SIZE);
	cout << "Zjedzono " << sum << " ciasteczek.\n";
	
	sum = sum_ar(cookies, cookies + 3);
	cout << "Pierwszych trzech zjadlo " << sum << " ciasteczek.\n";
	
	sum = sum_ar(cookies + AR_SIZE - 2, cookies + AR_SIZE);
	cout << "Ostatnich dwoch znadlo " << sum << " ciasteczek.\n";
	
}

int sum_ar(const int begin[], const int end[])
{
	const int * pt;
	int total = 0;
	
	for (pt = begin; pt != end; pt++)
	{
		total += *pt;
	}
	
	return total;
}