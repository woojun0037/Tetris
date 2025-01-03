#pragma once
#include "Common.h"

class ConsoleManager
{
public: 
	ConsoleManager();
	~ConsoleManager();

	void InitConsole();
	void DestroyConsole();
	void CleanScreen();
	void BufferFlip();

	HANDLE GetCurrentBuffer
};