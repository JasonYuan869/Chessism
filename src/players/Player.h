#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "../BoardState.h"

enum MoveResult {
    INVALID_MOVE,
    SUCCESS,
    STALEMATE,
};

class Player {
protected:
    bool isWhite;
public:
    explicit Player(bool isWhite);

    virtual ~Player();

    virtual MoveResult makeMove(BoardState &board) = 0;
};

#endif
