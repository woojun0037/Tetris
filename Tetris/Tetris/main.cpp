#include "common.h"                      

constexpr int WIN_WIDTH = 70;
constexpr int WIN_HEIGHT = 60;

constexpr int MAP_WIDTH = 12;
constexpr int MAP_HEGITH = 22;

constexpr int START_POS_X = 4;
constexpr int START_POS_Y = 1;


//콘솔 관련 설정 값을 가지고 있을 구조체

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

//키입력 함수
void Input()
{
    int nKey = 0;

    //키입력이 감지되었을 때 입력된 키를 가져온다. 
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

//콘솔 버퍼 해제함수
void DestroyGame()
{
    //콘솔화면 버퍼는 CloseHandle을 이용해서 메모리 해제 해야됨
    if (console.hBuffer[0] != nullptr)
    {
        CloseHandle(console.hBuffer[0]);
    }
    if (console.hBuffer[1] != nullptr)
    {
        CloseHandle(console.hBuffer[1]);
    }
}

//화면 지우기
void ClearScreen()
{
    COORD pos{ 0, };
    DWORD dwWritten = 0;

    unsigned size = console.rtConsole.m_Width * console.rtConsole.m_Height;//화면 사이즈

    //콘솔 화면 전체를 띄어쓰기를 넣어서 빈 화면 생성
    FillConsoleOutputCharacter(console.hConsole, ' ', size, pos, &dwWritten);
    SetConsoleCursorPosition(console.hConsole, pos);
}

//버퍼 플립
void BufferFlip()
{
    //화면 버퍼 설정
    SetConsoleActiveScreenBuffer(console.hBuffer[console.curBuffer]);
    //화면 버퍼 인덱스를 교체
    console.curBuffer = console.curBuffer ? 0 : 1;
}

int main()
{
    int curBlock[BLOCK_WIDTH * BLOCK_HEIGTH] = { 0, }; // 블록 가로 * 세로
    int memSize = sizeof(int) * BLOCK_HEIGTH * BLOCK_WIDTH; //메모리 카피를 위한 가로 세로 블록사이즈 * sizeof
    memcpy_s(curBlock, memSize, BLOCKS[1], memSize); //메모리 복사

    printf("");
    for (int rot = 0; rot < 1; ++rot)
    {
        int temp[BLOCK_WIDTH * BLOCK_HEIGTH] = { 0, };

        for (int y = 0; y < BLOCK_HEIGTH; ++y) //세로
        {
            for (int x = 0; x < BLOCK_WIDTH; ++x) //가로
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