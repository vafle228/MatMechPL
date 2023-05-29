#include "../../headers/GameAi/HardAI.h"


HardAI::HardAI(char sign, SolveGraph* graph)
	: SolveGraphAI(sign, graph)
{ }

float HardAI::CountMoveValue(GameOutcome outcome)
{
	float tie = outcome.tie;
	float self_win = (sign == 'O' ? outcome.x_lose : outcome.x_win);
	float self_lose = (sign == 'O' ? outcome.x_win : outcome.x_lose);

	if (self_win / (self_win + tie + self_lose) < 0.9) 
		return 4 * self_win + 2 * tie + self_lose;
	return INT_MAX;
}