#pragma once
#include "ConsoleManger.h"
#include "Block.h"

class Player
{
public:
	Player(Block& block);
	~Player();

private:
	COORD playerCursor; //�÷��̾� ��ġ
	const Block& block; //������ ����
};