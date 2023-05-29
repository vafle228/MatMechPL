#include <fstream>

#include "../../headers/Utils/Utils.h"
#include "../../headers/GameCore/GameField.h"
#include "../../headers/GameSolver/SolveGraph.h"


SolveGraph::SolveGraph()
{
	std::ifstream file("graph.txt");
	if (file.is_open()) LoadGameGraph();

	else { GenerateGameGraph(); DumpGameGraph(); }
}

Outcomes SolveGraph::GetOutcomes(std::string field)
{
	return game_graph[field];
}

void SolveGraph::DumpGameGraph()
{
	std::ofstream file("graph.txt");
	for (auto game_state : game_graph) 
	{
		file << game_state.first << ":";
		for (auto state_rel : game_state.second) 
		{
			file << state_rel.rel << ";";
			file << state_rel.outcome.tie << ",";
			file << state_rel.outcome.x_win << ",";
			file << state_rel.outcome.x_lose << " ";
		}
		file << std::endl;
	}
}

void SolveGraph::LoadGameGraph()
{
	std::ifstream file("graph.txt");
	
	std::string game_state;
	while (std::getline(file, game_state)) 
	{
		auto state = Split(game_state, ':');
		
		Outcomes state_rels = Outcomes();
		for (auto relation : Split(state[1], ' ')) 
		{
			if (relation == "") continue;
			
			auto state_rel = Split(relation, ';');
			auto outcome = Split(state_rel[1], ',');

			GameOutcome out(stoi(outcome[0]), stoi(outcome[1]), stoi(outcome[2]));

			state_rels.push_back(GraphRel(state_rel[0], out));
		}
		game_graph[state[0]] = state_rels;
	}
}

GameOutcome GenerateGraph(GameField* field, char sign, GameGraph* graph)
{
	GameState state = field->CheckState();
	
	if (state != GameState::Game)
	{
		return GameOutcome(
			state == GameState::Tie,
			state == GameState::XWin,
			state == GameState::XLose
		);
	}
	GameOutcome outcomes = GameOutcome(0, 0, 0);
	std::string current_field = field->ToString();

	if (graph->find(current_field) == graph->end())
		graph->insert({ current_field, Outcomes() });
		
	for (int row = 1; row < SIZE + 1; row++)
	{
		for (int col = 1; col < SIZE + 1; col++)
		{
			try { field->DoMove(row, col, sign); }
			catch (const std::exception&) { continue; }

			auto outcome = GenerateGraph(field, sign == 'X' ? 'O' : 'X', graph);
			
			GraphRel relation = GraphRel(field->ToString(), outcome);
			auto find_res{ std::find(graph->at(current_field).begin(), graph->at(current_field).end(), relation) };

			if (find_res == graph->at(current_field).end())
				graph->at(current_field).push_back(relation);
			else find_res->operator+(relation);

			field->LoadField(current_field); outcomes = outcomes + outcome;
		}
	}
	return outcomes;
}

GameOutcome SumOutcomes(Outcomes outcomes) 
{
	GameOutcome out(0, 0, 0);
	for (auto outcome : outcomes)
		out = out + outcome.outcome;
	return out;
}

void SolveGraph::GenerateGameGraph()
{
	GameField* field = new GameField();
	game_graph["_________"] = Outcomes();

	std::vector<std::string> field_vars
	{
		{ "____X____" },
		{ "X________" },
		{ "_X_______" },
	};
	
	for (auto variant : field_vars) 
	{
		field->LoadField(variant);
		GenerateGraph(field, 'O', &game_graph);
		
		auto var_outcomes = game_graph[variant];
		GameOutcome summed = SumOutcomes(var_outcomes);

		game_graph["_________"].push_back({ variant, summed });
	}
}