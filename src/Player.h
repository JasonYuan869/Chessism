#ifndef PLAYER_H
#define PLAYER_H

#include "BoardState.h"

class Player {
    bool isWhite;
    public:
        virtual ~Player();
        virtual int makeMove(BoardState& board)=0;
};

#endif
