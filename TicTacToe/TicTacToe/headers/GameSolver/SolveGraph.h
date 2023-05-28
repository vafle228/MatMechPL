#pragma once
#include <map>
#include <string>
#include <vector>

#include "GraphRel.h"

#define Outcomes std::vector<GraphRel>
#define GameGraph std::map<std::string, std::vector<GraphRel>>


class SolveGraph 
{
public:
	SolveGraph();
	Outcomes GetOutcomes(std::string field);

private:
	GameGraph game_graph = GameGraph();

	void DumpGameGraph();
	void LoadGameGraph();

	void GenerateGameGraph();
};