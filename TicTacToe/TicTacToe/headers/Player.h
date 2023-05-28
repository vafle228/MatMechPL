#pragma once
#include "GameCore/GamePlayer.h"


class Player : public GamePlayer 
{
public:
	Player(char sign);
	void MakeMove(GameField* field) override;
};