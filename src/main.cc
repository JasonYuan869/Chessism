#include "Game.h"
#include "Graphical.h"
#include "HumanPlayer.h"
#include "ComputerPlayer1.h"
#include "ComputerPlayer2.h"
#include "ComputerPlayer3.h"
#include "ComputerPlayer4.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[]) {
    auto app = Gtk::Application::create( argc, argv, "chessism" );

    string command;
    string player1;
    string player2;
    Player* whitePlayer;
    Player* blackPlayer;
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

    Game game(whitePlayer, blackPlayer);
    Graphical view(&game);

    // View will call Game::setup() and Game::run()
    return app->run(view);
}