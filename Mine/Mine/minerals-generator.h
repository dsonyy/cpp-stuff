// minerals-generator.h --
#pragma once
#include <cstdlib>
#include "minerals.h"


class MineralsGenerator
{
public:

	static MineralsContainer GetRoomMinerals(double difficulty);
	static MineralsContainer GetChestMinerals(double difficulty);

	static const size_t Min_resources_number = 6;
	static const size_t Max_resources_number = 10;

//private:
	static size_t GetNumberOfResources(double difficulty);
};
