#include "../../headers/GameAi/SolveGraphAI.h"


const std::vector<int> ROTATION_MATRIX{ 2, 5, 8, 1, 4, 7, 0, 3, 6 };

SolveGraphAI::SolveGraphAI(char sign, SolveGraph* graph)
	: GamePlayer(sign), solve_graph(graph)
{ }

void SolveGraphAI::MakeMove(GameField* field)
{
	if (rotation_times == -1)
		rotation_times = GetRotationTime(field->ToString());

	auto game_states = solve_graph->GetOutcomes(
		RotateField(field->ToString(), rotation_times)
	);

	GraphRel max_rel = game_states[0];
	for (auto state_rel : game_states)
	{
		if (CountMoveValue(max_rel.outcome) < CountMoveValue(state_rel.outcome))
		{
			max_rel = state_rel;
		}
	}
	field->LoadField(RotateField(max_rel.rel, 4 - rotation_times));
}

int SolveGraphAI::GetRotationTime(std::string field)
{
	int rotation_count = 0;
	while (solve_graph->GetOutcomes(field).empty())
	{
		field = RotateField(field, 1); rotation_count++;
	}
	return rotation_count;
}

std::string SolveGraphAI::RotateField(std::string field, int count)
{
	std::string new_field(field);

	for (int _ = 0; _ < count; _++)
	{
		for (int i = 0; i < field.length(); i++)
			new_field[ROTATION_MATRIX[i]] = field[i];
		field = new_field;
	}
	return new_field;
}
