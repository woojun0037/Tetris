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
      0,0,0,0},//ㅁ

    { 0,0,0,0,
      0,2,0,0,
      0,2,2,0,
      0,0,2,0},//S

    { 0,0,0,0,
      0,2,0,0,
      2,2,2,0,
      0,0,0,0},//ㅗ

    { 0,0,0,0,
      0,0,2,0,
      0,2,2,0,
      0,2,0,0}//z
};

const int Block::MAP[MAP_HEIGHT][MAP_WIDTH] =
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
    "▣",
    "□",
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

    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        xAdd = 0;
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            if (blockData[y * BLOCK_WIDTH + x] != 0)  // 블록 데이터가 0이 아니면
            {
                coord.X = xAdd + xOffset;  // x좌표는 xAdd와 xOffset의 합
                coord.Y = y + yOffset;     // y좌표는 y + yOffset

                SetConsoleCursorPosition(hBuffer, coord);  // 콘솔 커서 위치 설정
                WriteFile(hBuffer, BLOCK_TYPES[blockData[y * BLOCK_WIDTH + x]], sizeof(BLOCK_TYPES[0]), &dw, NULL);  // 블록 출력
            }
            xAdd += 1;
            if (blockData[y * BLOCK_WIDTH + x] == 0)  // 만약 블록 데이터가 0이면 xAdd 증가
                xAdd += 1;
        }
    }
}
