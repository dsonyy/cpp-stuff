#include <iostream>
using namespace std;

int main()
{
	const char * months[12]
	{
		"Styczen",
		"Luty",
		"Marzec",
		"Kwiecien",
		"Maj",
		"Czerwiec",
		"Lipiec",
		"Sierpien",
		"Wrzesien",
		"Pazdziernik",
		"Listopad",
		"Grudzien"
	};
	int sold[12][3];
	int total = 0;
	
	for (int y = 0; y < 3; ++y)
	{
		cout << "==ROK " << y << "==" << endl;
		for (int i = 0; i < 12; ++i)
		{
			cout << "Podaj liczbe egzemplarzy dla miesiaca: " << months[i] << endl;
			cin >> sold[i][y];
			total += sold[i][y];
		}
	}
	cout << endl << "OK, w sumie sprzedano " << total << " egzemplarzy.\n";
	
	return 0;
}