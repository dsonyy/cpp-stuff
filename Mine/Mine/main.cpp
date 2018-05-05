#include <iostream>

#include "minerals.h"
#include "minerals-generator.h"

int main(int argc, char ** argv)
{
	int tab[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	for (int x = 0; x < 100000; x++)
	{
		int i = MineralsGenerator::GetNumberOfResources(10);
		tab[i]++;


	}
	std::cout << "------------------------------\n";
	for (int i = 0; i < 20; i++)
	{
		std::cout << i << ": " << tab[i] << "\n";
		if (i >= 1)
		{
			//std::cout << i<< " ~ " << tab[i] - tab[i - 1] << "\n";
		}
	}
	while (1);




	return 0;
}

