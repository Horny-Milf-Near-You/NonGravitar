#include "Game.hpp"

// This one is the only "active" header included
#define OLC_PGE_APPLICATION
#include <olcPixelGameEngine.h>

int main(void)
{
	Game app;
	int constexpr appScale = 1;
	int constexpr appHeight = 720;
	int constexpr appWidth = 1280;

	if (app.Construct(appWidth, appHeight, appScale, appScale))
		app.Start();

	return 0;
}
