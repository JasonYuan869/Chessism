#ifndef COMPUTERPLAYER5_H
#define COMPUTERPLAYER5_H

#include "ComputerPlayer.h"
#include "../BoardState.h"

class ComputerPlayer5 : public ComputerPlayer {
public:
    explicit ComputerPlayer5(bool isWhite);

    bool makeMove(BoardState &board) override;

    void getHelp(BoardState &board) override;

    void getHint(BoardState &board);

    Move determineBestMove(BoardState& board);

    double alphabeta(int depth, BoardState& board, double alpha, double beta, bool isMaximizingPlayer);
};


#endif //COMPUTERPLAYER5_H
