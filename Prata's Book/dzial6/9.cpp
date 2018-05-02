#include <iostream>
#include <fstream>
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
	ifstream fin("do9");

	fin >> donatorsNum;
	if (!fin)
	{
		cout << "Blad podczas odczytywanie liczby sponsorow.\n";
		return -1;
	}
	donator = new Donator [donatorsNum];
	for (int i = 0; i < donatorsNum; ++i)
	{
		fin.get();
		fin.get(donator[i].surname, 20);
		if (!fin)
		{
			cout << "Blad podczas odczytywanie sponsora " << i << ".\n";
			return -1;
		}
		fin >> donator[i].donate;
		if (!fin)
		{
			cout << "Blad podczas odczytywanie kwoty sponsora " << i << ".\n";
			return -1;
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
	
	fin.close();
	return 0;
}