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
    bool isWhiteTurn;
    public: 
        Game(Player* whitePlayer, Player* blackPlayer);
        ~Game();
        void setup();
        BoardState& getBoard();
};

#endif
