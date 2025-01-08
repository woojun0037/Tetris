#pragma once
#include "ConsoleManger.h"
#include "Block.h"

class Player
{
public:
	Player(Block& block);
	~Player();

private:
	COORD playerCursor; //플레이어 위치
	const Block& block; //참조로 저장
};