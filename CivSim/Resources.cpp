#include "Resources.h"

Resources::Resources()
{
}

Resources::~Resources()
{
}

void Resources::resAccum()
{
	Wood += woodGatherRate;
	Food += foodGatherRate;
	Stone += stoneGatherRate;
	Metal += metalGatherRate;
	Coin += coinGatherRate;

	
}

void Resources::gatherRates(int woodgatherers, int foodgatherers, int stonegatherers, int miners, int minters, float woodModifier, float foodModifier, float stoneModifier, float metalModifier, float coinModifier)
{
	woodGatherRate = woodgatherers * 1.6f + woodModifier;
	foodGatherRate = foodgatherers * 2.2f + foodModifier;
	stoneGatherRate = stonegatherers * 1.3f + stoneModifier;
	metalGatherRate = miners * 1.5 + metalModifier;
	coinGatherRate = minters * 1.1 + coinModifier;
	
}