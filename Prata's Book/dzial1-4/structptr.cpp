#include <iostream>
using namespace std;

int main()
{
	struct tiger
	{
		int val;
	};
	
	tiger t { 12 };
	cout << "Utworzono strukture. Zmienna w strukturze jest rowna " << t.val << endl;
	tiger * pt = &t;
	cout << "Utworzono wskaznik do tej struktury. Adres wskaznika to " << &pt << endl;
	tiger tab[3] = {12,32,76};
	cout << "Utworzono tablice struktur." << endl;
	cout << "Zmienne tych struktur to "
		 << tab[0].val << ", "
		 << tab[1].val << ", "
		 << tab[2].val << ".\n";
	tiger *ptab = &tab[0];
	cout << "Utworzono wskaznik na tablice struktur. Adres wskaznika to " << &ptab << endl;
	cout << "Zmienna struktury wskazywanej przez ten wskaznik to " << ptab->val << endl;
	cout << "Zmienna za wskazywana wartoscia to " << (ptab+1)->val << endl;
	return 0;
}