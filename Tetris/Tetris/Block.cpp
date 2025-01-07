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

const int MAP[MAP_HEGITH][MAP_WIDTH] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,0,0,1,},
    {1,1,1,1,1,1,1,1,1,1,1,1,},
};

const char BLOCK_TYPES[][4] =
{
    "   ",
    "¢Ã",
    "¡à",
};

Block::Block(int id)
{
    memcpy_s(blockData, sizeof(blockData), BLOCKS[id], sizeof(blockData));
    memSize = sizeof(blockData);
}

void Block::Rotate()
{
    int temp[BLOCK_WIDTH * BLOCK_HEIGTH] = { 0 };

    for (int y = 0; y < BLOCK_HEIGTH; ++y)
    {                                                                                      
        for (int x = 0; x < BLOCK_WIDTH; ++x)
        {
            temp[(x * BLOCK_WIDTH) + (BLOCK_HEIGTH - y - 1)] = blockData[(y * BLOCK_HEIGTH) + x];
        }
    }
    memcpy_s(blockData, memSize, temp, memSize);
}

void Block::Render(ConsoleManager& console, int yOffset, int xOffset)
{
    HANDLE hBuffer = console.GetCurrentBuffer();
    COORD coord{ 0, };
    DWORD dw = 0;
    int xAdd = 0;

    for (int y = 0; y < MAP_HEGITH; ++y)
    {
        xAdd = 0;
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            coord.X = xAdd + xOffset;
            coord.Y = y + yOffset;

            SetConsoleCursorPosition(hBuffer[console.curBuffer])
        }
    }

   
}
