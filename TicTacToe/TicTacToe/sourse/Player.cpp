#include <string>
#include <iostream>

#include "../headers/Player.h"


Player::Player(char sign)
    : GamePlayer(sign)
{ }

std::vector<std::string> ParseMove(std::string input)
{
    std::string move = "";
    std::vector<std::string> move_vec;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ') move += input[i];
        else { move_vec.push_back(move); move = ""; }
    }
    move_vec.push_back(move); return move_vec;
}

std::pair<int, int> Player::MakeMove()
{
    std::string input;
    getline(std::cin, input);
    
    auto args = ParseMove(input);
    
    if (args.size() != 2)
        throw std::exception("Input error");
	return std::pair<int, int>(stoi(args[0]), stoi(args[1]));
}
