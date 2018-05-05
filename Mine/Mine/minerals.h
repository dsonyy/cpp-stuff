// minerals.h -- data about minerals used in game
#pragma once
#include <string>
#include <vector>
#include "error.h"


// basic structure containing common informations about minerals
struct MineralType
{
	std::string name = "";
	double rarity = 0.0;

	bool operator==(const MineralType & other_mineral_type) const
	{
		if (other_mineral_type.name == name &&
			other_mineral_type.rarity == rarity)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};


// represents specific portion of mineral and its total weight
struct Mineral
{
	MineralType type = {};
	double weight;
};


// container storing specific kinds of minerals and their weigth
class MineralsContainer
{
public:
	// functions that return the most common minerals
	static const MineralType & Coal()		{ static MineralType coal		= { "coal", 30.0 };		return coal; }
	static const MineralType & Iron()		{ static MineralType iron		= { "iron", 20.0 };		return iron; }
	static const MineralType & Copper()		{ static MineralType copper		= { "copper", 25.0 };	return copper; }
	static const MineralType & Halite()		{ static MineralType halite		= { "halite", 25.0 };	return halite; }
	static const MineralType & Gold()		{ static MineralType gold		= { "gold", 5.0 };		return gold; }
	static const MineralType & Diamiond()	{ static MineralType diamond	= { "diamond", 1.0 };	return diamond; }

	error_code Give(const MineralType & mineral, double weigth);
	error_code Take(const MineralType & mineral, double weigth);
	error_code Empty();
	error_code Empty(const MineralType & mineral);

	error_code GetWeight(const MineralType & mineral, double * weight);
	error_code SetWeight(const MineralType & mineral, double new_weight);

private:
	std::vector<Mineral>::iterator Find(const MineralType & mineral);

	std::vector<Mineral> content;

};
