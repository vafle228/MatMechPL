#pragma once
#include "AIModes.h"
#include "GameField.h"
#include "GamePlayer.h"


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
