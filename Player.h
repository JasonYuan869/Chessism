#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "BoardState.h"

class Player {
protected:
    bool isWhite;
public:
    explicit Player(bool isWhite);
    virtual ~Player() = default;
    virtual bool makeMove(BoardState &board) = 0;
    virtual void getHelp(BoardState &board) = 0;
};

#endif
