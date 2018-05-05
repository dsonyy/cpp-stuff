#include <iostream>
using namespace std;

int main()
{
	const char * tab = "elo elo";
	
	cout << tab << endl;
	cout << (*tab)[2] << endl;
	cout << &tab << endl;

	return 0;
}