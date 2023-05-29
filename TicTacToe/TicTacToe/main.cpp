#include <iostream>

#include "headers/Game.h"
#include "headers/GameAi/AIModes.h"
#include "headers/GameCore/GameState.h"

#include "headers/GameSolver/SolveGraph.h"


int main()
{
    std::srand(std::time(nullptr));

    std::cout << "Loading graph ..." << std::endl;
    SolveGraph graph = SolveGraph();
    std::cout << "Ready!" << std::endl;

    GameState state = GameState::Game;
    Game game_instance = Game('X', AIModes::Easy, &graph);
    
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
