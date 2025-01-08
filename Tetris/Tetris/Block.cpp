#include "Block.h"
#include <stdio.h>

const int Block::BLOCKS[][BLOCK_WIDTH * BLOCK_HEIGTH] =
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

const int Block::MAP[MAP_HEGITH][MAP_WIDTH] =
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

const char Block::BLOCK_TYPES[][4] =
{
    "   ",
    "¢Ã",
    "¡à",
};

Block::Block(int id) : id(id)
{
    memcpy_s(blockData, sizeof(blockData), BLOCKS[id], sizeof(blockData));
    memSize = BLOCK_WIDTH * BLOCK_HEIGTH * sizeof(int);
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
    COORD coord{ 0, };
    DWORD dw = 0;
    int xAdd = 0;

    HANDLE hBuffer = console.GetCurrentBuffer();

    for (int y = 0; y < MAP_HEGITH; ++y)
    {
        xAdd = 0;
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            if (blockData[y * BLOCK_WIDTH + x] != 0)
            {
                coord.X = xAdd + xOffset;
                coord.Y = y + yOffset;

                SetConsoleCursorPosition(hBuffer, coord);
                WriteFile(hBuffer, BLOCK_TYPES[MAP[y][x]], sizeof(BLOCK_TYPES[MAP[y][x]]), & dw, NULL);
            }
            xAdd += 1;
            if (BLOCK_TYPES[MAP[y][x]] == 0)
                xAdd += 1;
        }
    }

   
}
