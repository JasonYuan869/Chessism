#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "BoardState.h"
#include "Player.h"
#include "Subject.h"

class Game : public Subject {
    BoardState board;
    Player* white;
    Player* black;
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
