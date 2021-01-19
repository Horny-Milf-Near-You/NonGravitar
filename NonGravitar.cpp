#include <Game.hpp>

// This one is the only "active" header included
#define OLC_PGE_APPLICATION
#include <olcPixelGameEngine.h>


int main(void)
{
	Game app;
	if (app.Construct(SCREEN_WIDTH, SCREEN_HEIGHT, PIXEL_SCALE_WIDTH, PIXEL_SCALE_HEIGHT))
		app.Start();

	return 0;
}
