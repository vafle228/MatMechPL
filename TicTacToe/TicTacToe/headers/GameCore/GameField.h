#pragma once
#include <vector>

#include "GameState.h"

#define Field std::vector<std::vector<char>>


const int SIZE = 3;

class GameField 
{
public:
	GameField();

	void Print();
	GameState CheckState();
	void DoMove(int row, int col, char sign);

private: Field game_field;
};