#pragma once
#include "Button.h"
#include <discord.h>

struct Achievement
{
	Achievement(std::string name, bool ach) { this->name = name, this->isComplete = ach; }
	std::string name;
	bool isComplete;
};

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

	void checkA(int i);

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

	std::vector<Achievement> ach;

protected:

	bool OnUserCreate();

	bool OnUserUpdate(float fElapsedTime);

	int	GameState = MainMenu;

	Civilisation* civ = nullptr;
	
	discord::Core* core = nullptr;

	//Tick Variables
	int gameTick = 0;
	int PopTick = 0;
	float tick = 0.0f;
};

