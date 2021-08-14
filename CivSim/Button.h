#pragma once
#include "olcPixelGameEngine.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <tuple>

class Button
{
public:
	Button();
	Button(std::string label, int ox, int oy, int w, int h);
	~Button();

	void DrawSelf(olc::PixelGameEngine* pge);

	std::string label;
	int originx;
	int originy;
	int w;
	int h;
};

