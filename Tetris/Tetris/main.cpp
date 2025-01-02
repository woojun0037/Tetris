#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <conio.h>                      


constexpr int WIN_WIDTH = 70;
constexpr int WIN_HEIGHT = 60;

constexpr int MAP_WIDTH = 12;
constexpr int MAP_HEGITH = 22;

constexpr int BLOCK_WIDTH = 4;
constexpr int BLOCK_HEIGTH = 4;

constexpr int START_POS_X = 4;
constexpr int START_POS_Y = 1;

//Ű ��
enum eKeyCode
{
    KEY_UP = 72, //����Ű ��
    KEY_DOWN = 80, //����Ű ��
    KEY_LEFT = 75, //����Ű ��
    KEY_RIGHT = 77, //����Ű ��
    KEY_SPACE = 32, //�����̽���
    KEY_R = 114 //RŰ
};

//Rectangle ����ü
struct stRect
{
    int m_Width;
    int m_Height;
};

//�ܼ� ���� ���� ���� ������ ���� ����ü
struct stConsole
{
    //Console ���� �뵵
    HANDLE hConsole;
    //Console ���� ���۸� ����ϱ� ����
    HANDLE hBuffer[2];

    stRect rtConsole;
    //���� ���� üũ
    int curBuffer;

    //�ɹ� �ʱ�ȭ
    stConsole() : hConsole(nullptr), hBuffer{ nullptr, }, curBuffer(0)
    {

    }
}; stConsole console;

const int Blocks[][BLOCK_WIDTH * BLOCK_HEIGTH] =
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
        case eKeyCode::KEY_UP: { break; }
        case eKeyCode::KEY_DOWN: { break; }
        case eKeyCode::KEY_LEFT: { break; }
        case eKeyCode::KEY_RIGHT: { break; }
        case eKeyCode::KEY_SPACE: { break; }
        case eKeyCode::KEY_R: { break; }
        }
    }
}

//�ܼ� ������ �ʱ� ������
void InitGame(bool initConsole = true)
{
    //���� �ܼ��� �ڵ��� �޾ƿ�
    console.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //���� �ܼ� ������ �ε����� 0���� �ʱ�ȭ
    console.curBuffer = 0;

    //�ܼ� ���� ����
    CONSOLE_CURSOR_INFO consoleCursor{ 1, FALSE }; //�ܼ��� Ŀ�� �������� �����մϴ�.
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo{ 0, }; //�ܼ� ȭ�� ������ ���� ������ ��� ����ü

    //���� �ܼ� ȭ�� ������ ���� ������ �������� winAPI �Լ�
    //consoleinfo�� ������ ����
    GetConsoleScreenBufferInfo(console.hConsole, &consoleInfo);

    consoleInfo.dwSize.X = 40; // ����
    consoleInfo.dwSize.Y = 30; // ����

    //�ܼ��� ũ�⸦ �ٽ� ���(���߿� �׸� �׸��� ���)
    console.rtConsole.m_Width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
    console.rtConsole.m_Height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top;

    //�ܼ��� ù��° ȭ�� ���� ����
    console.hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    SetConsoleScreenBufferSize(console.hBuffer[0], consoleInfo.dwSize);   //ȭ�� ���� ũ�� ����
    SetConsoleWindowInfo(console.hBuffer[0], TRUE, &consoleInfo.srWindow);//�ܼ� ����
    SetConsoleCursorInfo(console.hBuffer[0], &consoleCursor);             //�ܼ��� Ŀ�� ����

    //�ܼ��� �ι�° ȭ�� ���� ����
    console.hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(console.hBuffer[1], consoleInfo.dwSize);
    SetConsoleWindowInfo(console.hBuffer[1], TRUE, &consoleInfo.srWindow);
    SetConsoleCursorInfo(console.hBuffer[1], &consoleCursor);
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
    InitGame();

    char chBuffer[256] = { 0, };
    COORD coord{ 0, 0 };
    DWORD dw = 0;

    while (true)
    {
        memset(chBuffer, 0, sizeof(chBuffer));
        int len = sprintf_s(chBuffer, sizeof(chBuffer), "TEST");
        SetConsoleCursorPosition(console.hBuffer[console.curBuffer], coord);
        WriteFile(console.hBuffer[console.curBuffer], chBuffer, len, &dw, NULL);

        ClearScreen();
        BufferFlip();
        Sleep(1);
    }

    DestroyGame();

    return 0;
}