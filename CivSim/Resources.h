#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <tuple>
#include <deque>

class Resources
{
public:
	Resources();
	~Resources();

	float Wood = 0.0f;

	float woodGatherRate = 0;
	float Food = 0.0f;

	float foodGatherRate = 0;
	float Stone = 0.0f;

	float stoneGatherRate = 0;
	float Metal = 0.0f;

	float metalGatherRate = 0;
	float Coin = 0.0f;

	float coinGatherRate = 0.0f;
};

