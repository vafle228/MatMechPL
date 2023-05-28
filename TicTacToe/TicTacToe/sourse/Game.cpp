#include <iostream>
#include "../headers/Game.h"
#include "../headers/Player.h"

#include "../headers/GameAi/EasyAI.h"
#include "../headers/GameAi/NormalAI.h"


Game::Game(char player_sign, AIModes mode, SolveGraph* graph)
{
    player = new Player(player_sign);

    if (player_sign == 'X') 
    {
        computer = new NormalAI('O', graph);
        active = player;
    }
    
    else
    {
        computer = new NormalAI('X', graph);
        active = computer;
    }
}

void Game::NextTurn()
{
    while ("Input loop")
    {
        try { active->MakeMove(&field); break; }
        catch (const std::exception& ex) { std::cout << ex.what() << std::endl; }
    }
    active = active == computer ? player : computer;
}

GameState Game::State()
{
    field.Print();
    return field.CheckState();
}
