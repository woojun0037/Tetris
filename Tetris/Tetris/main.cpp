#include "Common.h"

int main()
{
    Game game;

    game.Init();
    game.RunGame();
    game.CleanUp();

    return 0;
}