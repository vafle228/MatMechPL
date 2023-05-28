#pragma once
#include "../GameCore/GamePlayer.h"


class EasyAI : public GamePlayer 
{
public:
	EasyAI(char sign);
	std::pair<int, int> MakeMove() override;
};