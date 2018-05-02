#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char ** argv)
{
	const int SIZE = 15;
	char name1[SIZE];
	char name2[SIZE] = "C++boy";
	
	cout << "Hey, how are you! I'm " << name2
			<< "! And what's your name?\n";
	cin >> name1;
	while (!cin)
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Huh!?\n";
		cin >> name1;
	}
	cout << "OK, " << name1 << ", this name has "
			<< strlen(name1) << " letters\nand is saved in "
			<< sizeof(name1) << " Bytes array.\n";
	cout << "Your initial is " << name1[0] << ".\n";
	
	name2[3] = '\0';
	cout << "First 3 letters of my name are: " << name2 << endl;
	cout << "Goodbye ;)";
	
	return 0;
}