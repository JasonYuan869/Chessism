#ifndef PLAYER_H
#define PLAYER_H

#include "../BoardState.h"

enum MoveResult {
    INVALID_MOVE,
    SUCCESS,
    STALEMATE,
    RESIGNED,
    SETUP
};

class Player {
    protected:
        bool isWhite;
    public:
        explicit Player(bool isWhite): isWhite{isWhite} {}
        virtual ~Player();
        virtual MoveResult makeMove(BoardState& board)=0;
};

#endif
