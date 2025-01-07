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

	int GetCurBuffer() const { return curBuffer; }
	void SetCurBuffer(int bufferIndex)
	{
		if (bufferIndex >= 0 && bufferIndex < 2) curBuffer = bufferIndex;
	}

private:
	HANDLE hBuffer[2];
	stRect consoleSize;
	stConsole console;
	int curBuffer;
};

#endif