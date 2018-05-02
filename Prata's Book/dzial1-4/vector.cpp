#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
	double a1[4] = {1, 43, 7, 11.1221};
	
	vector<double> a2(4);
	a2[0] = 12;
	a2[1] = 1232;
	a2[2] = 45;
	a2[3] = 4;
	
	vector<double> a5{12, 43};
	vector<double> a6 = {0,0};
	a6 = a5;
	
	
	array<double, 4> a3 = {1, 5, 767, 465.65};
	array<double, 4> a4;
	a4 = a3;
	
	return 0;
}