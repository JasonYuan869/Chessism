#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "BoardState.h"
#include "players/Player.h"
#include "Subject.h"

class Game : public Subject {
    BoardState board;
    Player* white;
    Player* black;

    
    /*use bit encoding for each feature:
        1 << 0 is undo
        1 << 1 is help 
        1 << 2 is switch player
    */
    int features; 
    public: 
        Game(Player* whitePlayer, Player* blackPlayer);
        ~Game();
        void setup();
        BoardState& getBoard();

        // Runs the game and returns the end state
        // blackScore += return
        // whiteScore += (1-return)
        double run();
};

#endif
