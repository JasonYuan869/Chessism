#include "Game.h"
#include "graphics/Graphical.h"
#include "players/HumanPlayer.h"
#include "players/ComputerPlayer1.h"
#include "players/ComputerPlayer2.h"
#include "players/ComputerPlayer3.h"
#include "players/ComputerPlayer4.h"
#include "Terminal.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

void loop(double& whiteScore, double& blackScore, bool enableGraphics) {
    string command;
    string player1;
    string player2;
    while (true) {
        unique_ptr<Player> whitePlayer;
        unique_ptr<Player> blackPlayer;
        while (cin >> command) {
            if (command == "game") {
                cin >> player1 >> player2;

                if (player1 == "human") {
                    whitePlayer = make_unique<HumanPlayer>(true);
                } else if (player1 == "computer1") {
                    whitePlayer = make_unique<ComputerPlayer1>(true);
                } else if (player1 == "computer2") {
                    whitePlayer = make_unique<ComputerPlayer2>(true);
                } else if (player1 == "computer3") {
                    whitePlayer = make_unique<ComputerPlayer3>(true);
                } else if (player1 == "computer4") {
                    whitePlayer = make_unique<ComputerPlayer4>(true);
                } else {
                    cout << "Invalid player type" << endl;
                    continue;
                }

                if (player2 == "human") {
                    blackPlayer = make_unique<HumanPlayer>(false);
                } else if (player2 == "computer1") {
                    blackPlayer = make_unique<ComputerPlayer1>(false);
                } else if (player2 == "computer2") {
                    blackPlayer = make_unique<ComputerPlayer2>(false);
                } else if (player2 == "computer3") {
                    blackPlayer = make_unique<ComputerPlayer3>(false);
                } else if (player2 == "computer4") {
                    blackPlayer = make_unique<ComputerPlayer4>(false);
                } else {
                    cout << "Invalid player type" << endl;
                    continue;
                }

                break;
            } else {
                cout << "Invalid command" << endl;
                continue;
            }
        }

        if (cin.eof()) {
            throw -1;
        }

        // Construct the game
        Game game(std::move(whitePlayer), std::move(blackPlayer));

        // Initialize observers
        Terminal terminal(&game);

        unique_ptr<Graphical> window = nullptr;
        if (enableGraphics) {
            window = make_unique<Graphical>(&game);
        }

        // Run the game and update scores upon completion
        double score = game.run();
        blackScore += score;
        whiteScore += (1 - score);
    }
}

int main(int argc, char** argv) {
    double whiteScore = 0;
    double blackScore = 0;

    // Disable graphics if -nographics is passed
    bool enableGraphics = true;
    if (argc >= 2) {
        enableGraphics = !(string(argv[1]) ==  "-nographics");
    }

    try {
        loop(whiteScore, blackScore, enableGraphics);
    } catch (int e) {
        cout << "Final Score:" << endl;
        cout << "White: " << whiteScore << endl;
        cout << "Black: " << blackScore << endl;
    }

    return 0;
}

