#ifndef PLAYER_H
#define PLAYER_H

#include "BoardState.h"

class Player {
    protected:
        bool isWhite;
    public:
        explicit Player(bool isWhite): isWhite{isWhite} {}
        virtual ~Player();
        virtual int makeMove(BoardState& board)=0;
};

#endif
