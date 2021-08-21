#pragma once
#include "Button.h"
#include "Achievement.h"
#include <discord.h>

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
		Achievements,
		Credits
	};

public:
	Engine();
	~Engine();

	int TickSystem(float& tick, int Population, float& fElapsedTime, int& gameTick, float& woodGatherRate, float& foodGatherRate, float& stoneGatherRate, float& metalGatherRate, float& coinGatherRate, float& Wood, float& Food, float& Stone, float& Metal, float& Coin, int woodGatherers, int foodGatherers, int stoneGatherers, int Miners, int Minters, float woodModifier, float foodModifier, float stoneModifier, float metalModifier, float coinModifier);

	int PopTickSystem(int& gameTick, int& PopTick, int& Population, int& popInc, float& Food, int& IdlePop, int& popCap);

	void userInput(int& ID);

	//void userInput();

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

	int	GameState = MainMenu;

	Civilisation* civ = nullptr;
	Achievement* ach = nullptr;
	discord::Core* core = nullptr;

	//Tick Variables
	int gameTick = 0;
	int PopTick = 0;
	float tick = 0.0f;

	//Achievement
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

