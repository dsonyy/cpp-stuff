// minerals-generator.cpp
#include "minerals-generator.h"
#include <random>
#include <ctime>

MineralsContainer MineralsGenerator::GetRoomMinerals(double difficulty)
{
	MineralsContainer x;
	return x;
}

MineralsContainer MineralsGenerator::GetChestMinerals(double difficulty)
{
	GetNumberOfResources(10);

	MineralsContainer x;
	return x;
}




size_t MineralsGenerator::GetNumberOfResources(double difficulty)
{
	const int n = Max_resources_number - Min_resources_number + 1;

	int prefix[n];
	prefix[0] = 1;
	for (int i = 1; i < n; ++i)
		prefix[i] = prefix[i - 1] + i + 1;

	int r = (rand() % prefix[n - 1]) + 1;

	int mid;
	int l = 0;
	int h = n - 1;
	while (l < h)
	{
		mid = l + ((h - l) >> 1);
		(r > prefix[mid]) ? (l = mid + 1) : (h = mid);
	}

	return (prefix[l] >= r) ? l + Min_resources_number : -1;

}
