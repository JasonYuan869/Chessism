#include "Game.h"
#include "Graphical.h"
#include "HumanPlayer.h"
#include "ComputerPlayer1.h"
#include "ComputerPlayer2.h"
#include "ComputerPlayer3.h"
#include "ComputerPlayer4.h"
#include "Terminal.h"
#include <iostream>
#include <string>

using namespace std;

void loop(double& whiteScore, double& blackScore) {
    string command;
    string player1;
    string player2;
    while (true) {
        Player* whitePlayer = nullptr;
        Player* blackPlayer = nullptr;
        while (cin >> command) {
            if (command == "game") {
                cin >> player1 >> player2;

                if (player1 == "human") {
                    whitePlayer = new HumanPlayer(true);
                } else if (player1 == "computer1") {
                    whitePlayer = new ComputerPlayer1(true);
                } else if (player1 == "computer2") {
                    whitePlayer = new ComputerPlayer2(true);
                } else if (player1 == "computer3") {
                    whitePlayer = new ComputerPlayer3(true);
                } else if (player1 == "computer4") {
                    whitePlayer = new ComputerPlayer4(true);
                } else {
                    cout << "Invalid player type" << endl;
                    continue;
                }

                if (player2 == "human") {
                    blackPlayer = new HumanPlayer(false);
                } else if (player2 == "computer1") {
                    blackPlayer = new ComputerPlayer1(false);
                } else if (player2 == "computer2") {
                    blackPlayer = new ComputerPlayer2(false);
                } else if (player2 == "computer3") {
                    blackPlayer = new ComputerPlayer3(false);
                } else if (player2 == "computer4") {
                    blackPlayer = new ComputerPlayer4(false);
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

        if (cin.eof() || whitePlayer == nullptr || blackPlayer == nullptr) {
            throw -1;
        }

        Game game(whitePlayer, blackPlayer);
        // Graphical window(&game);
        Terminal terminal(&game);

        double score = game.run();
        blackScore += score;
        whiteScore += (1-score);
    }
}

int main() {
    double whiteScore = 0;
    double blackScore = 0;

    try {
        loop(whiteScore, blackScore);
    } catch (int e) {
        cout << "Final Score:" << endl;
        cout << "White: " << whiteScore << endl;
        cout << "Black: " << blackScore << endl;
    }

    return 0;
}

