#pragma once
#include "Button.h"

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

	int calculateIdle(int& Population, int& totalGatherers, int& IdlePop);

	float foodConsump(float& Food, int Population);

	void userInput();

	void populateButtonVec();

	std::vector<Button> Main;
	std::vector<Button> Game;
	std::vector<Button> Help;
	std::vector<Button> Build;
	std::vector<Button> Upgrade;
	std::vector<Button> Achieve;
	std::vector<Button> Credit;
	std::vector<Button> Option;

	std::vector<Label> labels;

protected:

	bool OnUserCreate();

	bool OnUserUpdate(float fElapsedTime);

	
	//Options bools
	bool backSelected = false;

	//GameScreen bools
	bool helpSelected = false;
	bool buildSelected = false;
	bool upgrSelected = false;
	bool achieveSelected = false;
	bool creditSelected = false;

	//Upgrade bools
	


	//Back bools
	bool hBackselected = false;
	bool bBackselected = false;
	bool uBackselected = false;
	bool aBackselected = false;
	bool cBackselected = false;

	int	GameState = MainMenu;

	Civilisation* civ = nullptr;

	//Resources
	

	//Buildings
	


	
	

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

