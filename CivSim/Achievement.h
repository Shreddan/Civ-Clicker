#pragma once
#include <olcPixelGameEngine.h>

class Achievement
{
public:

	Achievement();
	~Achievement();

	void checkSelf(std::string& achieve, float& alpha0, bool& anotherHouseComplete, bool& farmHandComplete, bool& timberrrComplete, bool& expansionComplete);
	void DrawSelf(olc::PixelGameEngine* pge);

	std::string achName;
	int alpha;
	bool isShown;
};

