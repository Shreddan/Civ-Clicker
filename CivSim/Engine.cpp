#include "Engine.h"

Engine::Engine()
{
	sAppName = "Civ-Clicker";
}

Engine::~Engine()
{
	delete civ;
	OnUserDestroy();
}



int Engine::TickSystem(float& tick, int Population, float& fElapsedTime, int& gameTick, float& woodGatherRate, float& foodGatherRate, float& stoneGatherRate, float& metalGatherRate, float& coinGatherRate, float& Wood, float& Food, float& Stone, float& Metal, float& Coin, int woodGatherers, int foodGatherers, int stoneGatherers, int Miners, int Minters, float woodModifier, float foodModifier, float stoneModifier, float metalModifier, float coinModifier)
{
	tick += fElapsedTime;
	if (tick >= 2.5f)
	{
		civ->foodConsump();
		civ->res->gatherRates(woodGatherers, foodGatherers, stoneGatherers, Miners, Minters, woodModifier, foodModifier, stoneModifier, metalModifier, coinModifier);
		civ->res->resAccum();
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

void Engine::userInput(int& ID)
{
	switch (ID)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		civ->woodGatherers--;
		break;
	}
	case 2:
	{
		civ->woodGatherers++;
		break;
	}
	case 3:
	{
		civ->foodGatherers--;
		break;
	}
	case 4:
	{
		civ->foodGatherers++;
		break;
	}
	case 5:
	{
		civ->stoneGatherers--;
		break;
	}
	case 6:
	{
		civ->stoneGatherers++;
		break;
	}
	case 7:
	{
		civ->Miners--;
		break;
	}
	case 8:
	{
		civ->Miners++;
		break;
	}
	case 9:
	{
		civ->Minters--;
		break;
	}
	case 10:
	{
		civ->Minters++;
		break;
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
			GameState = Achievements;
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
		if (GetMouse(0).bPressed && !civ->upgrade1 && civ->res->Coin > 100)
		{
			civ->res->Coin -= 100;
			civ->upgrade1 = true;
		}
	}
	else if (GetMouseX() >= 400 && GetMouseX() <= 450 && GetMouseY() >= 160 && GetMouseY() <= 210 && GameState == Upgrades)
	{
		if (GetMouse(0).bPressed && !civ->upgrade2 && civ->res->Coin > 200)
		{
			civ->res->Coin -= 200;
			civ->upgrade2 = true;
		}

	}
	else if (GetMouseX() >= 400 && GetMouseX() <= 450 && GetMouseY() >= 230 && GetMouseY() <= 280 && GameState == Upgrades)
	{
		if (GetMouse(0).bPressed && !civ->upgrade3 && civ->res->Coin > 300)
		{
			civ->res->Coin -= 300;
			civ->upgrade3 = true;
		}
	}


	//BuildingScreen Inputs
	if (GetMouseX() >= 550 && GetMouseX() <= 590 && GetMouseY() >= 100 && GetMouseY() <= 130 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && civ->res->Wood >= 10)
		{
			civ->res->Wood -= 10;
			civ->houseTotal++;
		}
	}
	else if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 150 && GetMouseY() <= 180 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && civ->res->Wood >= 15)
		{
			civ->res->Wood -= 15;
			civ->farmTotal++;
		}
	}
	else if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 200 && GetMouseY() <= 230 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && civ->res->Metal >= 10)
		{
			civ->res->Metal -= 10;
			civ->timberyardTotal++;
		}
	}
	else if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 250 && GetMouseY() <= 280 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && civ->res->Metal >= 10 && civ->res->Wood >= 5)
		{
			civ->res->Metal -= 10;
			civ->res->Wood -= 5;
			civ->quarryTotal++;
		}
	}
	else if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 300 && GetMouseY() <= 330 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && civ->res->Metal >= 25 && civ->res->Wood >= 15)
		{
			civ->res->Metal -= 25;
			civ->res->Wood -= 15;
			civ->mineTotal++;
		}
	}
	else if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 350 && GetMouseY() <= 380 && GameState == BuildingScreen)
	{
		if (GetMouse(0).bPressed && civ->res->Metal >= 50)
		{
			civ->res->Metal -= 50;
			civ->mintTotal++;
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


	if (GetMouseX() >= 500 && GetMouseX() <= 610 && GetMouseY() >= 550 && GetMouseY() <= 600 && GameState == Achievements)
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
	Main.emplace_back("Start", 420, 150, 300, 60, GameScreen, 0, olc::DARK_GREY, 3);
	Main.emplace_back("Options", 420, 250, 300, 60, Options, 0, olc::DARK_GREY, 3);
	Main.emplace_back("Quit", 420, 350, 300, 60, -1, 0, olc::DARK_GREY, 3);

	//Nav Buttons
	Game.emplace_back("Help", 30, 550, 100, 50, HelpScreen, 0, olc::DARK_GREY, 2, olc::WHITE);
	Game.emplace_back("Buildings", 180, 550, 180, 50, BuildingScreen, 0, olc::DARK_GREY, 2, olc::WHITE);
	Game.emplace_back("Upgrades", 410, 550, 160, 50, Upgrades, 0, olc::DARK_GREY, 2, olc::WHITE);
	Game.emplace_back("Achievements", 620, 550, 230, 50, Achievements, 0, olc::DARK_GREY, 2, olc::WHITE);
	Game.emplace_back("Credits", 890, 550, 150, 50, Credits, 0, olc::DARK_GREY, 2, olc::WHITE);


	//Worker Buttons
	Game.emplace_back("-", 920, 140, 40, 30, GameScreen, 1, olc::GREY, 3, olc::RED);
	Game.emplace_back("+", 970, 140, 40, 30, GameScreen, 2, olc::GREY, 3, olc::GREEN);
	Game.emplace_back("-", 920, 190, 40, 30, GameScreen, 3, olc::GREY, 3, olc::RED);
	Game.emplace_back("+", 970, 190, 40, 30, GameScreen, 4, olc::GREY, 3, olc::GREEN);
	Game.emplace_back("-", 920, 240, 40, 30, GameScreen, 5, olc::GREY, 3, olc::RED);
	Game.emplace_back("+", 970, 240, 40, 30, GameScreen, 6, olc::GREY, 3, olc::GREEN);
	Game.emplace_back("-", 920, 290, 40, 30, GameScreen, 7, olc::GREY, 3, olc::RED);
	Game.emplace_back("+", 970, 290, 40, 30, GameScreen, 8, olc::GREY, 3, olc::GREEN);
	Game.emplace_back("-", 920, 340, 40, 30, GameScreen, 9, olc::GREY, 3, olc::RED);
	Game.emplace_back("+", 970, 340, 40, 30, GameScreen, 10, olc::GREY, 3, olc::GREEN);

	labels.emplace_back(50, 100, civ->type, olc::DARK_GREEN, 1, 0, 3);
	labels.emplace_back(350, 50, "Population = ", olc::WHITE, 1, 2, 3);
	labels.emplace_back(450, 80, "Idle = ", olc::WHITE, 1, 1, 2);
	labels.emplace_back(800, 50, "Cap = ", olc::WHITE, 1, 3, 2);
	labels.emplace_back(120, 175, "Wood = ", olc::WHITE, 1, 4, 2);
	labels.emplace_back(120, 200, "Food = ", olc::WHITE, 1, 5, 2);
	labels.emplace_back(120, 225, "Stone = ", olc::WHITE, 1, 6, 2);
	labels.emplace_back(120, 250, "Metal = ", olc::WHITE, 1, 7, 2);
	labels.emplace_back(120, 275, "Coin = ", olc::WHITE, 1, 8, 2);
}



bool Engine::OnUserCreate()
{
	//core->Create(877611818154065970, DiscordCreateFlags_Default, &core);
	civ = new Civilisation();
	srand(time(NULL));
	populateButtonVec();
	return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::VERY_DARK_GREY);

	civ->calculateModifiers();

	TickSystem(tick, civ->Population, fElapsedTime, gameTick, civ->res->woodGatherRate, civ->res->foodGatherRate, civ->res->stoneGatherRate, civ->res->metalGatherRate, civ->res->coinGatherRate, civ->res->Wood, civ->res->Food, civ->res->Stone, civ->res->Metal, civ->res->Coin, civ->woodGatherers, civ->foodGatherers, civ->stoneGatherers, civ->Miners, civ->Minters, civ->woodModifier, civ->foodModifier, civ->stoneModifier, civ->metalModifier, civ->coinModifier);
	civ->calculateTotalGatherers();
	civ->calculateIdle();
	civ->calculatePopCap();
	PopTickSystem(gameTick, PopTick, civ->Population, civ->popInc, civ->res->Food, civ->IdlePop, civ->popCap);
	civ->settleSize();
	
	for (size_t i = 0; i < labels.size(); i++)
	{
		if (labels[i].ID == GameState)
		{
			labels[i].DrawSelf(this);
			labels[i].updateLabel(civ);
		}
	}

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
				userInput(Game[i].interaction.second);
			}
		}

		//Workers - Right
		DrawString(580, 150, "Wood Gatherers = " + std::to_string(civ->woodGatherers), olc::WHITE, 2U);
		DrawString(580, 200, "Food Gatherers = " + std::to_string(civ->foodGatherers), olc::WHITE, 2U);
		DrawString(580, 250, "Stone Gatherers = " + std::to_string(civ->stoneGatherers), olc::WHITE, 2U);
		DrawString(580, 300, "Miners = " + std::to_string(civ->Miners), olc::WHITE, 2U);
		DrawString(580, 350, "Minters = " + std::to_string(civ->Minters), olc::WHITE, 2U);
		DrawString(580, 400, "Total Gatherers = " + std::to_string(civ->totalGatherers), olc::WHITE, 2U);

		//Button Text
		

		/*DrawString(935, 250, "-", olc::RED, 2U);
		DrawString(985, 250, "+", olc::GREEN, 2U);

		DrawString(935, 300, "-", olc::RED, 2U);
		DrawString(985, 300, "+", olc::GREEN, 2U);

		DrawString(935, 350, "-", olc::RED, 2U);
		DrawString(985, 350, "+", olc::GREEN, 2U);*/

		//GameTime - Bottom
		//DrawString(150, 500, "Tick = " + ftos(tick), olc::WHITE, 2U);
		//DrawString(600, 500, "PopTick = " + std::to_string(PopTick), olc::WHITE, 2U);

		//Achievement notif
		/*SetPixelMode(olc::Pixel::ALPHA);
		DrawString(120, 400, achieve, olc::Pixel(0, 255, 0, uint8_t(alpha0 * 255)), 3U);
		SetPixelMode(olc::Pixel::NORMAL);*/

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
		DrawString(120, 100, "House Total = " + std::to_string(civ->houseTotal), olc::WHITE, 2U);
		DrawString(120, 150, "Farm Total = " + std::to_string(civ->farmTotal), olc::WHITE, 2U);
		DrawString(120, 200, "TimberYard Total = " + std::to_string(civ->timberyardTotal), olc::WHITE, 2U);
		DrawString(120, 250, "Quarry Total = " + std::to_string(civ->quarryTotal), olc::WHITE, 2U);
		DrawString(120, 300, "Mine Total = " + std::to_string(civ->mineTotal), olc::WHITE, 2U);
		DrawString(120, 350, "Mint Total = " + std::to_string(civ->mintTotal), olc::WHITE, 2U);

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
		/*SetPixelMode(olc::Pixel::ALPHA);
		DrawString(120, 400, achieve, olc::Pixel(0, 255, 0, uint8_t(alpha0 * 255)), 3U);
		SetPixelMode(olc::Pixel::NORMAL);*/


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

		if (civ->upgrade1)
		{
			FillRect(400, 90, 40, 40, olc::GREEN);
		}
		else
		{
			FillRect(400, 90, 40, 40, olc::RED);
		}

		if (civ->upgrade2)
		{
			FillRect(400, 160, 40, 40, olc::GREEN);
		}
		else
		{
			FillRect(400, 160, 40, 40, olc::RED);
		}

		if (civ->upgrade3)
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
	case Achievements:
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

	if (civ->IdlePop <= 0)
	{
		civ->IdlePop = 0;
	}

	if (civ->res->Food < 0)
	{
		civ->res->Food = 0;
	}

	if (civ->Population > civ->popCap)
	{
		civ->Population = civ->popCap;
	}

	return true;

}