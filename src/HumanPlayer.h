#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "BoardState.h"

class HumanPlayer : public Player {
public:
    explicit HumanPlayer(bool isWhite);

    MoveResult makeMove(BoardState &board) override;
};

#endif
