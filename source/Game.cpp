#include "Game.hpp"
#include "SharedScenes.hpp"

Game::Game(uint16_t _initFuel, uint16_t _initHealth)
	: mPlayerScore(0), mPlayerFuel(_initFuel), mPlayerHealth(_initHealth)
{
	sAppName = "NonGravitar 2.0";
}

bool Game::OnUserCreate()
{
	SetPixelMode(olc::Pixel::ALPHA);
	Logger::Verified("Game object created successfully");
	mStackScene.push(std::make_unique<WelcomeScene>());
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

	// Reset the canvas to blank
	Clear(olc::Pixel(22, 26, 46));

	if (mStackScene.empty())
	{
		Logger::Error("The Scene Stack must always contain at least one scene!");
		return false;
	}

	mStackScene.top()->Render(*this, fElapsedTime);

	return (true);
}

void Game::OnUserPause()
{
	Logger::Warning("Pause requested by the user");
	// Create PauseScene with pause menu
	mStackScene.push(std::make_unique<PauseScene>());
}
