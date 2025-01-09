#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "ConsoleManger.h"

constexpr int BLOCK_WIDTH = 4;
constexpr int BLOCK_HEIGTH = 4;

constexpr int MAP_WIDTH = 12;
constexpr int MAP_HEIGHT = 22;

constexpr int START_POS_X = 4;
constexpr int START_POS_Y = 1;

class Block
{
public:
	Block(int id);
	void Rotate();
	void Render(ConsoleManager& console, int yOffset, int xOffset);
	
	static const char BLOCK_TYPES[][4];
	static const int  BLOCKS[][BLOCK_WIDTH * BLOCK_HEIGTH];
	static const int  MAP[MAP_HEIGHT][MAP_WIDTH];

	const int* GetBlock    () const { return BLOCKS[id];}
	const int* GetBlockData() const { return blockData; }

	const int(*GetMapData())[MAP_WIDTH]{ return mapData;}

private:
	int id;
	int blockData[BLOCK_WIDTH * BLOCK_HEIGTH];
	int mapData[MAP_HEIGHT][MAP_WIDTH] = { 0, };
	int memSize;
};

#endif // !_BLOCK_H_