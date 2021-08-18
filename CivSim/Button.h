#pragma once
#include "olcPixelGameEngine.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <tuple>
#include <deque>

struct Label
{
	Label(int x, int y, std::string lab, olc::Pixel col, int id, float scale) { this->x = x, this->y = y, this->lab = lab, this->col = col, this->ID = id, this->scale = scale; }
	void updateLabel(std::string in) { if (lab != in) { this->lab = in; } }
	void DrawSelf(olc::PixelGameEngine* pge) { pge->DrawStringDecal(olc::vf2d(this->x, this->y), this->lab, this->col, olc::vf2d(this->scale, this->scale)); }

	int x;
	int y;
	std::string lab;
	olc::Pixel col;
	int ID;
	float scale;
};

class Button
{
public:
	
	Button(std::string label, int ox, int oy, int w, int h, int inter1, int inter2, olc::Pixel col, olc::Pixel tcol = olc::BLACK);
	~Button();

	void DrawSelf(olc::PixelGameEngine* pge);
	bool onHover(olc::PixelGameEngine* pge);
	bool onInteract(olc::PixelGameEngine* pge);

	std::string label;
	int originx;
	int originy;
	int w;
	int h;
	std::pair<int, int> interaction;
	olc::Pixel col;
	olc::Pixel tCol;
};

