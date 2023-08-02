#include "Game.h"
#include "Graphical.h"
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
                whitePlayer = Game::makePlayer(true, player1);
                blackPlayer = Game::makePlayer(false, player2);

                if (!whitePlayer || !blackPlayer) {
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

