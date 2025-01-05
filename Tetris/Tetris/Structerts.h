#pragma once

//키 값
enum eKeyCode
{
    KEY_UP = 72, //방향키 ↑
    KEY_DOWN = 80, //방향키 ↓
    KEY_LEFT = 75, //방향키 ←
    KEY_RIGHT = 77, //방향키 →
    KEY_SPACE = 32, //스페이스바
    KEY_R = 114 //R키
};

//Rectangle 구조체
struct stRect
{
    int m_Width;
    int m_Height;
};
