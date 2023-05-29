#pragma once
#include "SolveGraphAI.h"


class NormalAI : public SolveGraphAI
{
public:
	NormalAI(char sign, SolveGraph* graph);

protected:
	float CountMoveValue(GameOutcome outcome) override;
};