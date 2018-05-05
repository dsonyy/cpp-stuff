#include <iostream>
using namespace std;

struct Donator
{
	char surname[20];
	double donate;
};

int main()
{
	Donator * donator;
	int donatorsNum;
	
	cout << "Podaj liczbe sponsorow.\n";
	cin >> donatorsNum;
	while (!cin)
	{
		cout << "Blad!\n";
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cin >> donatorsNum;
	}
	donator = new Donator [donatorsNum];
	for (int i = 0; i < donatorsNum; ++i)
	{
		cout << "Podaj nazwisko " << i+1 << " sponsora: ";
		cin >> donator[i].surname;
		while (!cin)
		{
			cout << "Blad!\n";
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cin >> donator[i].surname;
		}
		cout << "Podaj kwote: ";
		cin >> donator[i].donate;
		while (!cin)
		{
			cout << "Blad!\n";
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cin >> donator[i].donate;
		}
	}
	cout << "\nNasi wspaniali sponsorzy:\n";
	bool isSponsors = false;
	for (int i = 0; i < donatorsNum; ++i)
	{
		if (donator[i].donate >= 10000)
		{
			cout << donator[i].surname << endl;
			isSponsors = true;
		}
	}
	if (!isSponsors)
		cout << "Brak\n";
	cout << "\nNasi sponsorzy:\n";
	isSponsors = false;
	for (int i = 0; i < donatorsNum; ++i)
	{
		if (donator[i].donate < 10000)
		{
			cout << donator[i].surname << endl;
			isSponsors = true;
		}
	}
	if (!isSponsors)
		cout << "Brak\n";
	
	return 0;
}