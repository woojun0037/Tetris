#pragma once
#include "ConsoleManger.h"
#include "Block.h"

class Player
{
public:
	Player(Block& block);
	~Player();

	void UpdateBlockPosition();
	void Render(ConsoleManager& console);

private:
	Block& block;
	COORD playerCursor;
	int blockPosition[MAP_HEIGHT][MAP_WIDTH] = { 0 };
};