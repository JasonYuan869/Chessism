#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>
#include "BoardState.h"
#include "players/Player.h"
#include "Subject.h"

#define NUM_FEATURES 4
#define UNDO 0
#define HELP 1
#define SWITCH 2
#define HINT 3

class Game : public Subject {
    BoardState board;
    std::unique_ptr<Player> white;
    std::unique_ptr<Player> black;


    /*use bit encoding for each feature:
        1 << 0 is undo
        1 << 1 is help 
        1 << 2 is switch player
        1 << 3 is computer hint
    */
    int features;
public:
    Game(std::unique_ptr<Player>&& whitePlayer, std::unique_ptr<Player>&& blackPlayer);

    void setup();

    BoardState& getBoard();

    // Runs the game and returns the end state
    // blackScore += return
    // whiteScore += (1-return)
    double run();

    // Returns a unique_ptr to a player of the given type
    // or nullptr if the type is invalid
    static std::unique_ptr<Player> makePlayer(bool white, const std::string& playerType);
};

#endif
