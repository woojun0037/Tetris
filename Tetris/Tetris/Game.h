#pragma once
#include "ConsoleManger.h"
#include "InputManager.h"
#include "Block.h"

class Game
{
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