#include "Label.h"

Label::Label(int x, int y, std::string lab1, olc::Pixel col, int id, int id2, float scale)
{
	this->x = x;
	this->y = y;
	this->lab = lab1;
	this->col = col;
	this->ID = id;
	this->ID2 = id2;
	this->scale = scale;
}

Label::~Label()
{
}

void Label::updateLabel(int& id2, Civilisation* civ)
{
	switch (id2)
	{
	case 0:
	{
		this->reslab = "";
		break;
	}
	case 1:
	{
		this->reslab = civ->getResAsString(id2);
		break;
	}
	case 2:
	{
		this->reslab = civ->getResAsString(id2);
		break;
	}
	}
}
