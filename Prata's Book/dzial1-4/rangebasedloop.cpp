#include <iostream>
using namespace std;

int main()
{
	double tab[] = {0.11,1,2,3, 4,5,6,7,8,9};
	
	for (double x : tab)
		cout << x << endl;
	
	for (const char * txt : {"czy ", "to ", "zadziala?"})
		cout << txt << endl;
	
	for (const char ch : "A TO DZIALA???")
	{
		cout << ch;
		
		int i = 0;
		while (i < 100000000)
			++i;
	}
	
	return 0;
}