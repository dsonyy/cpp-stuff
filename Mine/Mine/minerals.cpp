// minerals.cpp
#include <algorithm>
#include "minerals.h"
#include "error.h"

error_code MineralsContainer::Give(const MineralType & mineral, double weight)
{
	auto existing_mineral = Find(mineral);

	if (existing_mineral == content.end())
	{
		content.push_back({ mineral, weight });
	}
	else
	{
		existing_mineral->weight += weight;
	}

	return NO_ERRORS;
}


error_code MineralsContainer::Take(const MineralType & mineral, double weight)
{
	auto existing_mineral = Find(mineral);

	if (existing_mineral == content.end()) return ERROR_UNKNOWN_RESOURCE;

	if (existing_mineral->weight < weight) return ERROR_TOO_FEW_RESOURCES;

	existing_mineral->weight -= weight;

	return NO_ERRORS;
}


error_code MineralsContainer::Empty(const MineralType & mineral)
{
	auto existing_mineral = Find(mineral);

	if (existing_mineral == content.end()) return ERROR_UNKNOWN_RESOURCE;

	content.erase(existing_mineral);

	return NO_ERRORS;
}


error_code MineralsContainer::Empty()
{
	content.clear();

	return NO_ERRORS;
}


error_code MineralsContainer::GetWeight(const MineralType & mineral, double * weight) 
{

	auto existing_mineral = Find(mineral);

	if (existing_mineral == content.end()) return ERROR_UNKNOWN_RESOURCE;

	*weight = existing_mineral->weight;

	return NO_ERRORS;
}


error_code MineralsContainer::SetWeight(const MineralType & mineral, double weight)
{
	auto existing_mineral = Find(mineral);

	if (existing_mineral == content.end())
	{
		content.push_back({ mineral, weight });
		existing_mineral = content.end() - 1;
	}

	existing_mineral->weight = weight;

	return NO_ERRORS;
}

std::vector<Mineral>::iterator MineralsContainer::Find(const MineralType & mineral)
{
	if (!content.empty())
	{
		for (auto it = content.begin(); it < content.end(); ++it)
		{
			if (it->type == mineral)
			{
				return it;
			}
		}
	}

	return content.end();
}