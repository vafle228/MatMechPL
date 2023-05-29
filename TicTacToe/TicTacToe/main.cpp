#include <string>
#include <iostream>

#include "headers/Game.h"
#include "headers/GameAi/AIModes.h"
#include "headers/GameCore/GameState.h"

#include "headers/GameSolver/SolveGraph.h"


char InitPlayerSign() 
{
    char player_sign = '_';
    
    while (player_sign != 'X' && player_sign != 'O')
    {
        std::cout << "Choose player sign (X or O): ";
        std::cin >> player_sign;
    }
    return player_sign;
}

AIModes InitAIMode()
{
    while (true) 
    {
        std::cout << "Choose ai mode (1 - easy, 2 - normal, 3 - hard): ";
        int ai_mode; std::cin >> ai_mode;

        if (ai_mode == (int)AIModes::Easy) return AIModes::Easy;
        if (ai_mode == (int)AIModes::Hard) return AIModes::Hard;
        if (ai_mode == (int)AIModes::Medium) return AIModes::Medium;
    }
}

int main()
{
    std::srand(std::time(nullptr));

    std::cout << "Loading graph ..." << std::endl;
    SolveGraph graph = SolveGraph();
    std::cout << "Ready!" << std::endl;

    GameState state = GameState::Game;
    Game game_instance = Game(InitPlayerSign(), InitAIMode(), &graph);

    std::string temp; getline(std::cin, temp);
    std::cout << "Game instance started!" << std::endl << std::endl;
    
    while (state == GameState::Game) 
    {
        game_instance.NextTurn();
        state = game_instance.State();
    }

    if (state == GameState::XWin)
        std::cout << "X wins" << std::endl;

    if (state == GameState::XLose)
        std::cout << "O wins" << std::endl;

    if (state == GameState::Tie)
        std::cout << "Friendship :)" << std::endl;
}
