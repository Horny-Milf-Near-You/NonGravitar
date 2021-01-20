#include "Game.hpp"

Game::Game(uint16_t _initFuel, uint16_t _initHealth)
{
	sAppName = "NonGravitar 2.0";
	mPlayerScore = 0;
	mPlayerFuel = _initFuel;
	mPlayerHealth = _initHealth;
}

bool Game::OnUserCreate()
{
	SetPixelMode(olc::Pixel::ALPHA);
	Logger::Verified("Game object created successfully");
	return (true);
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	// CTRL+Q shortcut to close the application
	if (IsKeyPressed(olc::Key::CTRL) && IsKeyPressed(olc::Key::Q))
		return (false);
	// CTRL+P shortcut for game pause
	else if (IsKeyPressed(olc::Key::CTRL) && IsKeyPressed(olc::Key::P))
		OnUserPause();

	Clear(olc::Pixel(22, 26, 46));
	return (true);
}

void Game::OnUserPause()
{
	Logger::Warning("Pause requested by the user");
	// ToDo add real pause
}