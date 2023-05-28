#include "../../headers/GameSolver/GraphRel.h"


#pragma region GameOutcome
GameOutcome::GameOutcome(int tie, int x_win, int x_lose)
	: tie(tie), x_win(x_win), x_lose(x_lose)
{ }

GameOutcome GameOutcome::operator+(GameOutcome& obj)
{
	return GameOutcome(tie + obj.tie, x_win + obj.x_win, x_lose + obj.x_lose);
}
#pragma endregion

#pragma region GraphRel
GraphRel::GraphRel(std::string rel, GameOutcome outcome)
	: rel(rel), outcome(outcome)
{ }

GraphRel GraphRel::operator+(GraphRel& obj)
{
	return GraphRel(rel, outcome + obj.outcome);
}

bool GraphRel::operator==(const GraphRel& obj) const
{
	return obj.rel == rel;
}
#pragma endregion