#include <iostream>
using namespace std;

enum operation {Add, Subtract, Multiply, Divide};

double add(double,double);
double subtract(double,double);
double multiply(double,double);
double divide(double,double);
double calculate(double, double, double (*)(double, double));

int main()
{
	int a = 32, b = 2;
	double (*ptr[4])(double, double) = {add, subtract, multiply, divide};
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "a + b = " << calculate(a,b,ptr[Add]) << endl;
	cout << "a - b = " << calculate(a,b,ptr[Subtract]) << endl;
	cout << "a * b = " << calculate(a,b,ptr[Multiply]) << endl;
	cout << "a / b = " << calculate(a,b,ptr[Divide]) << endl;
}

double calculate(double a, double b , double (*pf)(double, double))
{
	return (pf)(a,b);
}

double add(double a, double b)
{
	return a + b;
}

double subtract(double a, double b)
{
	return a - b;
}

double multiply(double a, double b)
{
	return a * b;
}

double divide(double a, double b)
{
	return a / b;
}