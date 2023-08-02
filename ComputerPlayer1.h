#ifndef COMPUTERPLAYER1_H
#define COMPUTERPLAYER1_H

#include "ComputerPlayer.h"
#include "BoardState.h"

class ComputerPlayer1 : public ComputerPlayer {
    public: 
        explicit ComputerPlayer1(bool isWhite);
        bool makeMove(BoardState& board) override;
        void getHelp(BoardState &board) override;
};

#endif
