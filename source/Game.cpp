#include "Game.hpp"


Game::Game(unsigned int _initFuel, unsigned int _initHealth)
{
	sAppName = "NonGravitar 2.0";
	nPlayerScore = 0;
	nPlayerFuel = _initFuel;
	nPlayerHealth = _initHealth;

}


bool Game::OnUserCreate()
{
	SetPixelMode(olc::Pixel::ALPHA);	
	print_debug_line(VERIFIED, "Game object created successfully");
	return (true);
}


bool Game::OnUserUpdate(float fElapsedTime)
{
	// CTRL+Q shortcut to close the application
	if (check_keyboard_shortcut(this, CTRL, Q))
        return (false);
	// CTRL+P shortcut for game pause
	else if (check_keyboard_shortcut(this, CTRL, P))
        OnUserPause();

	Clear(olc::Pixel(22, 26, 46));
	return (true);
}


bool Game::OnUserDestroy()
{
	return (true);
}


void Game::OnUserPause()
{	
	print_debug_line(WARNING, "Pause requested by the user");
}


inline bool Game::canGameContinue(void)
{
	return (nPlayerFuel > 0 && nPlayerHealth > 0);
}