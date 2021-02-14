#pragma once

#include <stack>
#include "Core.hpp"

// O------------------------------------------------------------------------------O
// | Game: Global game class                                                      |
// O------------------------------------------------------------------------------O
class Game : public olc::PixelGameEngine
{
public:
	Game(uint16_t _initFuel = 500, uint16_t _initHealth = 100);

	// OnEvents functions
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	void OnUserPause();
	bool OnUserDestroy() override
	{
		Logger::Warning("Deallocating Game object");
		return (true);
	};

	bool IsKeyPressed(olc::Key keycode) { return GetKey(keycode).bHeld; };

private:
	inline bool canGameContinue() { return (mPlayerFuel > 0 && mPlayerHealth > 0); };

private:
	// Game enviroment variable
	uint16_t mPlayerScore;
	uint16_t mPlayerFuel;
	uint16_t mPlayerHealth;

	std::stack<std::unique_ptr<Scene>> mStackScene;
};