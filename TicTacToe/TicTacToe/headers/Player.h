#pragma once
#include "GamePlayer.h"


class Player : public GamePlayer 
{
public:
	Player(char sign);
	std::pair<int, int> MakeMove() override;
};