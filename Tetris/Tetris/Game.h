#pragma once
#include "ConsoleManger.h"
#include "InputManager.h"
#include "Block.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void Init();
	void RunGame();
	void CleanUp();

private:
	ConsoleManager consoleManager;
	InputManager   inputManager;
	Block*         currentBlock;
};