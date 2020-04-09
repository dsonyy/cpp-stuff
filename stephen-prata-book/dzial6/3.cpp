#include <iostream>
#include <array>
using namespace std;

const int AR_SIZE = 10;

int main()
{
	char choice;
	
	cout << "=== MENU GLOWNE ===\n";
	cout << " Nowa gra\n";
	cout << " Instrukcja\n";
	cout << " Opcje\n";
	cout << " Wyjscie\n";
	cout << "\n [i] podaj pierwsza\n     litere\n";
	cout << "===================\n";
	do
	{
		cin.get(choice);
		switch (choice)
		{
			case 'n':
			case 'N':
				cout << "tutaj kiedys bedzie gra\n";
				break;
			case 'i':
			case 'I':
				cout << "kto czyta instrukcje lol\n";
				break;
			case 'o':
			case 'O':
				cout << "nie ma jeszcze\n";
				break;
			case 'w':
			case 'W':
				cout << "Dowidzenia\n";
				break;
			default:
				cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
				choice = 0;
				while (cin.get() != '\n')
					continue;
				break;
		}
	} while (!cin.good() || choice == 0);
	
	
}