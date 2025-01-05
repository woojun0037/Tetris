#include "common.h"                      

constexpr int WIN_WIDTH = 70;
constexpr int WIN_HEIGHT = 60;

constexpr int MAP_WIDTH = 12;
constexpr int MAP_HEGITH = 22;

constexpr int START_POS_X = 4;
constexpr int START_POS_Y = 1;


//�ܼ� ���� ���� ���� ������ ���� ����ü

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
      0,0,0,0},//��

    { 0,0,0,0,
      0,2,0,0,
      0,2,2,0,
      0,0,2,0},//S

    { 0,0,0,0,
      0,2,0,0,
      2,2,2,0,
      0,0,0,0},//��

    { 0,0,0,0,
      0,0,2,0,
      0,2,2,0,
      0,2,0,0}//z
};

//Ű�Է� �Լ�
void Input()
{
    int nKey = 0;

    //Ű�Է��� �����Ǿ��� �� �Էµ� Ű�� �����´�. 
    if (_kbhit() > 0)
    {
        nKey = _getch();

        switch (nKey)
        {
            case eKeyCode::KEY_UP   : { break; }
            case eKeyCode::KEY_DOWN : { break; }
            case eKeyCode::KEY_LEFT : { break; }
            case eKeyCode::KEY_RIGHT: { break; }
            case eKeyCode::KEY_SPACE: { break; }
            case eKeyCode::KEY_R    : { break; }
        }
    }
}

//�ܼ� ���� �����Լ�
void DestroyGame()
{
    //�ܼ�ȭ�� ���۴� CloseHandle�� �̿��ؼ� �޸� ���� �ؾߵ�
    if (console.hBuffer[0] != nullptr)
    {
        CloseHandle(console.hBuffer[0]);
    }
    if (console.hBuffer[1] != nullptr)
    {
        CloseHandle(console.hBuffer[1]);
    }
}

//ȭ�� �����
void ClearScreen()
{
    COORD pos{ 0, };
    DWORD dwWritten = 0;

    unsigned size = console.rtConsole.m_Width * console.rtConsole.m_Height;//ȭ�� ������

    //�ܼ� ȭ�� ��ü�� ���⸦ �־ �� ȭ�� ����
    FillConsoleOutputCharacter(console.hConsole, ' ', size, pos, &dwWritten);
    SetConsoleCursorPosition(console.hConsole, pos);
}

//���� �ø�
void BufferFlip()
{
    //ȭ�� ���� ����
    SetConsoleActiveScreenBuffer(console.hBuffer[console.curBuffer]);
    //ȭ�� ���� �ε����� ��ü
    console.curBuffer = console.curBuffer ? 0 : 1;
}

int main()
{
    int curBlock[BLOCK_WIDTH * BLOCK_HEIGTH] = { 0, }; // ��� ���� * ����
    int memSize = sizeof(int) * BLOCK_HEIGTH * BLOCK_WIDTH; //�޸� ī�Ǹ� ���� ���� ���� ��ϻ����� * sizeof
    memcpy_s(curBlock, memSize, BLOCKS[1], memSize); //�޸� ����

    printf("");
    for (int rot = 0; rot < 1; ++rot)
    {
        int temp[BLOCK_WIDTH * BLOCK_HEIGTH] = { 0, };

        for (int y = 0; y < BLOCK_HEIGTH; ++y) //����
        {
            for (int x = 0; x < BLOCK_WIDTH; ++x) //����
            {
                temp[(x * BLOCK_WIDTH) + (BLOCK_HEIGTH - y - 1)] = curBlock[(y * BLOCK_HEIGTH) + x];
            }
        }
        memcpy_s(curBlock, memSize, temp, memSize);
    }
    printf("");

    while (true)
    {
        Input();

        ClearScreen();
        BufferFlip();
        Sleep(1);
    }

    DestroyGame();

    return 0;
}