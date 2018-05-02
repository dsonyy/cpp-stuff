#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	double wages[3] = {1000.0, 2000.0, 3000.0};
	short stacks[3] = {3, 2, 1};
	
	double * pd = wages;
	short * ps = &stacks[0];
	
	cout << "pd = " << pd << "     *pd = " << *pd << endl;
	cout << "Dodanie do wskaznika pd 1\n";
	pd += 1;
	cout << "pd = " << pd << "     *pd = " << *pd << endl;

	cout << "ps = " << ps << "     *ps = " << *ps << endl;
	cout << "Dodanie do wskaznika ps 1\n";
	ps += 1;
	cout << "ps = " << ps << "     *ps = " << *ps << endl;
	
	
	return 0;
}