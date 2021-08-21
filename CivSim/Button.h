#pragma once
#include "Label.h"

class Button
{
public:
	
	Button(std::string label, int ox, int oy, int w, int h, int inter1, int inter2, olc::Pixel col, int tSize, bool hasText = false, olc::Pixel tcol = olc::BLACK);
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
	int tScale;
	bool hasText;
};

