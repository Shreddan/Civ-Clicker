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
	Button(std::string label, int ox, int oy, int w, int h, int inter1, int inter2, olc::Pixel col);
	~Button();

	void DrawSelf(olc::PixelGameEngine* pge);
	void onHover(olc::PixelGameEngine* pge);
	std::pair<int, int> onInteract(olc::PixelGameEngine* pge);

	std::string label;
	int originx;
	int originy;
	int w;
	int h;
	std::pair<int, int> interaction;
	olc::Pixel col;
};

