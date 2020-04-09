#include <iostream>

using namespace std;

struct field
{
	unsigned int number : 4;
	unsigned int : 4;
	bool isGood : 1;
	bool isRight : 1;
};

int main(int argc, char ** argv)
{
	field stuff { 15, true, false };
	
	cout << stuff.number << endl;
	cout << stuff.isGood << endl;
	cout << stuff.isRight << endl;
	
	return 0;
}