#include <iostream>
using namespace std;

int main()
{
	const char * txt = "czy to dziala?";
	cout << &"czy to dziala?" << endl;
	cout << &txt << endl;
	return 0;
}