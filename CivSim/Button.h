#pragma once
#include "olcPixelGameEngine.h"
#include "Engine.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <tuple>

class Button
{
public:
	Button(int ox, int oy, int w, int h);
	~Button();

	void DrawSelf(olc::PixelGameEngine* pge);
	

private:
	int originx;
	int originy;
	int w;
	int h;
};

