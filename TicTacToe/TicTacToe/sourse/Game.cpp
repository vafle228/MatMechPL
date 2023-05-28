#include <iostream>
#include "../headers/Game.h"
#include "../headers/Player.h"
#include "../headers/GameAi/EasyAI.h"


Game::Game(char player_sign, AIModes mode)
{
    player = new Player(player_sign);

    if (player_sign == 'X') 
    {
        computer = new EasyAI('O');
        active = player;
    }
    
    else
    {
        computer = new EasyAI('X');
        active = computer;
    }
}

void Game::NextTurn()
{
    while ("Input loop")
    {
        try
        {
            auto move = active->MakeMove();
            field.DoMove(move.first, move.second, active->sign);
            break;
        }
        catch (const std::exception& ex)
        {
            if (active == computer) continue;
            std::cout << ex.what() << std::endl;
        }
    }
    active = active == computer ? player : computer;
}

GameState Game::State()
{
    field.Print();
    return field.CheckState();
}
