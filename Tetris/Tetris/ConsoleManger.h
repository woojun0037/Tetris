#pragma once
#include <Windows.h>
#include "Structerts.h"

class ConsoleManager
{
public: 
	ConsoleManager();
	~ConsoleManager();

	void InitConsole();
	void DestroyConsole();
	void CleanScreen();
	void BufferFlip();

	HANDLE GetCurrentBuffer() const { return hBuffer[curBuffer] };

private:
	HANDLE hBuffer[2];
	stRect consoleSize;
	int curBuffer;
};