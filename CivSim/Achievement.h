#pragma once
#include <olcPixelGameEngine.h>

class Achievement
{
public:

	Achievement();
	~Achievement();

	void checkSelf(int& checkTot);
	void DrawSelf(olc::PixelGameEngine* pge);
	void DrawNotif(olc::PixelGameEngine* pge);

	std::string achName;
	int alpha;
	int State;
	bool isShown;
	bool isComplete;
};

