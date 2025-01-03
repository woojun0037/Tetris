#pragma once
#include "ConsoleManger.h"

constexpr int BLOCK_WIDTH = 4;
constexpr int BLOCK_HEIGTH = 4;

class Block
{
public:
	Block(int id);
	void Rotate();
	void Render(ConsoleManager& console);

private:
	int blockData[BLOCK_WIDTH * BLOCK_HEIGTH];
	int memSize;
};