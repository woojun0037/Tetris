#ifndef _CONSOLEMANAGER_H_
#define _CONSOLEMANAGER_H_

#include "Common.h"
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

	HANDLE GetCurrentBuffer() const { return hBuffer[curBuffer];}

private:
	HANDLE hBuffer[2];
	stRect consoleSize;
	stConsole console;
	int curBuffer;
};

#endif