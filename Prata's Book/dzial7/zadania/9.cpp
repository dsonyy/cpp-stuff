#include <iostream>
using namespace std;

const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student [], int);

void display1(student);
void display2(const student *);
void display3(const student [], int);

int main()
{
	int class_size;
	
	cout << "Podaj wielkosc grupy: ";
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student * ptr_stu = new student [class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Gotowe!\n";
	return 0;
}

int getinfo(student pa [], int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		cout << "Podaj imie studenta " << i + 1 << ": ";
		cin >> pa[i].fullname;
		while (cin.get() != '\n')
			continue;
		
		cout << "Podaj hobby studenta " << i + 1 << ": ";
		cin >> pa[i].hobby;
		while (cin.get() != '\n')
			continue;
		
		cout << "Podaj ooplevel studenta " << i + 1 << ": ";
		cin >> pa[i].ooplevel;
		while (cin.get() != '\n')
			continue;
	}
	
	return i;
}

void display1(student pa)
{
	cout << "> STUDENT\n";
	cout << ">> imie:     " << pa.fullname << endl;
	cout << ">> hobby:    " << pa.hobby << endl;
	cout << ">> ooplevel: " << pa.ooplevel << endl;
}

void display2(const student * pa)
{
	cout << "> STUDENT\n";
	cout << ">> imie:     " << pa->fullname << endl;
	cout << ">> hobby:    " << pa->hobby << endl;
	cout << ">> ooplevel: " << pa->ooplevel << endl;
}

void display3(const student pa[], int num)
{
	for (int i = 0; i < num; i++)
	{
		display2(&pa[i]);
	}
}
