#include "Block.h"
#include <stdio.h>

const int BLOCKS[][BLOCK_WIDTH * BLOCK_HEIGTH] =
{
    { 0,0,0,0,
      2,2,2,2,
      0,0,0,0,
      0,0,0,0 },// I

    { 0,0,0,0,
      0,0,2,0,
      0,0,2,0,
      0,2,2,0 },//J

    { 0,0,0,0,
      0,2,0,0,
      0,2,0,0,
      0,2,2,0 },//L

    { 0,0,0,0,
      0,2,2,0,
      0,2,2,0,
      0,0,0,0},//¤±

    { 0,0,0,0,
      0,2,0,0,
      0,2,2,0,
      0,0,2,0},//S

    { 0,0,0,0,
      0,2,0,0,
      2,2,2,0,
      0,0,0,0},//¤Ç

    { 0,0,0,0,
      0,0,2,0,
      0,2,2,0,
      0,2,0,0}//z
};

const int MAP[MAP_HEIGHT][]
Block::Block(int id)
{
    memcpy_s(blockData, sizeof(blockData), BLOCKS[id], sizeof(blockData));
    memSize = sizeof(blockData);
}

void Block::Rotate()
{
    printf("");
    int temp[BLOCK_WIDTH * BLOCK_HEIGTH] = { 0 };

    for (int y = 0; y < BLOCK_HEIGTH; ++y)
    {                                                                                      
        for (int x = 0; x < BLOCK_WIDTH; ++x)
        {
            temp[(x * BLOCK_WIDTH) + (BLOCK_HEIGTH - y - 1)] = blockData[(y * BLOCK_HEIGTH) + x];
        }
    }
    memcpy_s(blockData, memSize, temp, memSize);
    printf("");
}

void Block::Render(ConsoleManager& console)
{
    HANDLE hBuffer = console.GetCurrentBuffer();
}
