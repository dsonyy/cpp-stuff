#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char ** argv)
{
	char ch[20];
	string str;
	
	cout << "Dlugosc lancucha zmiennej char przed wprowadzeniem danych: "
			<< strlen(ch) << endl;
	cout << "Dlugosc lancucha zmiennej string przed wprowadzeniem danych: "
			<< str.size() << endl;
	cout << "Wprowadzanie danych do zmiennej char:" << endl;
	cin.getline(ch, 20);
	cout << "Wprowadzanie danych do zmiennej string:" << endl;
	getline(cin, str);
	cout << "Dlugosc lancucha zmiennej char wynosi teraz: "
			<< strlen(ch) << endl;
	cout << "Dlugosc lancucha zmiennej string wynosi teraz: "
			<< str.size() << endl;
	
	
	return 0;
}