#pragma once
#include "../GameCore/GamePlayer.h"
#include "../GameSolver/SolveGraph.h"


class SolveGraphAI : public GamePlayer 
{
public:
	SolveGraphAI(char sign, SolveGraph* graph);

	void MakeMove(GameField* field) override;

private:
	int rotation_times = -1;
	SolveGraph* solve_graph;

	int GetRotationTime(std::string field);
	std::string RotateField(std::string field, int count);

protected: virtual float CountMoveValue(GameOutcome outcome) = 0;
};