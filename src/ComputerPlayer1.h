#ifndef COMPUTERPLAYER1_H
#define COMPUTERPLAYER1_H

#include "Player.h"
#include "BoardState.h"

class ComputerPlayer1 : public Player {
    public: 
        ComputerPlayer1();
        ~ComputerPlayer1();
        int makeMove(BoardState& board) override;
};

#endif
