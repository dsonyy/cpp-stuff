#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int val, count = 0;
	ifstream fileIn;
	fileIn.open("num.txt");
	
	fileIn >> val;
	while (bool(fileIn))
	{
		++count;
		cout << "number: " << val << endl;
		fileIn >> val;
	}
	cout << "count: " << count << endl;
	
	fileIn.close();
	return 0;
}