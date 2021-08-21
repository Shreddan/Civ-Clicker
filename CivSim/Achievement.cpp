#include "Achievement.h"


Achievement::Achievement()
{
}

Achievement::~Achievement()
{
}

void Achievement::checkSelf(int& checkTot) 
{	
	if (checkTot == 2)
	{
		this->isComplete = true;
	}

}

void Achievement::DrawSelf(olc::PixelGameEngine* pge)
{
}
