#include "Engine.h"

Engine::Engine()
{
	sAppName = "Civ-Clicker";
}

Engine::~Engine()
{
	OnUserDestroy();
}

std::string Engine::settleSize(std::string& type, int houseTotal, int farmTotal, int timberyardTotal, int quarryTotal, int mineTotal, int mintTotal)
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

void Engine::checkAchievements(int& alpha1, int& alpha2, int& alpha3, int& alpha4, std::string& achieve, float& alpha0, bool& anotherHouseComplete, bool& farmHandComplete, bool& timberrrComplete, bool& expansionComplete)
{
	if (!anotherHouseComplete)
	{
		if (houseTotal == 2)
		{
			achieve = achieve1;
			alpha1 = 255;
			alpha0 = 1;
			anotherHouseComplete = true;
		}

	}
	else if (!farmHandComplete)
	{
		if (farmTotal == 1)
		{
			achieve = achieve2;
			alpha2 = 255;
			alpha0 = 1;
			farmHandComplete = true;
		}

	}
	else if (!timberrrComplete)
	{
		if (timberyardTotal == 1)
		{
			achieve = achieve3;
			alpha3 = 255;
			alpha0 = 1;
			timberrrComplete = true;
		}

	}
	else if (!expansionComplete)
	{
		if (type == "Town")
		{
			achieve = achieve4;
			alpha4 = 255;
			alpha0 = 1;
			expansionComplete = true;
		}

	}


}

std::tuple<float, float, float, float, float> Engine::resAccum(float& Wood, float& Food, float& Stone, float& Metal, float& Coin)
{
	Wood += woodGatherRate;
	Food += foodGatherRate;
	Stone += stoneGatherRate;
	Metal += metalGatherRate;
	Coin += coinGatherRate;

	return std::make_tuple(Wood, Food, Stone, Metal, Coin);
}

std::tuple<float, float, float, float, float> Engine::gatherRates(float& woodGatherRate, float& foodGatherRate, float& stoneGatherRate, float& metalGatherRate, float& coinGatherRate, int woodGatherers, int foodGatherers, int stoneGatherers, int Miners, int Minters, float woodModifier, float foodModifier, float stoneModifier, float metalModifier, float coinModifier)
{

	woodGatherRate = woodGatherers * 1.6f + woodModifier;
	foodGatherRate = foodGatherers * 2.2f + foodModifier;
	stoneGatherRate = stoneGatherers * 1.3f + stoneModifier;
	metalGatherRate = Miners * 1.5 + metalModifier;
	coinGatherRate = Minters * 1.1 + coinModifier;
	return std::make_tuple(woodGatherRate, foodGatherRate, stoneGatherRate, metalGatherRate, coinGatherRate);
}

int Engine::TickSystem(float& tick, int Population, float& fElapsedTime, int& gameTick, float& woodGatherRate, float& foodGatherRate, float& stoneGatherRate, float& metalGatherRate, float& coinGatherRate, float& Wood, float& Food, float& Stone, float& Metal, float& Coin, int woodGatherers, int foodGatherers, int stoneGatherers, int Miners, int Minters, float woodModifier, float foodModifier, float stoneModifier, float metalModifier, float coinModifier)
{
	tick += fElapsedTime;
	if (tick >= 2.5f)
	{
		foodConsump(Food, Population);
		gatherRates(woodGatherRate, foodGatherRate, stoneGatherRate, metalGatherRate, coinGatherRate, woodGatherers, foodGatherers, stoneGatherers, Miners, Minters, woodModifier, foodModifier, stoneModifier, metalModifier, coinModifier);
		resAccum(Wood, Food, Stone, Metal, Coin);
		gameTick++;
		tick = 0.f;
	}

	return gameTick;
}

int Engine::PopTickSystem(int& gameTick, int& PopTick, int& Population, int& popInc, float& Food, int& IdlePop, int& popCap)
{
	popInc = rand() % 5 + 1;
	if (gameTick >= 6)
	{
		PopTick++;
		gameTick = 0;
		if (Food > (Population * 2) && Population < popCap)
		{
			Population += popInc;
			IdlePop += popInc;

		}
	}
	return PopTick;
}

