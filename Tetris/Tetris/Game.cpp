#include "Game.h"

Game::Game() : currentBlock(nullptr) 
{

}
Game::~Game(){}

void Game::Init()
{
    consoleManager.InitConsole();
    currentBlock = new Block(0); //ó�� ��� ����
}

void Game::RunGame()
{
    while (true) 
    {
        eKeyCode key = inputManager.GetInput();
        if (key == KEY_R) currentBlock->Rotate();

        consoleManager.CleanScreen();
        currentBlock->Render(consoleManager);

        Sleep(100);
    }
}

void Game::CleanUp()
{
    delete currentBlock;
    consoleManager.DestroyConsole();
}
