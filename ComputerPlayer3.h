#ifndef COMPUTERPLAYER3_H
#define COMPUTERPLAYER3_H

#include "ComputerPlayer.h"
#include "BoardState.h"

class ComputerPlayer3 : public ComputerPlayer {
public:
    explicit ComputerPlayer3(bool isWhite);

    bool makeMove(BoardState &board) override;

    // Returns the most valuable piece that is under attack by the opponent, given the board state.
    double mostValuableAttacked(BoardState &board);
    void getHelp(BoardState &board) override;

};

#endif
