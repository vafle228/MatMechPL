#include <iostream>

#include "headers/Game.h"
#include "headers/AIModes.h"
#include "headers/GameState.h"


int main()
{
    std::srand(std::time(nullptr));
    
    GameState state = GameState::Game;
    Game game_instance = Game('X', AIModes::Easy);
    
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
