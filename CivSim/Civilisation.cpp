#include "Civilisation.h"

Civilisation::Civilisation()
{
	this->res = new Resources();
}

Civilisation::~Civilisation()
{
	delete res;
}

int Civilisation::calculateTotalGatherers(int& woodGatherers, int& foodGatherers, int& stoneGatherers, int& Miners, int& Minters)
{
	totalGatherers = woodGatherers + foodGatherers + stoneGatherers + Miners + Minters;
	return totalGatherers;
}

std::tuple<float, float, float, float, float> Civilisation::calculateModifiers(int& farmTotal, int& timberyardTotal, int& quarryTotal, int& mineTotal, int& mintTotal)
{
	if (upgrade2)
	{
		foodModifier = farmTotal / 2;
	}
	else
	{
		foodModifier = farmTotal / 3;
	}

	if (upgrade3)
	{
		woodModifier = timberyardTotal / 2;
	}
	else
	{
		woodModifier = timberyardTotal / 3;
	}

	stoneModifier = quarryTotal / 3;
	metalModifier = mineTotal / 3;
	coinModifier = mintTotal / 3;
	return std::make_tuple(foodModifier, woodModifier, stoneModifier, metalModifier, coinModifier);
}

int Civilisation::calculatePopCap(int& houseTotal, int& popCap)
{
	if (upgrade1)
	{
		popCap = houseTotal * 7;
	}
	else
	{
		popCap = houseTotal * 5;
	}

	return popCap;
}

std::string Civilisation::settleSize(std::string& type, int houseTotal, int farmTotal, int timberyardTotal, int quarryTotal, int mineTotal, int mintTotal)
{
	if (houseTotal >= 10 && farmTotal == 1)
	{
		type = "Town";
	}
	else if (houseTotal >= 20 && farmTotal == 3 && timberyardTotal == 1)
	{
		type = "City";
	}
	else if (houseTotal >= 50 && farmTotal == 8 && timberyardTotal == 3 && Population >= 100)
	{
		type = "County";
	}

	return type;
}