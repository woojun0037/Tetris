#include "Player.h"

Player::Player(Block& blockRef) : block(blockRef)
{
	playerCursor = { 5, 2 };
	
	for (int y = 0; y < BLOCK_HEIGTH; ++y)
	{
		for (int x = 0; x < BLOCK_WIDTH; ++x)
		{
			if (block.GetBlock()[y * BLOCK_WIDTH + x] != 0)
			{
				//Block::BLOCK_TYPES[block.GetMapData  ()[playerCursor.Y + y][playerCursor.X + x]] = 
					               block.GetBlockData()[(y * BLOCK_HEIGTH) + x];
			}
		}
	}
}

Player::~Player()
{
}