std::string Engine::ftos(float f)
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << f;
	std::string s = stream.str();
	return s;
}

int Engine::calculateTotalGatherers(int& woodGatherers, int& foodGatherers, int& stoneGatherers, int& Miners, int& Minters)
{
	totalGatherers = woodGatherers + foodGatherers + stoneGatherers + Miners + Minters;
	return totalGatherers;
}

int Engine::calculateIdle(int& Population, int& totalGatherers, int& IdlePop)
{
	IdlePop = Population - totalGatherers;
	return IdlePop;
}

int Engine::calculatePopCap(int& houseTotal, int& popCap)
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

float Engine::foodConsump(float& Food, int Population)
{
	Food -= Population / 5;

	return Food;
}

std::tuple<float, float, float, float, float> Engine::calculateModifiers(int& farmTotal, int& timberyardTotal, int& quarryTotal, int& mineTotal, int& mintTotal)
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

void Engine::userInput()
{
	//Options Inputs

	if (GetMouseX() >= 420 && GetMouseX() <= 720 && GetMouseY() >= 350 && GetMouseY() <= 410 && GameState == Options)
	{
		backSelected = true;
		if (GetMouse(0).bPressed && backSelected == true)
		{
			GameState = MainMenu;
			backSelected = false;
		}

	}
	else
	{
		backSelected = false;
	}


	//Gamescreen Buttons

	//Worker Buttons
	if (GetMouseX() >= 920 && GetMouseX() <= 960 && GetMouseY() >= 140 && GetMouseY() <= 170 && GameState == GameScreen)
	{
		if (GetMouse(0).bPressed && woodGatherers > 0)
		{
			woodGatherers--;
		}

	}
	else if (GetMouseX() >= 970 && GetMouseX() <= 1010 && GetMouseY() >= 140 && GetMouseY() <= 170 && GameState == GameScreen)
	{
		if (GetMouse(0).bPressed && IdlePop > 0)
		{
			woodGatherers++;
		}

	}
	else if (GetMouseX() >= 920 && GetMouseX() <= 960 && GetMouseY() >= 190 && GetMouseY() <= 220 && GameState == GameScreen)
	{
		if (GetMouse(0).bPressed && foodGatherers > 0)
		{
			foodGatherers--;
		}

	}
	else if (GetMouseX() >= 970 && GetMouseX() <= 1010 && GetMouseY() >= 190 && GetMouseY() <= 220 && GameState == GameScreen)
	{
		if (GetMouse(0).bPressed && IdlePop > 0)
		{
			foodGatherers++;
		}

	}
	else if (GetMouseX() >= 920 && GetMouseX() <= 960 && GetMouseY() >= 240 && GetMouseY() <= 270 && GameState == GameScreen)
	{
		if (GetMouse(0).bPressed && stoneGatherers > 0)
		{
			stoneGatherers--;
		}

	}
	else if (GetMouseX() >= 970 && GetMouseX() <= 1010 && GetMouseY() >= 240 && GetMouseY() <= 270 && GameState == GameScreen)
	{
		if (GetMouse(0).bPressed && IdlePop > 0)
		{
			stoneGatherers++;
		}

	}
	else if (GetMouseX() >= 920 && GetMouseX() <= 960 && GetMouseY() >= 290 && GetMouseY() <= 320 && GameState == GameScreen)
	{
		if (GetMouse(0).bPressed && Miners > 0)
		{
			Miners--;
		}

	}
	else if (GetMouseX() >= 970 && GetMouseX() <= 1010 && GetMouseY() >= 290 && GetMouseY() <= 320 && GameState == GameScreen)
	{
		if (GetMouse(0).bPressed && IdlePop > 0)
		{
			Miners++;
		}

	}
	else if (GetMouseX() >= 920 && GetMouseX() <= 960 && GetMouseY() >= 340 && GetMouseY() <= 370 && GameState == GameScreen)
	{
		if (GetMouse(0).bPressed && Minters > 0)
		{
			Minters--;
		}

	}
	else if (GetMouseX() >= 970 && GetMouseX() <= 1010 && GetMouseY() >= 340 && GetMouseY() <= 370 && GameState == GameScreen)
	{
		if (GetMouse(0).bPressed && IdlePop > 0)
		{
			Minters++;
		}

	}

	//Navigation Inputs

	if (GetMouseX() >= 30 && GetMouseX() <= 130 && GetMouseY() >= 550 && GetMouseY() <= 600 && GameState == GameScreen)
	{
		helpSelected = true;
		if (GetMouse(0).bPressed && helpSelected)
		{
			GameState = HelpScreen;
		}
	}
	else if (GetMouseX() >= 180 && GetMouseX() <= 360 && GetMouseY() >= 550 && GetMouseY() <= 600 && GameState == GameScreen)
	{
		buildSelected = true;
		if (GetMouse(0).bPressed && buildSelected)
		{
			GameState = BuildingScreen;
		}
	}
	else if (GetMouseX() >= 410 && GetMouseX() <= 570 && GetMouseY() >= 550 && GetMouseY() <= 600 && GameState == GameScreen)
	{
		upgrSelected = true;
		if (GetMouse(0).bPressed && upgrSelected)
		{
			GameState = Upgrades;
		}
	}
	else if (GetMouseX() >= 620 && GetMouseX() <= 850 && GetMouseY() >= 550 && GetMouseY() <= 600 && GameState == GameScreen)
	{
		achieveSelected = true;
		if (GetMouse(0).bPressed && achieveSelected)
		{
			GameState = Acheivements;
		}
	}
	else if (GetMouseX() >= 890 && GetMouseX() <= 1040 && GetMouseY() >= 550 && GetMouseY() <= 600 && GameState == GameScreen)
	{
		creditSelected = true;
		if (GetMouse(0).bPressed && creditSelected)
		{
			GameState = Credits;
		}
	}
	else
	{
		helpSelected = false;
		buildSelected = false;
		upgrSelected = false;
		achieveSelected = false;
		creditSelected = false;
	}

	//HelpScreen Inputs

	if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 550 && GetMouseY() <= 600 && GameState == HelpScreen)
	{
		hBackselected = true;
		if (GetMouse(0).bPressed && hBackselected)
		{
			GameState = GameScreen;
		}
	}
	else
	{
		hBackselected = false;
	}

	//Upgrade Inputs

	if (GetMouseX() >= 400 && GetMouseX() <= 450 && GetMouseY() >= 90 && GetMouseY() <= 140 && GameState == Upgrades)
	{
		if (GetMouse(0).bPressed && !upgrade1 && Coin > 100)
		{
			Coin -= 100;
			upgrade1 = true;
		}
	}
	else if (GetMouseX() >= 400 && GetMouseX() <= 450 && GetMouseY() >= 160 && GetMouseY() <= 210 && GameState == Upgrades)
	{
		if (GetMouse(0).bPressed && !upgrade2 && Coin > 200)
		{
			Coin -= 200;
			upgrade2 = true;
		}

	}
	else if (GetMouseX() >= 400 && GetMouseX() <= 450 && GetMouseY() >= 230 && GetMouseY() <= 280 && GameState == Upgrades)
	{
		if (GetMouse(0).bPressed && !upgrade3 && Coin > 300)
		{
			Coin -= 300;
			upgrade3 = true;
		}
	}


	//BuildingScreen Inputs
	if (GetMouseX() >= 550 && GetMouseX() <= 590 && GetMouseY() >= 100 && GetMouseY() <= 130 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && Wood >= 10)
		{
			Wood -= 10;
			houseTotal++;
		}
	}
	else if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 150 && GetMouseY() <= 180 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && Wood >= 15)
		{
			Wood -= 15;
			farmTotal++;
		}
	}
	else if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 200 && GetMouseY() <= 230 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && Metal >= 10)
		{
			Metal -= 10;
			timberyardTotal++;
		}
	}
	else if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 250 && GetMouseY() <= 280 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && Metal >= 10 && Wood >= 5)
		{
			Metal -= 10;
			Wood -= 5;
			quarryTotal++;
		}
	}
	else if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 300 && GetMouseY() <= 330 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && Metal >= 25 && Wood >= 15)
		{
			Metal -= 25;
			Wood -= 15;
			mineTotal++;
		}
	}
	else if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 350 && GetMouseY() <= 380 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && Metal >= 50)
		{
			Metal -= 50;
			mintTotal++;
		}
	}
	else if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 550 && GetMouseY() <= 600 && GameState == BuildingScreen)
	{
		bBackselected = true;
		if (GetMouse(0).bPressed && bBackselected)
		{
			GameState = GameScreen;
		}
	}
	else
	{
		bBackselected = false;
	}


	if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 550 && GetMouseY() <= 600 && GameState == Upgrades)
	{
		uBackselected = true;
		if (GetMouse(0).bPressed && uBackselected)
		{
			GameState = GameScreen;
		}
	}
	else
	{
		uBackselected = false;
	}


	if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 550 && GetMouseY() <= 600 && GameState == Acheivements)
	{
		aBackselected = true;
		if (GetMouse(0).bPressed && aBackselected)
		{
			GameState = GameScreen;
		}

	}
	else
	{
		aBackselected = false;
	}


	if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 550 && GetMouseY() <= 600 && GameState == Credits)
	{
		cBackselected = true;
		if (GetMouse(0).bPressed && cBackselected)
		{
			GameState = GameScreen;
		}

	}
	else
	{
		cBackselected = false;
	}
}

