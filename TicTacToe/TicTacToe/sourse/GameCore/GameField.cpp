#include <cstdlib>
#include <iostream>

#include "../../headers/GameCore/GameField.h"

#define CheckableTiles std::vector<std::vector<std::pair<int, int>>>


const std::string ROW_DELIM = "|---+---+---|";

GameField::GameField()
	: game_field(Field(SIZE, std::vector<char>(SIZE, ' ')))
{ }

void GameField::Print()
{
	for (int i = 0; i < game_field.size(); i++) 
	{
		std::cout << "|";
		
		for (int j = 0; j < game_field[i].size(); j++) 
			std::cout << " " << game_field[i][j] << " |";

		if (i != game_field.size() - 1)
			std::cout << std::endl << ROW_DELIM << std::endl;
	}
	std::cout << std::endl << std::endl;
}

GameState CheckGameStatus(char tile1, char tile2, char tile3)
{
	if (tile1 == tile2 && tile2 == tile3 && tile3 == 'X')
		return GameState::XWin;

	if (tile1 == tile2 && tile2 == tile3 && tile3 == 'O')
		return GameState::XLose;

	return GameState::Game;
}

GameState GameField::CheckState()
{
	GameState status;
	
	#pragma region CheckRows + Cols
	for (int i = 0; i < SIZE; i++) 
	{
		status = CheckGameStatus(
			game_field[i][0], game_field[i][1], game_field[i][2]
		);
		if (status != GameState::Game) return status;

		status = CheckGameStatus(
			game_field[0][i], game_field[1][i], game_field[2][i]
		);
		if (status != GameState::Game) return status;
	}
	#pragma endregion

	#pragma region Check diagonals
	status = CheckGameStatus(
		game_field[0][0], game_field[1][1], game_field[2][2]
	);
	if (status != GameState::Game) return status;

	status = CheckGameStatus(
		game_field[0][2], game_field[1][1], game_field[2][0]
	);
	if (status != GameState::Game) return status;
	#pragma endregion

	for (int i = 0; i < game_field.size(); i++) 
		for (int j = 0; j < game_field[i].size(); j++)
			if (game_field[i][j] == ' ') return GameState::Game;
	return GameState::Tie;
}

void GameField::DoMove(int row, int col, char sign)
{
	if ((row < 1 || row > 3) || (col < 1 || col > 3))
		throw std::exception("Index out of range!");

	if (game_field[row - 1][col - 1] != ' ')
		throw std::exception("Tile not empty!");

	game_field[row - 1][col - 1] = sign;
}
