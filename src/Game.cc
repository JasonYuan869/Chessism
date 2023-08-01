#include "Game.h"
#include "pieces/Piece.h"
#include "pieces/KingPiece.h"

#include "players/HumanPlayer.h"
#include "players/ComputerPlayer1.h"
#include "players/ComputerPlayer2.h"
#include "players/ComputerPlayer3.h"
#include "players/ComputerPlayer4.h"
#include "players/ComputerPlayer5.h"

#include <iostream>
#include <string>
#include <utility>

using namespace std;

Game::Game(unique_ptr<Player>&& whitePlayer, unique_ptr<Player>&& blackPlayer) : white{std::move(whitePlayer)},
                                                                                 black{std::move(blackPlayer)},
                                                                                 features{0} {}

void Game::setup() {
    cout << "Enter setup commands" << endl;
    string command;
    char piece;
    char location[2];
    int x, y;
    unique_ptr<Piece> newPiece;
    while (cin >> command) {
        if (command == "+") {
            cin >> piece >> location[0] >> location[1];
            x = location[0] - 'a';
            y = location[1] - '1';
            if (x < 0 || x > 7 || y < 0 || y > 7) {
                cout << "Invalid location" << endl;
                continue;
            }
            newPiece = BoardState::makePiece(piece, x, y);
            newPiece->canCastle = false;  // Disable castling for newly placed pieces
            board.setPiece(std::move(newPiece), x, y);
            notifyObservers();
        } else if (command == "-") {
            cin >> location[0] >> location[1];
            x = location[0] - 'a';
            y = location[1] - '1';
            if (x < 0 || x > 7 || y < 0 || y > 7) {
                cout << "Invalid location" << endl;
                continue;
            }
            board.removePiece(x, y);
            notifyObservers();
        } else if (command == "=") {
            cin >> command;
            if (command == "white") {
                board.isWhiteTurn = true;
            } else if (command == "black") {
                board.isWhiteTurn = false;
            } else {
                cout << "Invalid colour" << endl;
                continue;
            }
        } else if (command == "done") {
            if (board.canStartGame()) {
                return;
            } else {
                cout << "Invalid board setup" << endl;
            }
        } else {
            cout << "Invalid command" << endl;
        }
    }

    if (cin.eof()) {
        throw -1;
    }
}

BoardState& Game::getBoard() {
    return board;
}

double Game::run() {
    // Print the board
    notifyObservers();

    while (true) {
        unique_ptr<Player>& currentPlayer = board.isWhiteTurn ? white : black;
        string colour = board.isWhiteTurn ? "White" : "Black";
        string opponentColour = board.isWhiteTurn ? "Black" : "White";

        if (board.getCheckmate(board.isWhiteTurn)) {
            // Checkmate
            cout << "Checkmate! " << opponentColour << " wins!" << endl;
            return board.isWhiteTurn ? 1 : 0;
        }

        // Is there a stalemate?
        if (board.getStalemate(board.isWhiteTurn)) {
            cout << "Stalemate!" << endl;
            return 0.5;
        }
        // check for special draws like 50 move rule or insufficient material
        // the draw message is printed within checkDraws.
        if (checkDraws()){ // 
            return 0.5;
        }
        // Is the player in check?
        if (board.getCheck(board.isWhiteTurn)) {
            // Check if there is a checkmate for this player
            cout << colour << " is in check." << endl;
        }

        string command;
        cin >> command;
        if (cin.eof()) {
            throw -1;
        }

        if (command == "setup") {
            if (board.lastMoves.empty()) {
                setup();
            } else {
                cout << "Cannot enter setup mode after game has started" << endl;
            }
        } else if (command == "move") {
            if (!currentPlayer->makeMove(board)) {
                continue;
            }
            notifyObservers();
        } else if (command == "resign") {
            cout << colour << " resigned." << endl;
            return board.isWhiteTurn ? 1 : 0;
        } else if (command == "enable") {
            int featureNumber = 0;
            cin >> featureNumber;
            if (!cin || featureNumber >= NUM_FEATURES) {
                cout << "Invalid command" << endl;
                continue;
            }
            if (featureNumber == -1){ // enable -1 enables all features
                features =  (1 << NUM_FEATURES) - 1;
            } else {
                features = features | (1 << featureNumber);
            }
        } else if (command == "disable") {
            int featureNumber = 0;
            cin >> featureNumber;
            if (!cin || featureNumber >= NUM_FEATURES) {
                cout << "Invalid command" << endl;
                continue;
            }
            if (featureNumber == -1){
                features = 0;
            } else {
                features = features & ~(1 << featureNumber);
            }
        } else if (command == "undo" && (features & (1 << UNDO))) {
            if (board.lastMoves.empty()) {
                cout << "Cannot undo from the start of the game!" << endl;
                continue;
            }
            board.undo();
            notifyObservers();
        } else if (command == "help" && (features & (1 << HELP))) {
            currentPlayer->getHelp(board);
        } else if (command == "switch" && (features & (1 << SWITCH))) {
            cout << "Select what player you would like to switch for the " << colour << " player:" << endl;
            string playerType;
            cin >> playerType;

            if (!cin) {
                cout << "Invalid player type" << endl;
                continue;
            }

            unique_ptr<Player> newPlayer = makePlayer(board.isWhiteTurn, playerType);

            if (!newPlayer) {
                cout << "Invalid player type" << endl;
                continue;
            }

            std::swap(currentPlayer, newPlayer);
            cout << "Switched in " << playerType << endl;
        } else if (command == "hint" && (features & (1 << HINT))) {
            // Instantiate a ComputerPlayer5 to get a hint
            unique_ptr<ComputerPlayer5> hintPlayer = make_unique<ComputerPlayer5>(board.isWhiteTurn);
            hintPlayer->getHint(board);
        } else {
            cout << "Invalid command" << endl;
        }
    }
}

std::unique_ptr<Player> Game::makePlayer(bool white, const std::string& playerType) {
    unique_ptr<Player> newPlayer;
    if (playerType == "human") {
        newPlayer = make_unique<HumanPlayer>(white);
    } else if (playerType == "computer1") {
        newPlayer = make_unique<ComputerPlayer1>(white);
    } else if (playerType == "computer2") {
        newPlayer = make_unique<ComputerPlayer2>(white);
    } else if (playerType == "computer3") {
        newPlayer = make_unique<ComputerPlayer3>(white);
    } else if (playerType == "computer4") {
        newPlayer = make_unique<ComputerPlayer4>(white);
    } else if (playerType == "computer5") {
        newPlayer = make_unique<ComputerPlayer5>(white);
    }

    // nullptr if playerType is invalid
    return newPlayer;
}


bool Game::checkDraws(){
    //has there been 50 moves with no pawn movement or captures?
    if ((features & (1 << FIFTY)) && board.checkFiftyMoves()){
        cout << "Draw due to 50 move rule." << endl;
        return true;
    }
    if ((features & (1 << INSUFFICIENT)) && board.checkInsufficientMaterial()){
        cout<< "Draw due to insufficient material." << endl;
        return true;
    }
    return false;
}