#ifndef _STRUCTERTS_H_
#define _STRUCTERTS_H_

#include <Windows.h>

//Ű ��
enum eKeyCode
{
    KEY_UP    = 72, //����Ű ��
    KEY_DOWN  = 80, //����Ű ��
    KEY_LEFT  = 75, //����Ű ��
    KEY_RIGHT = 77, //����Ű ��
    KEY_SPACE = 32, //�����̽���
    KEY_R     = 114 //RŰ
};

//Rectangle ����ü
struct stRect
{
    int m_Width;
    int m_Height;
};

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
    stConsole() : hConsole(nullptr), hBuffer{ nullptr, }, curBuffer(0){}
};

#endif