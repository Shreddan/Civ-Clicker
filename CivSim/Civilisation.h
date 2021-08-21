#pragma once

#include "Resources.h"




class Civilisation
{
public:
	Civilisation();
	~Civilisation();

	int calculateTotalGatherers();

	std::tuple<float, float, float, float, float> calculateModifiers();

	int calculatePopCap();

	std::string settleSize();

	int calculateIdle();

	float foodConsump();

	Resources* res = nullptr;

	std::string type = "Village";

	//Population Variables
	int Population = 5;
	int popInc = 0;

	//Workers
	int woodGatherers = 0;
	int foodGatherers = 0;
	int stoneGatherers = 0;
	int Miners = 0;
	int Minters = 0;

	//Buildings
	int houseTotal = 1;
	int farmTotal = 0;
	int timberyardTotal = 0;
	int quarryTotal = 0;
	int mineTotal = 0;
	int mintTotal = 0;

	//Modifiers
	float foodModifier = farmTotal / 4;
	float woodModifier = timberyardTotal / 4;
	float stoneModifier = quarryTotal / 4;
	float metalModifier = mineTotal / 4;
	float coinModifier = mintTotal / 4;
	int popCap = houseTotal * 5;
	int totalGatherers = woodGatherers + foodGatherers + stoneGatherers;
	int IdlePop = Population - totalGatherers;

	bool upgrade1 = false;
	bool upgrade2 = false;
	bool upgrade3 = false;
};
