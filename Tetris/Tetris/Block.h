#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "ConsoleManger.h"

class Block
{
public:
	Block(int id);
	void Rotate();
	void Render(ConsoleManager& console);

private:
	int blockData[BLOCK_WIDTH * BLOCK_HEIGTH];
	int mapData[MAP_WIDTH * MAP_HEGITH];
	int memSize;
};

#endif // !_BLOCK_H_