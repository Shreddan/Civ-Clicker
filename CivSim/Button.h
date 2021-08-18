#pragma once
#include "olcPixelGameEngine.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <tuple>
#include <deque>

struct Label
{
	Label(int x, int y, std::string lab, olc::Pixel col) { this->x = x, this->y = y, this->lab = lab, this->col = col; }
	
	void toggleShow() { this->isShown = !isShown; }
	void updateLabel(std::string in) { if (lab != in) { this->lab = in; } }

private:

	int x;
	int y;
	std::string lab;
	olc::Pixel col;
	bool isShown;
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

