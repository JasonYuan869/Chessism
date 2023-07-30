#ifndef COMPUTERPLAYER1_H
#define COMPUTERPLAYER1_H

#include "Player.h"
#include "../BoardState.h"

class ComputerPlayer1 : public Player {
    public: 
        explicit ComputerPlayer1(bool isWhite);
        ~ComputerPlayer1() override;
        MoveResult makeMove(BoardState& board) override;
};

#endif
