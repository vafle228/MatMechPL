#pragma once
#include "GameAi/AIModes.h"
#include "GameCore/GameField.h"
#include "GameCore/GamePlayer.h"

#include "GameSolver/SolveGraph.h"


class Game 
{
public:
	Game(char player_sign, AIModes mode, SolveGraph* graph);
	
	void NextTurn();
	GameState State();

private:
	GamePlayer* active;
	GameField field = GameField();

	GamePlayer* player; GamePlayer* computer;
};
