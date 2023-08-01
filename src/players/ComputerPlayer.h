#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include "../BoardState.h"

class ComputerPlayer : public Player {

public:
    ComputerPlayer(bool isWhite);
    virtual ~ComputerPlayer() = default;
    virtual bool makeMove(BoardState &board) = 0;
    virtual void getHelp(BoardState &board) = 0;

    double evaluateBoard(BoardState &board) const;
};

#endif
