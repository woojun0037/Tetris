#ifndef _STRUCTERTS_H_
#define _STRUCTERTS_H_

#include <Windows.h>

//키 값
enum eKeyCode
{
    KEY_UP    = 72, //방향키 ↑
    KEY_DOWN  = 80, //방향키 ↓
    KEY_LEFT  = 75, //방향키 ←
    KEY_RIGHT = 77, //방향키 →
    KEY_SPACE = 32, //스페이스바
    KEY_R     = 114 //R키
};

//Rectangle 구조체
struct stRect
{
    int m_Width;
    int m_Height;
};

struct stConsole
{
    //Console 제어 용도
    HANDLE hConsole;
    //Console 더블 버퍼를 사용하기 위해
    HANDLE hBuffer[2];

    stRect rtConsole;
    //현재 버퍼 체크
    int curBuffer;

    //맴버 초기화
    stConsole() : hConsole(nullptr), hBuffer{ nullptr, }, curBuffer(0){}
};

#endif