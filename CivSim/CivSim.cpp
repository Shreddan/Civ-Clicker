#define OLC_PGE_APPLICATION

#include "Engine.h"

int main()
{
	Engine engine;
	
	int width = 1200;
	int height = (width * 9) / 16;

	if (engine.Construct(width, height, 1, 1))
	{
		engine.Start();
	}
	return 0;

}


