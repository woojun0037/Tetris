#include "Player.h"

Player::Player(Block& blockRef) : block(blockRef)
{
	playerCursor = { 5, 2 };
}

Player::~Player()
{
}

void Player::UpdateBlockPosition()
{
	memset(blockPosition, 0, sizeof(blockPosition));

	// 현재 블록 데이터를 blockPosition에 추가
	for (int y = 0; y < BLOCK_HEIGTH; ++y)
	{
		for (int x = 0; x < BLOCK_WIDTH; ++x)
		{
			if (block.GetBlockData()[(y * BLOCK_WIDTH) + x] != 0)
			{
				int worldY = playerCursor.Y + y;
				int worldX = playerCursor.X + x;

				if (worldY >= 0 && worldY < MAP_HEIGHT && worldX >= 0 && worldX < MAP_WIDTH)
				{
					blockPosition[worldY][worldX] = block.GetBlockData()[(y * BLOCK_WIDTH) + x];
				}
			}
		}
	}
}

void Player::Render(ConsoleManager& console)
{
	auto mapData = block.GetMapData();

	for (int y = 0; y < MAP_HEIGHT; ++y)
	{
		for (int x = 0; x < MAP_WIDTH; ++x)
		{
			int value = mapData[y][x];

			if (blockPosition[y][x] != 0)
			{
				value = blockPosition[y][x];
			}

			block.Render(console, y, x);
		}
	}
}
