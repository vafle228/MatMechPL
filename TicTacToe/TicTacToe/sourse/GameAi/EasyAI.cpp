#include "../../headers/GameAi/EasyAI.h"


int GenerateRandomNumber(int min_val, int max_val)
{
	return min_val + std::rand() % (max_val - min_val);
}

EasyAI::EasyAI(char sign) 
	: GamePlayer(sign) 
{ }

void EasyAI::MakeMove(GameField* field)
{
	while ("Try to random free cell") 
	{
		int row = GenerateRandomNumber(1, 4);
		int col = GenerateRandomNumber(1, 4);
		
		try { field->DoMove(row, col, sign); return; }
		catch (const std::exception& except) { continue; }
	}
}
