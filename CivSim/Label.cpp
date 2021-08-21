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

void Label::updateLabel( Civilisation* civ)
{
	switch (this->ID2)
	{
	case 0:
	{
		this->reslab = "";
		break;
	}
	case 1:
	{
		this->reslab = civ->getResAsString(this->ID2);
		break;
	}
	case 2:
	{
		this->reslab = civ->getResAsString(this->ID2);
		break;
	}
	case 3:
	{
		this->reslab = civ->getResAsString(this->ID2);
		break;
	}
	case 4:
	{
		this->reslab = civ->res->ftos(civ->res->Wood);
		break;
	}
	case 5:
	{
		this->reslab = civ->res->ftos(civ->res->Food);
		break;
	}
	case 6:
	{
		this->reslab = civ->res->ftos(civ->res->Stone);
		break;
	}
	case 7:
	{
		this->reslab = civ->res->ftos(civ->res->Metal);
		break;
	}
	case 8:
	{
		this->reslab = civ->res->ftos(civ->res->Coin);
		break;
	}
	}
}
