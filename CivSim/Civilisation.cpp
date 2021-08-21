#include "Civilisation.h"

Civilisation::Civilisation()
{
	this->res = new Resources();
}

Civilisation::~Civilisation()
{
	delete res;
}

int Civilisation::calculateTotalGatherers()
{
	this->totalGatherers = this->woodGatherers + this->foodGatherers + this->stoneGatherers + this->Miners + this->Minters;
	return totalGatherers;
}

std::tuple<float, float, float, float, float> Civilisation::calculateModifiers()
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

int Civilisation::calculatePopCap()
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

std::string Civilisation::settleSize()
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

int Civilisation::calculateIdle()
{
	IdlePop = Population - totalGatherers;
	return IdlePop;
}
float Civilisation::foodConsump()
{
	res->Food -= Population / 5;

	return res->Food;
}