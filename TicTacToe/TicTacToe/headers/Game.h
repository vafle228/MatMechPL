#pragma once
#include "GameAi/AIModes.h"
#include "GameCore/GameField.h"
#include "GameCore/GamePlayer.h"


class Game 
{
public:
	Game(char player_sign, AIModes mode);
	
	void NextTurn();
	GameState State();

private:
	GamePlayer* active;
	GameField field = GameField();

	GamePlayer* player; GamePlayer* computer;
};
