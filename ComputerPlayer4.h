#ifndef COMPUTERPLAYER4_H
#define COMPUTERPLAYER4_H

#include "ComputerPlayer.h"
#include "BoardState.h"

class ComputerPlayer4 : public ComputerPlayer {
public:
    explicit ComputerPlayer4(bool isWhite);

    bool makeMove(BoardState &board) override;

    double minimax(int depth, BoardState &board, bool isMaximizingPlayer);
    void getHelp(BoardState &board) override;
};

#endif
