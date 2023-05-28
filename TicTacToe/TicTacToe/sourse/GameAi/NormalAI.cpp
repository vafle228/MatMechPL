#include "../../headers/GameAi/NormalAI.h"


NormalAI::NormalAI(char sign, SolveGraph* graph)
	: GamePlayer(sign), solve_graph(graph)
{ }

float NormalAI::CountMoveValue(GameOutcome outcome)
{
	float tie = outcome.tie;
	float self_win = (sign == 'O' ? outcome.x_lose : outcome.x_win);
	float self_lose = (sign == 'O' ? outcome.x_win : outcome.x_lose);

	return 4 * tie + 2 * self_lose + 0.5 * self_win;

}

void NormalAI::MakeMove(GameField* field)
{
	auto game_states = solve_graph->GetOutcomes(field->ToString());
	
	GraphRel max_rel = game_states[0];
	for (auto state_rel : game_states) 
	{
		if (CountMoveValue(max_rel.outcome) < CountMoveValue(state_rel.outcome))
		{
			max_rel = state_rel;
		}
	}
	field->LoadField(max_rel.rel);
}