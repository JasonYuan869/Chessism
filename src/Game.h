#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "BoardState.h"
#include "Player.h"

class Game {
    BoardState board;
    Player* white;
    Player* black;
    bool isWhiteTurn;
    public: 
        Game();
        ~Game();
        void setup();
        BoardState& getBoard();
};

#endif
