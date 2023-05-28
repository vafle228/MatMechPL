#pragma once
#include <string>


struct GameOutcome 
{
	int tie;
	int x_win;
	int x_lose;

	GameOutcome(int tie, int x_win, int x_lose);

	GameOutcome operator+(GameOutcome obj);
};

struct GraphRel 
{
	std::string rel;
	GameOutcome outcome;

	GraphRel(std::string rel, GameOutcome outcome);

	GraphRel operator+(GraphRel& obj);
	bool operator==(const GraphRel& obj) const;
};
