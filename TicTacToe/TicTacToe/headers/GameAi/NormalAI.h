#pragma once
#include "../GameCore/GamePlayer.h"
#include "../GameSolver/SolveGraph.h"


class NormalAI : public GamePlayer
{
public:
	NormalAI(char sign, SolveGraph* graph);
	
	void MakeMove(GameField* field) override;

private:
	SolveGraph* solve_graph;

	float CountMoveValue(GameOutcome outcome);
};