#pragma once

#include <Core.hpp>
#include <olcPixelGameEngine.h>


// O------------------------------------------------------------------------------O
// | Game: Global game class                                                      |
// O------------------------------------------------------------------------------O
class Game : public olc::PixelGameEngine
{
public:
	Game(unsigned int _initFuel = 20, unsigned int _initHealth = 10);

	// OnEvents functions
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;
	void OnUserPause();

private:
	inline bool canGameContinue(void);

private:
	// Game enviroment variable
	unsigned int nPlayerScore;
	unsigned int nPlayerFuel;
	unsigned int nPlayerHealth;
};