#ifndef COMPUTERPLAYER2_H
#define COMPUTERPLAYER2_H

#include "Player.h"
#include "BoardState.h"

class ComputerPlayer2 : public Player {
    public: 
        ComputerPlayer2();
        ~ComputerPlayer2();
        int makeMove(BoardState& board) override;
};

#endif
