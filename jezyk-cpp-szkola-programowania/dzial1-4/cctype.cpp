#include <iostream>
#include <cctype>
using namespace std;

int main()
{
  char ch;

  cout << "== Prezentacja biblioteki cctype ==\n\n";
  cout << " Podaj jakis znak.\n";
  cin.get(ch);
  while (!cin)
  {
	  cin.clear();
	  while (cin.get() != '\n')
		  continue;
	  cout << "Hej! Nieprawidlowe wejscie, sproboj ponownie.\n";
	  cin.get(ch);
  }
  while (cin.get() != '\n')
	  continue;
  cout << "\nHmm...\n";
  if (isalnum(ch)) cout << "Jest to znak alfanumeryczny.\n";
  else			   cout << "Nie jest to znak alfanumeryczny.\n";
  if (isalpha(ch)) cout << "Jest to litera.\n";
  else			   cout << "Nie jest to litera.\n";
  if (isblank(ch)) cout << "Jest to spacja lub tabluator.\n";
  else 			   cout << "Nie jest to spacja lub tabulator.\n";
  if (iscntrl(ch)) cout << "Jest to znak sterujacy.\n";
  else			   cout << "Nie jest to znak sterujacy.\n";
  if (isdigit(ch)) cout << "Jest to cyfra.\n";
  else 			   cout << "Nie jest to cyfra.\n";
  if (isgraph(ch)) cout << "Jest to znak drukowalny inny niz spacja.\n";
  else			   cout << "Nie jest to znak drukowalny.\n";
  if (islower(ch)) cout << "Jest to mala litera.\n";
  else			   cout << "Nie jest to mala litera.\n";
  if (isprint(ch)) cout << "Jest to znak drukowalny lub jest to spacja.\n";
  else 			   cout << "Nie jest to znak drukowalny, ani nie jest to spacja.\n";
  if (ispunct(ch)) cout << "Jest to znak przestankowy.\n";
  else 			   cout << "Nie jest to znak przestankowy.\n";
  if (isspace(ch)) cout << "Jest to znak bialy.\n";
  else			   cout << "Nie jest to znak bialy.\n";
  if (isupper(ch)) cout << "Jest to wielka litera.\n";
  else			   cout << "Nie jest to wielka litera.\n";
  if (isxdigit(ch))cout << "Jest to liczba szesnastkowa.\n";
  else 			   cout << "Nie jest to liczba szesnastkowa.\n";
  cout << "Jest to " << ch << endl;


  return 0;
}
