#include <iostream>
using namespace std;

const int STR_SIZE = 30;

enum V {name, nick, place};

struct zpdw
{
	char name[STR_SIZE];
	char nick[STR_SIZE];
	char place[STR_SIZE];
	V prefereces;
};

int main()
{
	char choice = 0;
	zpdw user[4]
	{
		{"Szymon Bednorz", "dsony", "1st degree initiation", nick},
		{"Oliwier Oliwier", "hax4dev", "2nd degree initiation", name},
		{"Ahab Ahl Ablahull", "a3", "4th degree initiation", place},
		{"Dadly Ahmed", "???", "janitor", place}
	};
	
	cout << "ZAKON PROGRAMISTOW DOBREJ WOLI\n";
	cout << "a. lista wg imion\n";
	cout << "b. lista wg stanowisk\n";
	cout << "c. lista wg pseudonimow\n";
	cout << "d. lista wg preferencji\n";
	cout << "q. koniec\n";
	while (!cin.good() || choice != 'q')
	{
		cin.get(choice);
		switch (choice)
		{
			case 'a':
				cout << "Lista wg imion:\n";
				for (int i = 0; i < 4; ++i)
					cout << user[i].name << endl;
				break;
			case 'b':
				cout << "Lista wg stanowisk:\n";
				for (int i = 0; i < 4; ++i)
					cout << user[i].place << endl;
				break;
			case 'c':
				cout << "Lista wg pseudonimow:\n";
				for (int i = 0; i < 4; ++i)
					cout << user[i].nick << endl;
				break;
			case 'd':
				cout << "Lista wg preferencji:\n";
				for (int i = 0; i < 4; ++i)
					if (user[i].prefereces == name)
						cout << user[i].name << endl;
					else if (user[i].prefereces == nick)
						cout << user[i].nick << endl;
					else if (user[i].prefereces == place)
						cout << user[i].place << endl;
				break;
			case 'q':
				return 0;
			default:
				cout << "Nieprawidlowe wejscie.\n";
				cin.clear();
				choice = 0;
				break;
		}
		while (cin.get() != '\n')
			continue;
	}

	return 0;
}