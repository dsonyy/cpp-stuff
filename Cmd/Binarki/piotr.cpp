#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string czamu;
	string wiara;
	string imie;
	int ocena;

	cout << " ... Otwieraj¥ si© przeogromne l˜ni¥ce bramy niebios i ˜wi©ta Posta† pod¥¾a w Twoja stron©.\n Podnosi Sw¢j ˜wi©ty lecz surowy gˆos i m¢wi:\n"
		<< " Witej synu - czy tam c¢rko - po co ¾e˜ to zalos?\n";
	getline(cin, czamu);
	cout << " Super... A jakiej ¾e˜ je wiary? Wierzysz ty w co˜ w og¢le?\n";
	getline(cin, wiara);
	cout << " Nie wa¾ne... Jak mosz na imi©?\n";
	getline(cin, imie);
	cout << " Co za durne imie, Dobre, jo musza lecie†, bo mom objawienie za 10 minut\n Sˆuchej teraz, jak by˜ se swoje ¾ycie oceniˆ w skali od 1 do 10?";
	cin >> ocena;
	if (ocena == 10)
		cout << " Ta   jasne. Dobra ola† to, witomy w niebie. Czuj si© jak u...   jak w niebie...\n";
	else if (ocena < 4)
		cout << " A to spierda... znaczy to tyra† na d¢ˆ musisz bo tukej cie nie moga p¢˜ci†.\n";
	else if (ocena > 10)
		cout << " Ja... kolejny '˜wi©ty'. Tela tych ˜wi©tych tu momy zeby sie nikt nie nudziˆ przez ta 'wieczno˜†'. Mo¾na si© do ka¾dego z osobna modli†.\n";
	else
		cout << " Witamy w niebie, pok¢j numer 666 przy ko˜ciele imienia Naj˜wi©tszej yyy...   Marii Panny. Miˆej zabawy\n";

	if (ocena > 3)
	cout << "... Po tej wizycie maˆy tˆu˜ciutki anioˆek podlatuje do ciebie i wr©cza ci Dow¢d Niebieski oraz kluczyki do pokoju 666.\n"
		<< "\n DOWàD NIEBIESKI\n"
		<< " Imi©:      " << imie << "\n"
		<< " Nazwisko:  gjhghgj\n"
		<< " 2gie imi©: fdhdf\n"
		<< " 3cie imi©: kokkkklmkj\n"
		<< " 4te imi©:  ffd\n"
		<< " Imi© ojca: twoja stara XDDDDD\n"
		<< " Imi© matki: ...chodzi do kina z pilotem xDD\n"
		<< " Imi© ojca chrzestnego: Andrzej z Goˆkowic\n"
		<< " Imi© matki chrzestnej: And¾ela z Jankowic\n"
		<< " Imi©... znaczy data urodzenia: 1.1.1969\n"
		<< " Adres zamieszkania: niebo, Bog¢w, Miˆowa 69/666\n"
		<< " Informacje dodatkowe: jak co to pytak Bodzia Ojca Wsze... bla bla\n"
		<< " aa i jakby˜ widzioˆ dup.. du¾y dym czorny albo bioˆy to nie sraj ¾arem, bo papie¾a wybieraj¥\n "
		<< " Wydawca dowodu: Szymon Pioter I Dupny\n";
	
	system("pause");
    return 0;
}

