#include <string>
#include <iostream>

#include "../headers/Player.h"
#include "../headers/Utils/Utils.h"


Player::Player(char sign)
    : GamePlayer(sign)
{ }

void Player::MakeMove(GameField* field)
{
    std::string input;
    getline(std::cin, input);
    
    auto args = Split(input);
    
    if (args.size() != 2)
        throw std::exception("Input error");
    field->DoMove(stoi(args[0]), stoi(args[1]), sign);
}
