#include "../../headers/GameCore/GameField.h"
#include "../../headers/GameSolver/SolveGraph.h"


SolveGraph::SolveGraph()
{
}

Outcomes SolveGraph::GetOutcomes(std::string field)
{
	return Outcomes();
}

void SolveGraph::DumpGameGraph()
{
}

void SolveGraph::LoadGameGraph()
{
}

GameOutcome GenerateGraph(GameField field, char sign, GameGraph graph)
{
	GameState state = field.CheckState();
	
	if (state != GameState::Game)
	{
		return GameOutcome(
			state == GameState::Tie,
			state == GameState::XWin,
			state == GameState::XLose
		);
	}
	else 
	{
		GameOutcome outcomes = GameOutcome(0, 0, 0);
		std::string current_field = field.ToString();

		if (graph.find(current_field) == graph.end())
			graph[current_field] = Outcomes();
		
		for (int row = 0; row < SIZE; row++) 
		{
			for (int col = 0; col < SIZE; col++) 
			{
				try { field.DoMove(row, col, sign); }
				catch (const std::exception&) { continue; }

				auto outcome = GenerateGraph(field, sign == 'X' ? 'O' : 'X', graph);
				
				GraphRel relation = GraphRel(field.ToString(), outcome);
				auto find_res{ std::find(graph[current_field].begin(), graph[current_field].end(), relation) };
				
				if (find_res != graph[current_field].end())
				{
					find_res->operator+(relation);
				}
				else 
				{
					graph[current_field].push_back(GraphRel(field.ToString(), outcome));
				}

				field.LoadField(current_field); outcomes = outcomes + outcome;
			}
		}
		return outcomes;
	}
}

void SolveGraph::GenerateGameGraph()
{
}