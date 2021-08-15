#include "Button.h"

Button::Button(std::string label, int ox, int oy, int w, int h)
{
	this->label = label;
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
	pge->DrawStringDecal(olc::vf2d(this->originx + 60, this->originy + 25), this->label, olc::BLACK, olc::vf2d(3.f, 3.f));
}

void Button::onHover(olc::PixelGameEngine* pge)
{
	if (pge->GetMouseX() > this->originx && pge->GetMouseX() < this->originx + this->w)
	{
		if (pge->GetMouseY() > this->originy && pge->GetMouseY() < this->originy + this->h)
		{
			pge->DrawRect(olc::vf2d(this->originx, this->originy), olc::vf2d(this->w, this->h), olc::YELLOW);
		}
	}
}
