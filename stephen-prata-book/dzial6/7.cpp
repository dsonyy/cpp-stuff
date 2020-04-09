#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const char vowel[] = {'a','e','i','o','u','y'};

int main()
{
	char tab[50] = "";
	int vowels = 0;
	int consonants = 0;
	int count = 0;
	
	cout << "Podawaj slowa, kiedy skonczysz napisz 'q'.\n";
	cin >> tab;
	while (strcmp(tab, "q") != 0)
	{
		if (isalpha(tab[0]))
		{
			for (int j = 0; j < sizeof(vowel); ++j)
			{
				if (tab[0] == vowel[j])
				{
					vowels++;
					break;
				}
				else if (j == sizeof(vowel) - 1)
					consonants++;
			}
		}
		cin >> tab;
		count++;
	}
	cout << "Podano " << count << " slow.\n";
	cout << "Podano " << vowels << " slow zaczynajacych sie na samogloske.\n";
	cout << "Podano " << consonants << " slow zaczynajacych sie na spolgloske.\n";
	cout << "Podano " << count - vowels - consonants << " slow zaczynajacych sie na cos innego.\n";
	
	
	return 0;
}