#pragma once
#include "../GameCore/GamePlayer.h"
#include "../GameSolver/SolveGraph.h"


class HardAI : public GamePlayer
{
public:
	HardAI(char sign, SolveGraph* graph);

	void MakeMove(GameField* field) override;

private:
	SolveGraph* solve_graph;

	float CountMoveValue(GameOutcome outcome);
};