#include <iostream>
#include "../headers/Game.h"
#include "../headers/Player.h"

#include "../headers/GameAi/EasyAI.h"
#include "../headers/GameAi/NormalAI.h"
#include "../headers/GameAi/HardAI.h"


GamePlayer* InitAI(char ai_sign, AIModes mode, SolveGraph* graph) 
{
    if (mode == AIModes::Easy) 
        return new EasyAI(ai_sign);

    if (mode == AIModes::Hard) 
        return new HardAI(ai_sign, graph);

    return new NormalAI(ai_sign, graph);
}

Game::Game(char player_sign, AIModes mode, SolveGraph* graph)
{
    player = new Player(player_sign);
    computer = InitAI(player_sign == 'X' ? 'O' : 'X', mode, graph);

    active = player_sign == 'X' ? player : computer;
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
