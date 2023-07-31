#include "Game.h"
#include "pieces/Piece.h"
#include "pieces/KingPiece.h"

#include "players/HumanPlayer.h"
#include "players/ComputerPlayer1.h"
#include "players/ComputerPlayer2.h"
#include "players/ComputerPlayer3.h"
#include "players/ComputerPlayer4.h"

#include <iostream>
#include <string>
using namespace std;

Game::Game(Player* whitePlayer, Player* blackPlayer) :  board{true}, white{whitePlayer}, black{blackPlayer}, features{0} {}

Game::~Game() {
    delete white;
    delete black;
}

void Game::setup() {
    cout << "Enter setup commands" << endl;
    string command;
    char piece;
    char location[2];
    int x, y;
    Piece* newPiece;
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
            board.setPiece(newPiece, x, y);
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
        Player* currentPlayer = board.isWhiteTurn ? white : black;
        string colour = board.isWhiteTurn ? "White" : "Black";
        string opponentColour = board.isWhiteTurn ? "Black" : "White";

        if (board.getCheckmate(board.isWhiteTurn)) {
            // Checkmate
            cout << "Checkmate! " << opponentColour << " wins!" << endl;
            return board.isWhiteTurn ? 1 : 0;
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
            MoveResult moveResult = currentPlayer->makeMove(board);
            switch (moveResult) {
                case INVALID_MOVE:
                    break;
                case SUCCESS:
                    notifyObservers();
                    break;
                case STALEMATE:
                    cout << "Stalemate!" << endl;
                    return 0.5;
            }
        } else if (command == "resign") {
            return board.isWhiteTurn ? 1 : 0;
        } else if (command == "enable"){
            int featureNumber = 0;
            cin >> featureNumber;
            if (!cin || featureNumber > 3){
                cout << "Invalid command" << endl;
                continue;
            } 
            features  = features | (1 << featureNumber);
        } else if (command == "disable"){
            int featureNumber;
            cin >> featureNumber;
            if (!cin || featureNumber > 3){
                cout << "Invalid command" << endl;
                continue;
            } 
            features  = features & ~(1 << featureNumber);
        } else if (command == "undo" && (features & 1)){
            if (board.lastMoves.empty()){
                cout << "Cannot undo from the start of the game!"<<endl;
                continue;
            } 
            board.undo();
            notifyObservers();
        } else if (command == "help" && (features & (1 << 1))){
            currentPlayer->getHelp(board);
        } else if (command == "switch" && (features & (1 << 2))){
            cout<<"select what player you would like to switch for the "<<colour<<" player:"<<endl;
            string playerType;
            Player* newPlayer;

            cin >> playerType;

            if (!cin){
                cout << "Invalid player type" << endl;
                continue;
            }
            if (playerType == "human") {
                newPlayer = new HumanPlayer(board.isWhiteTurn);
            } else if (playerType == "computer1") {
                newPlayer = new ComputerPlayer1(board.isWhiteTurn);
            } else if (playerType == "computer2") {
                newPlayer = new ComputerPlayer2(board.isWhiteTurn);
            } else if (playerType == "computer3") {
                newPlayer = new ComputerPlayer3(board.isWhiteTurn);
            } else if (playerType == "computer4") {
                newPlayer = new ComputerPlayer4(board.isWhiteTurn);
            } else {
                cout << "Invalid player type" << endl;
                continue;
            }
            delete currentPlayer;
            if (board.isWhiteTurn){
                white = newPlayer;
            } else {
                black = newPlayer;
            }
            cout<<"switched in "<<playerType<<endl;
        }
        else {
            cout << "Invalid command" << endl;
        }
    }
}
