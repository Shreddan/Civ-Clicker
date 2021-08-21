#include "Button.h"

Button::Button(std::string label, int ox, int oy, int w, int h, int inter1, int inter2, olc::Pixel col, olc::Pixel tcol)
{
	this->label = label;
	this->originx = ox;
	this->originy = oy;
	this->w = w;
	this->h = h;
	this->interaction = std::make_pair(inter1, inter2);
	this->col = col;
	this->tCol = tcol;
}

Button::~Button()
{
}

void Button::DrawSelf(olc::PixelGameEngine* pge)
{
	pge->FillRect(olc::vi2d(this->originx, this->originy), olc::vi2d(this->w, this->h), this->col);
	pge->DrawStringDecal(olc::vf2d(this->originx + (this->w / 3), this->originy + (this->h / 3)), this->label, this->tCol, olc::vf2d(3.f, 3.f));
}

bool Button::onHover(olc::PixelGameEngine* pge)
{
	if (pge->GetMouseX() > this->originx && pge->GetMouseX() < this->originx + this->w)
	{
		if (pge->GetMouseY() > this->originy && pge->GetMouseY() < this->originy + this->h)
		{
			pge->DrawRect(olc::vf2d(this->originx, this->originy), olc::vf2d(this->w, this->h), olc::YELLOW);
			return true;
		}
	}
	return false;
}

bool Button::onInteract(olc::PixelGameEngine* pge)
{
	if (onHover(pge))
	{
		if (pge->GetMouse(0).bPressed)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
