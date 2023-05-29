#include "../../headers/GameAi/NormalAI.h"


NormalAI::NormalAI(char sign, SolveGraph* graph)
	: SolveGraphAI(sign, graph)
{ }

float NormalAI::CountMoveValue(GameOutcome outcome)
{
	float tie = outcome.tie;
	float self_win = (sign == 'O' ? outcome.x_lose : outcome.x_win);
	float self_lose = (sign == 'O' ? outcome.x_win : outcome.x_lose);

	return 4 * tie + 2 * self_lose + 0.5 * self_win;
}
