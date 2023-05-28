#pragma once
#include "../GameCore/GamePlayer.h"


class EasyAI : public GamePlayer 
{
public:
	EasyAI(char sign);
	void MakeMove(GameField* field) override;
};