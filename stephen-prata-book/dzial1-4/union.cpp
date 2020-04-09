#include <iostream>

using namespace std;

union one4all
{
	int int_val;
	long long_val;
	double double_val;
};

int main(int argc, char ** argv)
{
	one4all stuff;
	stuff.int_val = 34;
	cout << stuff.int_val << " - to jest int"<<endl;
	stuff.double_val = 106.03;
	cout << stuff.double_val << " - teraz to double, a inta juz nie ma :(" << endl;
	
	return 0;
}