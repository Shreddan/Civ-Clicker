#include "Button.h"

Button::Button()
{
}

Button::Button(int ox, int oy, int w, int h)
{
	this->originx = ox;
	this->originy = oy;
	this->w = w;
	this->h = h;
}

Button::~Button()
{
}

void Button::DrawSelf(olc::PixelGameEngine* pge)
{
	pge->FillRect(olc::vi2d(this->originx, this->originy), olc::vi2d(this->w, this->h), olc::DARK_GREY);
}
