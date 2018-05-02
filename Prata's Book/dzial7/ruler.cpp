// dzial 7 strona 324
// ruler.cpp -- uzycie rekurencji do dzielenia linijki
#include <iostream>

using namespace std;

void subDivide(char[], int, int, int);

const int LENGHT = 66;
const int DIVS = 6;

int main()
{
	char ruler[LENGHT];
	int min = 0;
	int max = LENGHT - 2;
	int i;
	
	for (i = 1; i < LENGHT - 2; ++i)
	{
		ruler[i] = ' ';
	}
	ruler[LENGHT - 1] = '\0';
	
	ruler[min] = ruler[max] = '|';
	cout << ruler << endl;
	for (i = 1; i <= DIVS; ++i)
	{
		subDivide(ruler,min,max,i);
		cout << ruler << endl;
		for (int j = 1; j < LENGHT - 2; j++)
			ruler[j] = ' ';
	}
	
	return 0;
}

void subDivide(char ar[], int low, int high, int level)
{
	if (level == 0)
		return;
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subDivide(ar,low,mid,level - 1);
	subDivide(ar,mid,high,level -1);
}