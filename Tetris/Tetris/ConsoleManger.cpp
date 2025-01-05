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
    //현재 콘솔의 핸들을 받아옴
    console.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //현재 콘솔 버퍼의 인덱스를 0으로 초기화
    console.curBuffer = 0;

    //콘솔 관련 설정
    CONSOLE_CURSOR_INFO consoleCursor{ 1, FALSE }; //콘솔의 커서 깜빡임을 제거합니다.
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo{ 0, }; //콘솔 화면 버퍼의 상태 정보를 담는 구조체

    //현재 콘솔 화면 버퍼의 상태 정보를 가져오는 winAPI 함수
    //consoleinfo로 정보를 받음
    GetConsoleScreenBufferInfo(console.hConsole, &consoleInfo);

    consoleInfo.dwSize.X = 40; // 가로
    consoleInfo.dwSize.Y = 30; // 세로

    //콘솔의 크기를 다시 계산(나중에 그림 그릴때 사용)
    console.rtConsole.m_Width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
    console.rtConsole.m_Height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top;

    //콘솔의 첫번째 화면 버퍼 생성
    console.hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    SetConsoleScreenBufferSize(console.hBuffer[0], consoleInfo.dwSize);   //화면 버퍼 크기 설정
    SetConsoleWindowInfo(console.hBuffer[0], TRUE, &consoleInfo.srWindow);//콘솔 설정
    SetConsoleCursorInfo(console.hBuffer[0], &consoleCursor);             //콘솔의 커서 설정

    //콘솔의 두번째 화면 버퍼 생성
    console.hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(console.hBuffer[1], consoleInfo.dwSize);
    SetConsoleWindowInfo(console.hBuffer[1], TRUE, &consoleInfo.srWindow);
    SetConsoleCursorInfo(console.hBuffer[1], &consoleCursor);
}

void ConsoleManager::DestroyConsole()
{
    //버퍼가 사용중이라면 CloseHandle로 버퍼 클리어
    if (hBuffer[0] != nullptr) CloseHandle(hBuffer[0]);
    if (hBuffer[1] != nullptr) CloseHandle(hBuffer[1]);
}

void ConsoleManager::CleanScreen()
{
    COORD pos{ 0, };
    DWORD dwWritten = 0;

    unsigned size = console.rtConsole.m_Width * console.rtConsole.m_Height;//화면 사이즈

    //콘솔 화면 전체를 띄어쓰기를 넣어서 빈 화면 생성
    FillConsoleOutputCharacter(console.hConsole, ' ', size, pos, &dwWritten);
    SetConsoleCursorPosition(console.hConsole, pos);
                                                                                
}

void ConsoleManager::BufferFlip()
{
    SetConsoleActiveScreenBuffer(hBuffer[curBuffer]);
    curBuffer = curBuffer ? 0 : 1;
}

