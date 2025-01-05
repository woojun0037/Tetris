#include "ConsoleManger.h"

ConsoleManager::ConsoleManager() : curBuffer(0)
{
	hBuffer[0] = nullptr;
	hBuffer[1] = nullptr;
}

ConsoleManager::~ConsoleManager()
{

}

void ConsoleManager::InitConsole()
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

void ConsoleManager::DestroyConsole()
{

}

void ConsoleManager::CleanScreen()
{

}

void ConsoleManager::BufferFlip()
{

}

