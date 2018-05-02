//arfupt -- tablica wskaznikow do funkcji
// strona 331 dzial 7s

#include <iostream>

const double * f1(const double [], int);
const double * f2(const double *, int);
const double * f3(const double ar[], int n);

int main()
{
	using namespace std;
	double value[3] = {1123.32, 2143.3, 34.001};
	
	
	const double * (*function_pointer1)(const double *, int) = f1;
	auto function_pointer2 = f2;
	
	cout << "Uzywanie wskaznikow do funkcji:\n"
	cout << "\tadres 1: " << *(function_pointer1)(value, 1) << endl;
	cout << "\twartosc zwracana 1: " << (function_pointer1)(value, 1) << endl;
	cout << "\tadres 2: " << *(function_pointer1)(value, 1) << endl;
	cout << "\twartosc zwracana 2: " << (function_pointer2)(value, 2) << endl << endl;
	
	const double * (*function_array_pointer[3])(const double *, int) = {f1, f2, f3};
	auto first_function_pointer = function_array_pointer;
	const double * (*second_function_pointer)(const double *, int) = &function_array_pointer[1];
	
	cout << "Uzywanie tablicy wskaznikow do funkcji:\n"
	cout << "\tadres 1: " << *(function_pointer1)(value, 1) << endl;
	cout << "\twartosc zwracana 1: " << (function_pointer1)(value, 1) << endl;
	
	
	
	return 0;
}