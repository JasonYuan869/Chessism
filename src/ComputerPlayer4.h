#ifndef COMPUTERPLAYER4_H
#define COMPUTERPLAYER4_H

#include "Player.h"
#include "BoardState.h"

class ComputerPlayer4 : public Player {
    public: 
        ComputerPlayer4();
        ~ComputerPlayer4();
        int makeMove(BoardState& board) override;
};

#endif
