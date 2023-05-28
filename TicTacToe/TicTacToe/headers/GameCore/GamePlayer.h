#pragma once
#include <vector>

#include "GameField.h"


class GamePlayer 
{
public:
	GamePlayer(char sign);
	virtual void MakeMove(GameField* field) = 0;

protected: const char sign;
};


inline GamePlayer::GamePlayer(char sign) 
	: sign(sign) 
{ }
