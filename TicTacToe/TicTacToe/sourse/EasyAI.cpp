#include "../headers/EasyAI.h"


int GenerateRandomNumber(int min_val, int max_val)
{
	return min_val + std::rand() % (max_val - min_val);
}

EasyAI::EasyAI(char sign) 
	: GamePlayer(sign) 
{ }

std::pair<int, int> EasyAI::MakeMove() 
{
	return { GenerateRandomNumber(1, 4), GenerateRandomNumber(1, 4) };
}
