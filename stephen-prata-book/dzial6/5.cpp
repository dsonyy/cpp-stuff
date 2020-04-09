#include <iostream>
using namespace std;

const float TAX[4] = {0.0, 0.1, 0.15, 0.2};
const int THRESHOLD[4] = {5000, 10000, 20000, 35000};

int main()
{
	float twarps;
	float tax = 0.0;
	
	cout << "Ile twarpow zarabiasz?\n";
	cin >> twarps;
	while (!cin || twarps < 0)
	{
		cout << "Co?\n";
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cin >> twarps;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (twarps >= THRESHOLD[i])
		{
			tax += TAX[i] * THRESHOLD[i];
			twarps -= THRESHOLD[i];
		}
		else if (twarps > 0)
		{
			tax += TAX[i] * twarps;
		}
			
	}
	cout << "Podatek wynosi " << tax << " twerpow.\n";
	
	return 0;
}