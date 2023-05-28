#include <iostream>

#include "headers/Game.h"
#include "headers/GameAi/AIModes.h"
#include "headers/GameCore/GameState.h"

#include "headers/GameSolver/SolveGraph.h"


int main()
{
    SolveGraph graph = SolveGraph();
    std::cout << "done" << std::endl;
    //std::srand(std::time(nullptr));
    //
    //GameState state = GameState::Game;
    //Game game_instance = Game('X', AIModes::Easy);
    //
    //while (state == GameState::Game) 
    //{
    //    game_instance.NextTurn();
    //    state = game_instance.State();
    //}

    //if (state == GameState::XWin)
    //    std::cout << "X wins" << std::endl;

    //if (state == GameState::XLose)
    //    std::cout << "O wins" << std::endl;

    //if (state == GameState::Tie)
    //    std::cout << "Friendship :)" << std::endl;
}
