#pragma once
#include <vector>


class GamePlayer 
{
public:
	const char sign;
	
	GamePlayer(char sign);
	virtual std::pair<int, int> MakeMove() = 0;
};


inline GamePlayer::GamePlayer(char sign) 
	: sign(sign) 
{ }
