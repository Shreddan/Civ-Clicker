#pragma once
#include "olcPixelGameEngine.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <tuple>

class Engine : public olc::PixelGameEngine
{
	enum State
	{
		MainMenu,
		GameScreen,
		PauseMenu,
		Options,
		HelpScreen,
		BuildingScreen,
		Upgrades,
		Acheivements,
		Credits
	};

public:
	Engine();
	~Engine();

	std::string settleSize(std::string& type, int houseTotal, int farmTotal, int timberyardTotal, int quarryTotal, int mineTotal, int mintTotal);

	void checkAchievements(int& alpha1, int& alpha2, int& alpha3, int& alpha4, std::string& achieve, float& alpha0, bool& anotherHouseComplete, bool& farmHandComplete, bool& timberrrComplete, bool& expansionComplete);

	std::tuple<float, float, float, float, float> resAccum(float& Wood, float& Food, float& Stone, float& Metal, float& Coin);

	std::tuple<float, float, float, float, float> gatherRates(float& woodGatherRate, float& foodGatherRate, float& stoneGatherRate, float& metalGatherRate, float& coinGatherRate, int woodGatherers, int foodGatherers, int stoneGatherers, int Miners, int Minters, float woodModifier, float foodModifier, float stoneModifier, float metalModifier, float coinModifier);

	int TickSystem(float& tick, int Population, float& fElapsedTime, int& gameTick, float& woodGatherRate, float& foodGatherRate, float& stoneGatherRate, float& metalGatherRate, float& coinGatherRate, float& Wood, float& Food, float& Stone, float& Metal, float& Coin, int woodGatherers, int foodGatherers, int stoneGatherers, int Miners, int Minters, float woodModifier, float foodModifier, float stoneModifier, float metalModifier, float coinModifier);

	int PopTickSystem(int& gameTick, int& PopTick, int& Population, int& popInc, float& Food, int& IdlePop, int& popCap);

	std::string ftos(float f);

	int calculateTotalGatherers(int& woodGatherers, int& foodGatherers, int& stoneGatherers, int& Miners, int& Minters);

	int calculateIdle(int& Population, int& totalGatherers, int& IdlePop);

	int calculatePopCap(int& houseTotal, int& popCap);

	float foodConsump(float& Food, int Population);

	std::tuple<float, float, float, float, float> calculateModifiers(int& farmTotal, int& timberyardTotal, int& quarryTotal, int& mineTotal, int& mintTotal);

	void userInput();

protected:

	bool OnUserCreate();

	bool OnUserUpdate(float fElapsedTime);

	//MainMenu bools
	bool startSelected = false;
	bool optionsSelected = false;
	bool quitSelected = false;

	//Options bools
	bool backSelected = false;

	//GameScreen bools
	bool helpSelected = false;
	bool buildSelected = false;
	bool upgrSelected = false;
	bool achieveSelected = false;
	bool creditSelected = false;

	//Upgrade bools
	bool upgrade1 = false;
	bool upgrade2 = false;
	bool upgrade3 = false;


	//Back bools
	bool hBackselected = false;
	bool bBackselected = false;
	bool uBackselected = false;
	bool aBackselected = false;
	bool cBackselected = false;

	int	GameState = MainMenu;

	std::string type = "Village";

	//Population Variables
	int Population = 5;
	int popInc = 0;

	//Resources
	float Wood = 0.0f;
	int woodGatherers = 0;
	float woodGatherRate = 0;
	float Food = 0.0f;
	int foodGatherers = 0;
	float foodGatherRate = 0;
	float Stone = 0.0f;
	int stoneGatherers = 0;
	float stoneGatherRate = 0;
	float Metal = 0.0f;
	int Miners = 0;
	float metalGatherRate = 0;
	float Coin = 0.0f;
	int Minters = 0;
	float coinGatherRate = 0.0f;

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

	//Tick Variables
	int gameTick = 0;
	int PopTick = 0;
	float tick = 0.0f;

	//Achievement
	std::string achieve;
	std::string achieve1 = "Another House!";
	std::string achieve2 = "Dabbling Farmer!";
	std::string achieve3 = "Timberrrr!";
	std::string achieve4 = "Expansion!";
	bool anotherHouseComplete = false;
	bool farmHandComplete = false;
	bool timberrrComplete = false;
	bool expansionComplete = false;
	float alpha0 = 1.0f;
	float timeToFade = 3;
	int alpha1 = 0;
	int alpha2 = 0;
	int alpha3 = 0;
	int alpha4 = 0;

};

