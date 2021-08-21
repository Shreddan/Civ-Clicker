#include "Achievement.h"


Achievement::Achievement()
{
}

Achievement::~Achievement()
{
}

void Achievement::checkAchievements(int& houseTotal, std::string& achieve, float& alpha0, bool& anotherHouseComplete, bool& farmHandComplete, bool& timberrrComplete, bool& expansionComplete)
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
		if (civ->farmTotal == 1)
		{
			achieve = achieve2;
			alpha2 = 255;
			alpha0 = 1;
			farmHandComplete = true;
		}

	}
	else if (!timberrrComplete)
	{
		if (civ->timberyardTotal == 1)
		{
			achieve = achieve3;
			alpha3 = 255;
			alpha0 = 1;
			timberrrComplete = true;
		}

	}
	else if (!expansionComplete)
	{
		if (civ->type == "Town")
		{
			achieve = achieve4;
			alpha4 = 255;
			alpha0 = 1;
			expansionComplete = true;
		}

	}


}

void Achievement::DrawSelf(olc::PixelGameEngine* pge)
{
}
