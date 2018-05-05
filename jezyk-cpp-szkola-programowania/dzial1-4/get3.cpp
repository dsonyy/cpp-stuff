#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	int year;
	char address[80];
	
	cout << "How old is your house?\n";
	(cin >> year).get(); 								// cin is waiting for int, so it never get the new line char
	cout << "What's your home address?\n";
	cin.getline(address, 80);
	
	cout << "Year:       " << year << endl;
	cout << "Address: " << address << endl;
	cout << "Goodbye!\n";
	
	return 0;
}