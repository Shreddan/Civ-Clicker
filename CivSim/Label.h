#pragma once
#include "olcPixelGameEngine.h"
#include "Civilisation.h"


class Label
{
public:
	Label(int x, int y, std::string lab1, olc::Pixel col, int id, int id2, int id3, float scale);
	~Label();
	void updateLabel(Civilisation* civ);
	void DrawSelf(olc::PixelGameEngine* pge) { pge->DrawStringDecal(olc::vf2d(this->x, this->y), this->lab + " " + this->reslab, this->col, olc::vf2d(this->scale, this->scale)); }

	int x;
	int y;
	std::string lab;
	std::string reslab = "";
	olc::Pixel col;
	int ID;
	int ID2;
	int ID3;
	float scale;
};

