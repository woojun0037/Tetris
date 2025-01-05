#include "InputManager.h"

eKeyCode InputManager::GetInput() 
{
    int nKey = 0;

    if (_kbhit() > 0)
    {
        switch (nKey)
        {
            case eKeyCode::KEY_UP   : break;
            case eKeyCode::KEY_DOWN : break;
            case eKeyCode::KEY_LEFT : break;
            case eKeyCode::KEY_RIGHT: break;
            case eKeyCode::KEY_SPACE: break;
            case eKeyCode::KEY_R    : break;
        }
    }
}