void Engine::populateButtonVec()
{
	Main.emplace_back("Start", 420, 150, 300, 60, GameScreen, 0, olc::DARK_GREY, olc::BLACK);
	Main.emplace_back("Options", 420, 250, 300, 60, Options, 0, olc::DARK_GREY, olc::BLACK);
	Main.emplace_back("Quit", 420, 350, 300, 60, -1, 0, olc::DARK_GREY, olc::BLACK);

	Game.emplace_back("-", 920, 140, 40, 30, GameScreen, 0, olc::GREY, olc::RED);
	Game.emplace_back("+", 970, 140, 40, 30, GameScreen, 0, olc::GREY, olc::GREEN);
}



bool Engine::OnUserCreate()
{
	srand(time(NULL));
	populateButtonVec();
	return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::VERY_DARK_GREY);

	calculateModifiers(farmTotal, timberyardTotal, quarryTotal, mineTotal, mintTotal);

	TickSystem(tick, Population, fElapsedTime, gameTick, woodGatherRate, foodGatherRate, stoneGatherRate, metalGatherRate, coinGatherRate, Wood, Food, Stone, Metal, Coin, woodGatherers, foodGatherers, stoneGatherers, Miners, Minters, woodModifier, foodModifier, stoneModifier, metalModifier, coinModifier);
	calculateTotalGatherers(woodGatherers, foodGatherers, stoneGatherers, Miners, Minters);
	calculateIdle(Population, totalGatherers, IdlePop);
	calculatePopCap(houseTotal, popCap);
	PopTickSystem(gameTick, PopTick, Population, popInc, Food, IdlePop, popCap);
	settleSize(type, houseTotal, farmTotal, timberyardTotal, quarryTotal, mineTotal, mintTotal);

	userInput();
	checkAchievements(alpha1, alpha2, alpha3, alpha4, achieve, alpha0, anotherHouseComplete, farmHandComplete, timberrrComplete, expansionComplete);
	

	switch (GameState)
	{
	case MainMenu:
	{
		FillRect(olc::vf2d(150, 50), olc::vf2d(800, 500), olc::GREY);
		DrawStringDecal(olc::vf2d(400, 80), "Civ-Clicker", olc::Pixel(160, 82, 45), olc::vf2d(4.f, 4.f));

		for (size_t i = 0; i < Main.size(); i++)
		{
			Main[i].DrawSelf(this);
			Main[i].onHover(this);
			if (Main[i].onInteract(this))
			{
				GameState = Main[i].interaction.first;
			}
		}
		break;
	}

	case GameScreen:
	{

		for (size_t i = 0; i < Game.size(); i++)
		{
			Game[i].DrawSelf(this);
			Game[i].onHover(this);
			if (Game[i].onInteract(this))
			{
				GameState = Game[i].interaction.first;
			}
		}
		//Top
		DrawString(50, 100, type, olc::DARK_GREEN, 3U);
		DrawString(350, 50, "Population = " + std::to_string(Population), olc::WHITE, 3U);
		DrawString(450, 80, "Idle = " + std::to_string(IdlePop), olc::WHITE, 2U);
		DrawString(800, 50, "Cap = " + std::to_string(popCap), olc::WHITE, 2U);

		//Resource - Left
		DrawString(120, 175, "Wood = " + ftos(Wood), olc::WHITE, 2U);
		DrawString(120, 200, "Food = " + ftos(Food), olc::WHITE, 2U);
		DrawString(120, 225, "Stone = " + ftos(Stone), olc::WHITE, 2U);
		DrawString(120, 250, "Metal = " + ftos(Metal), olc::WHITE, 2U);
		DrawString(120, 275, "Coin = " + ftos(Coin), olc::WHITE, 2U);


		//Workers - Right
		DrawString(580, 150, "Wood Gatherers = " + std::to_string(woodGatherers), olc::WHITE, 2U);
		DrawString(580, 200, "Food Gatherers = " + std::to_string(foodGatherers), olc::WHITE, 2U);
		DrawString(580, 250, "Stone Gatherers = " + std::to_string(stoneGatherers), olc::WHITE, 2U);
		DrawString(580, 300, "Miners = " + std::to_string(Miners), olc::WHITE, 2U);
		DrawString(580, 350, "Minters = " + std::to_string(Minters), olc::WHITE, 2U);
		DrawString(580, 400, "Total Gatherers = " + std::to_string(totalGatherers), olc::WHITE, 2U);

		//Add&Remove Worker Buttons
		//FillRect();
		//FillRect();

		FillRect(920, 190, 40, 30, olc::GREY);
		FillRect(970, 190, 40, 30, olc::GREY);

		FillRect(920, 240, 40, 30, olc::GREY);
		FillRect(970, 240, 40, 30, olc::GREY);

		FillRect(920, 290, 40, 30, olc::GREY);
		FillRect(970, 290, 40, 30, olc::GREY);

		FillRect(920, 340, 40, 30, olc::GREY);
		FillRect(970, 340, 40, 30, olc::GREY);

		//Button Text
		//DrawString(935, 150, "-", olc::RED, 2U);
		//DrawString(985, 150, "+", olc::GREEN, 2U);

		//DrawString(935, 200, "-", olc::RED, 2U);
		//DrawString(985, 200, "+", olc::GREEN, 2U);

		DrawString(935, 250, "-", olc::RED, 2U);
		DrawString(985, 250, "+", olc::GREEN, 2U);

		DrawString(935, 300, "-", olc::RED, 2U);
		DrawString(985, 300, "+", olc::GREEN, 2U);

		DrawString(935, 350, "-", olc::RED, 2U);
		DrawString(985, 350, "+", olc::GREEN, 2U);


		//GameTime - Bottom
		DrawString(150, 500, "Tick = " + ftos(tick), olc::WHITE, 2U);
		DrawString(600, 500, "PopTick = " + std::to_string(PopTick), olc::WHITE, 2U);

		//Buttons
		FillRect(30, 550, 100, 50, olc::DARK_GREY);
		FillRect(180, 550, 180, 50, olc::DARK_GREY);
		FillRect(410, 550, 160, 50, olc::DARK_GREY);
		FillRect(620, 550, 230, 50, olc::DARK_GREY);
		FillRect(890, 550, 150, 50, olc::DARK_GREY);


		DrawString(50, 565, "Help", olc::WHITE, 2U);
		DrawString(200, 565, "Buildings", olc::WHITE, 2U);
		DrawString(430, 565, "Upgrades", olc::WHITE, 2U);
		DrawString(640, 565, "Achievements", olc::WHITE, 2U);
		DrawString(910, 565, "Credits", olc::WHITE, 2U);


		//Achievement notif
		SetPixelMode(olc::Pixel::ALPHA);
		DrawString(120, 400, achieve, olc::Pixel(0, 255, 0, uint8_t(alpha0 * 255)), 3U);
		SetPixelMode(olc::Pixel::NORMAL);

		if (helpSelected)
		{
			DrawRect(30, 550, 100, 50, olc::YELLOW);
		}
		else if (buildSelected)
		{
			DrawRect(180, 550, 180, 50, olc::YELLOW);
		}
		else if (upgrSelected)
		{
			DrawRect(410, 550, 160, 50, olc::YELLOW);
		}
		else if (achieveSelected)
		{
			DrawRect(620, 550, 230, 50, olc::YELLOW);
		}
		else if (creditSelected)
		{
			DrawRect(890, 550, 150, 50, olc::YELLOW);
		}


		break;
	}



	case HelpScreen:
	{
		DrawString(30, 100, "Welcome to Civ-Clicker", olc::WHITE, 2U);

		DrawString(30, 150, "Build Houses to increase your Population Cap", olc::WHITE, 2U);
		DrawString(30, 175, "buildings other than houses give a boost to the workers", olc::WHITE, 2U);
		DrawString(30, 225, "the aim is to increase your settlement size", olc::WHITE, 2U);
		DrawString(30, 250, "for this you will need to gather resources and use them to build.", olc::WHITE, 2U);
		DrawString(30, 275, "The higher your Population, the more food they will require", olc::WHITE, 2U);
		DrawString(30, 300, "Everything in brackets beside a button is a requirement", olc::WHITE, 2U);
		DrawString(30, 325, "Will you get all the achievements?", olc::WHITE, 2U);

		FillRect(500, 550, 110, 50, olc::DARK_GREY);
		DrawStringDecal(olc::vf2d(525, 565), "Back", olc::WHITE, olc::vf2d(2.f, 2.f));

		if (hBackselected)
		{
			DrawRect(500, 550, 110, 50, olc::YELLOW);
		}

		break;
	}
	case BuildingScreen:
	{

		//Buildings
		DrawString(120, 100, "House Total = " + std::to_string(houseTotal), olc::WHITE, 2U);
		DrawString(120, 150, "Farm Total = " + std::to_string(farmTotal), olc::WHITE, 2U);
		DrawString(120, 200, "TimberYard Total = " + std::to_string(timberyardTotal), olc::WHITE, 2U);
		DrawString(120, 250, "Quarry Total = " + std::to_string(quarryTotal), olc::WHITE, 2U);
		DrawString(120, 300, "Mine Total = " + std::to_string(mineTotal), olc::WHITE, 2U);
		DrawString(120, 350, "Mint Total = " + std::to_string(mintTotal), olc::WHITE, 2U);

		//Building Buttons
		FillRect(550, 100, 40, 30, olc::DARK_GREY);
		FillRect(550, 150, 40, 30, olc::DARK_GREY);
		FillRect(550, 200, 40, 30, olc::DARK_GREY);
		FillRect(550, 250, 40, 30, olc::DARK_GREY);
		FillRect(550, 300, 40, 30, olc::DARK_GREY);
		FillRect(550, 350, 40, 30, olc::DARK_GREY);

		//Button Text
		DrawString(565, 109, "+", olc::GREEN, 2U);
		DrawString(610, 109, "(10 Wood)", olc::WHITE, 2U);
		DrawString(565, 159, "+", olc::GREEN, 2U);
		DrawString(610, 159, "(15 Wood)", olc::WHITE, 2U);
		DrawString(565, 209, "+", olc::GREEN, 2U);
		DrawString(610, 209, "(10 Metal)", olc::WHITE, 2U);
		DrawString(565, 259, "+", olc::GREEN, 2U);
		DrawString(610, 259, "(10 Metal & 5 Wood)", olc::WHITE, 2U);
		DrawString(565, 309, "+", olc::GREEN, 2U);
		DrawString(610, 309, "(25 Metal & 15 Wood)", olc::WHITE, 2U);
		DrawString(565, 359, "+", olc::GREEN, 2U);
		DrawString(610, 359, "(50 Metal)", olc::WHITE, 2U);

		//Achievement notif
		SetPixelMode(olc::Pixel::ALPHA);
		DrawString(120, 400, achieve, olc::Pixel(0, 255, 0, uint8_t(alpha0 * 255)), 3U);
		SetPixelMode(olc::Pixel::NORMAL);


		FillRect(500, 550, 110, 50, olc::DARK_GREY);
		DrawString(525, 565, "Back", olc::WHITE, 2U);

		if (bBackselected)
		{
			DrawRect(500, 550, 110, 50, olc::YELLOW);
		}

		break;
	}
	case Upgrades:
	{
		DrawString(360, 30, "UPGRADES", olc::YELLOW, 4U);
		DrawLine(360, 60, 610, 60, olc::YELLOW);

		DrawString(120, 100, "Bigger Houses", olc::WHITE, 2U);
		DrawString(120, 170, "Crop Rotation", olc::WHITE, 2U);
		DrawString(120, 240, "Better Hatchets", olc::WHITE, 2U);

		if (upgrade1)
		{
			FillRect(400, 90, 40, 40, olc::GREEN);
		}
		else
		{
			FillRect(400, 90, 40, 40, olc::RED);
		}

		if (upgrade2)
		{
			FillRect(400, 160, 40, 40, olc::GREEN);
		}
		else
		{
			FillRect(400, 160, 40, 40, olc::RED);
		}

		if (upgrade3)
		{
			FillRect(400, 230, 40, 40, olc::GREEN);
		}
		else
		{
			FillRect(400, 230, 40, 40, olc::RED);
		}

		DrawString(460, 100, "(100 Coins)", olc::WHITE, 2U);
		DrawString(460, 170, "(200 Coins)", olc::WHITE, 2U);
		DrawString(460, 240, "(300 Coins)", olc::WHITE, 2U);


		FillRect(500, 550, 110, 50, olc::DARK_GREY);
		DrawString(525, 565, "Back", olc::WHITE, 2U);

		if (uBackselected)
		{
			DrawRect(500, 550, 110, 50, olc::YELLOW);
		}


		break;
	}
	case Acheivements:
	{
		DrawString(320, 30, "ACHIEVEMENTS", olc::GREEN, 4U);
		DrawLine(320, 60, 695, 60, olc::GREEN);

		SetPixelMode(olc::Pixel::ALPHA);
		DrawString(80, 100, achieve1, olc::Pixel(255, 255, 255, alpha1), 2U);
		DrawString(80, 130, achieve2, olc::Pixel(255, 255, 255, alpha2), 2U);
		DrawString(80, 160, achieve3, olc::Pixel(255, 255, 255, alpha3), 2U);
		DrawString(80, 190, achieve4, olc::Pixel(255, 255, 255, alpha4), 2U);
		SetPixelMode(olc::Pixel::NORMAL);

		FillRect(500, 550, 110, 50, olc::DARK_GREY);
		DrawString(525, 565, "Back", olc::WHITE, 2U);

		if (aBackselected)
		{
			DrawRect(500, 550, 110, 50, olc::YELLOW);
		}

		break;
	}
	case Credits:
	{
		DrawString(60, 100, " Creator : Danicron (Daniel Twitchett) ", olc::WHITE, 3U);
		DrawString(60, 130, " Assisted by : Javidx9 ", olc::WHITE, 3U);
		DrawString(395, 160, " Gorbit99 ", olc::WHITE, 3U);
		DrawString(60, 200, "and of course the rest of the OneLoneCoder Community", olc::WHITE, 2U);
		DrawString(60, 215, " for being my rubber duckies!", olc::WHITE, 2U);
		FillRect(500, 550, 110, 50, olc::DARK_GREY);
		DrawString(525, 565, "Back", olc::WHITE, 2U);

		if (cBackselected)
		{
			DrawRect(500, 550, 110, 50, olc::YELLOW);
		}
		break;
	}
	case Options:
	{
		FillRect(150, 50, 800, 500, olc::GREY);
		//Buttons
		FillRect(420, 350, 300, 60, olc::DARK_GREY);
		//Button Text
		DrawString(520, 370, "Back", olc::BLACK, 3U);
		if (backSelected)
		{
			DrawRect(420, 350, 300, 60, olc::YELLOW);
		}
		break;
	}
	case -1:
	{
		return false;
		break;
	}

	}


	if (alpha0 > 0)
	{
		alpha0 -= fElapsedTime / timeToFade;
	}

	if (IdlePop <= 0)
	{
		IdlePop = 0;
	}

	if (Food < 0)
	{
		Food = 0;
	}

	if (Population > popCap)
	{
		Population = popCap;
	}

	return true;

}