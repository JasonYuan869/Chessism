#ifndef COMPUTERPLAYER3_H
#define COMPUTERPLAYER3_H

#include "Player.h"
#include "BoardState.h"

class ComputerPlayer3 : public Player {
    public: 
        ComputerPlayer3();
        ~ComputerPlayer3();
        int makeMove(BoardState& board) override;
};

#endif
