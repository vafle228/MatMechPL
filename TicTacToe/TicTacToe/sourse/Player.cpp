#include <string>
#include <iostream>

#include "../headers/Player.h"
#include "../headers/Utils/Utils.h"


Player::Player(char sign)
    : GamePlayer(sign)
{ }

std::pair<int, int> Player::MakeMove()
{
    std::string input;
    getline(std::cin, input);
    
    auto args = Split(input);
    
    if (args.size() != 2)
        throw std::exception("Input error");
	return std::pair<int, int>(stoi(args[0]), stoi(args[1]));
}
