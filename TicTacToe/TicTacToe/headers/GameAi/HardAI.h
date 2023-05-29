#pragma once
#include "SolveGraphAI.h"


class HardAI : public SolveGraphAI
{
public:
	HardAI(char sign, SolveGraph* graph);

protected:
	float CountMoveValue(GameOutcome outcome) override;
};