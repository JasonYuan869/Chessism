#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>
#include "BoardState.h"
#include "players/Player.h"
#include "Subject.h"

class Game : public Subject {
    BoardState board;
    std::unique_ptr<Player> white;
    std::unique_ptr<Player> black;

    
    /*use bit encoding for each feature:
        1 << 0 is undo
        1 << 1 is help 
        1 << 2 is switch player
    */
    int features; 
    public: 
        Game(std::unique_ptr<Player>&& whitePlayer, std::unique_ptr<Player>&& blackPlayer);
        ~Game();
        void setup();
        BoardState& getBoard();

        // Runs the game and returns the end state
        // blackScore += return
        // whiteScore += (1-return)
        double run();
};

#endif
