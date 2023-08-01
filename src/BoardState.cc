#include "BoardState.h"
#include "pieces/PawnPiece.h"
#include "pieces/RookPiece.h"
#include "pieces/KnightPiece.h"
#include "pieces/BishopPiece.h"
#include "pieces/QueenPiece.h"
#include "pieces/KingPiece.h"
#include <vector>

using namespace std;

BoardState::BoardState() : isWhiteTurn{true} {
    board = vector<vector<Piece*>>(8,vector<Piece*>(8,nullptr));

    // Rank 1
    whitePieces.emplace_back(makePiece('R', 0, 0));
    whitePieces.emplace_back(makePiece('N', 0, 1));
    whitePieces.emplace_back(makePiece('B', 0, 2));
    whitePieces.emplace_back(makePiece('Q', 0, 3));
    whitePieces.emplace_back(makePiece('K', 0, 4));
    whitePieces.emplace_back(makePiece('B', 0, 5));
    whitePieces.emplace_back(makePiece('N', 0, 6));
    whitePieces.emplace_back(makePiece('R', 0, 7));

    // Pawns, rank 2
    for (int i = 0; i < 8; i++) {
        whitePieces.emplace_back(makePiece('P', 1, i));
    }

    // Rank 8
    blackPieces.emplace_back(makePiece('r', 7, 0));
    blackPieces.emplace_back(makePiece('n', 7, 1));
    blackPieces.emplace_back(makePiece('b', 7, 2));
    blackPieces.emplace_back(makePiece('q', 7, 3));
    blackPieces.emplace_back(makePiece('k', 7, 4));
    blackPieces.emplace_back(makePiece('b', 7, 5));
    blackPieces.emplace_back(makePiece('n', 7, 6));
    blackPieces.emplace_back(makePiece('r', 7, 7));

    // Pawns, rank 7
    for (int i = 0; i < 8; i++) {
        blackPieces.emplace_back(makePiece('p', 6, i));
    }

    // Initialize the board
    for (auto& piece : whitePieces) {
        board[piece->y][piece->x] = piece.get();
    }
    for (auto& piece : blackPieces) {
        board[piece->y][piece->x] = piece.get();
    }

    // Initialize the king pointers
    whiteKing = dynamic_cast<KingPiece *>(board[0][4]);
    blackKing = dynamic_cast<KingPiece *>(board[7][4]);
}

bool BoardState::getCheckmate(bool white) {
    // Update the valid moves for each piece
    updateValidMoves();

    if (!updateCheck(white)) {
        return false;
    }

    return getStalemate(white);
}

bool BoardState::getCheck(bool white) {
    KingPiece* king = white ? whiteKing : blackKing;
    return king->checked;
}

bool BoardState::updateCheck(bool white) {
    KingPiece* king = white ? whiteKing : blackKing;

    // Mutates the king's checked variable
    king->checked = getAttacked(king->x, king->y, white);
    return king->checked;
}

bool BoardState::getAttacked(int x, int y, bool white) {
    for (auto& piece : white ? blackPieces : whitePieces) {
        if (piece->isAlive && piece->isAttacking(x, y, *this)) {
            return true;
        }
    }
    return false;
}

void BoardState::setPiece(unique_ptr<Piece>&& piece, int x, int y) {
    if (board[y][x] != nullptr) {
        board[y][x]->isAlive = false;
    }

    board[y][x] = piece.get();
    piece->x = x;
    piece->y = y;


    bool isWhite = piece->isWhite;
    if (piece->getType() == PieceType::KING) {
        if (isWhite) {
            whiteKing = dynamic_cast<KingPiece *>(piece.get());
        } else {
            blackKing = dynamic_cast<KingPiece *>(piece.get());
        }
    }

    if (isWhite) {
        whitePieces.push_back(std::move(piece));
    } else {
        blackPieces.push_back(std::move(piece));
    }
}

void BoardState::removePiece(int x, int y) {
    Piece* piece = board[y][x];

    if (piece != nullptr) {
        piece->isAlive = false;
        if (piece == whiteKing) {
            whiteKing = nullptr;
        } else if (piece == blackKing) {
            blackKing = nullptr;
        }
    }

    board[y][x] = nullptr;
}

void BoardState::updateValidMoves() {
    KingPiece* king = isWhiteTurn ? whiteKing : blackKing;
    vector<unique_ptr<Piece>>& pieces = isWhiteTurn ? whitePieces : blackPieces;

    // Don't use a range based loop here because we might mutate the vector during move simulation (promotion)
    // This leads to an occasional bug where the iterator and unique_ptr are invalidated if the vector is resized
    for (int i = 0; i < pieces.size(); i++) {
        vector<Move> moves;

        if (!pieces[i]->isAlive){
            pieces[i]->validMoves = moves;
            continue;
        }

        for (const auto& move : pieces[i]->getPieceMoves(*this)) {
            // Simulate the move
            if (movePiece(move)) {
                // Is our king checked?
                if (!getAttacked(king->x, king->y, !isWhiteTurn)) {
                    // Add the move to the vector of moves
                    moves.push_back(move);
                }

                // Undo the move
                undo();
            }
        }

        // Update the validMoves vector
        pieces[i]->validMoves = moves;
    }
}


bool BoardState::movePieceIfLegal(const Move& move){
    int x = move.from.first;
    int y = move.from.second;
    Piece* pieceToMove = board[y][x];

    if (pieceToMove == nullptr || pieceToMove->isWhite != isWhiteTurn) {
        return false;
    }

    for (auto validMove : pieceToMove->validMoves){
        if (move.sameMoveAs(validMove)){
            return movePiece(validMove);
        }
    }

   return false;
}

bool BoardState::movePiece(const Move& move) {
    int x = move.from.first;
    int y = move.from.second;
    Piece* pieceToMove = board[y][x];

    if (pieceToMove == nullptr) {
        return false;
    }

    if (move.disabledCastle) {
        pieceToMove->canCastle = false;
    }

    int to_x = move.to.first;
    int to_y = move.to.second;

    //handle the capture
    if (!move.isCastle() && move.capturedOrMovedPiece != nullptr){
       move.capturedOrMovedPiece->isAlive = false;
       int captured_x = move.capturedOrMovedPiece->x;
       int captured_y = move.capturedOrMovedPiece->y;
       board[captured_y][captured_x] = nullptr;
    }

    // either pawn promotion, or we actually move the piece
    if (move.promotion != '-'){
        pieceToMove->isAlive = false;
        unique_ptr<Piece> newPiece = makePiece(move.promotion, to_y, to_x);

        board[to_y][to_x] = newPiece.get();
        if (isWhiteTurn){
            whitePieces.push_back(std::move(newPiece));
        } else {
            blackPieces.push_back(std::move(newPiece));
        }
    } else {
        board[to_y][to_x] = pieceToMove;
        pieceToMove->setPosition(to_x,to_y);
    }

    board[y][x] = nullptr;

    //castling
    if (move.isCastle() && move.capturedOrMovedPiece != nullptr){

        int rookStartx = move.rookFrom.first;
        int rookStarty = move.rookFrom.second;
        int rookEndx = move.rookTo.first;
        int rookEndy = move.rookTo.second;

        Piece* rook =  board[rookStarty][rookStartx];

        board[rookEndy][rookEndx] = rook;
        board[rookStarty][rookStartx] = nullptr;
        rook->setPosition(rookEndx,rookEndy);

        // Disable castling for the rook
        rook->canCastle = false;
    }
    lastMoves.push_back(move);
    isWhiteTurn = !isWhiteTurn;
    return true;
}

void BoardState::undo() {
    if (lastMoves.empty()){
        return;
    }
    //toggle the turn so that the logic is more similar to movePiece
    //we will undo movePiece in the opposite order compared to the order that
    //the last movePiece was done in
    isWhiteTurn = !isWhiteTurn;
    bool lastTurnIsWhite = isWhiteTurn;
    Move lastMove = lastMoves.back();
    lastMoves.pop_back();

    int startx = lastMove.from.first;
    int starty = lastMove.from.second;

    int endx = lastMove.to.first;
    int endy = lastMove.to.second;

    //castling logic
    if (lastMove.isCastle() && lastMove.capturedOrMovedPiece != nullptr){

        int rookStartx = lastMove.rookFrom.first;
        int rookStarty = lastMove.rookFrom.second;
        int rookEndx = lastMove.rookTo.first;
        int rookEndy = lastMove.rookTo.second;

        Piece* rook =  board[rookEndy][rookEndx];

        board[rookStarty][rookStartx] = rook;
        board[rookEndy][rookEndx] = nullptr;
        rook->setPosition(rookStartx,rookStarty);
        rook->canCastle = true;
    }

    //pawn promotion or regular move
    if (lastMove.promotion != '-') {
        vector<unique_ptr<Piece>>& pieces = lastTurnIsWhite ? whitePieces : blackPieces;

        // The last piece was the newly promoted piece, so we remove it
        // This should run the destructor for the piece because it is a unique_ptr
        pieces.pop_back();

        // Find the pawn used to promote
        for (auto& piece : pieces) {
            if (!piece->isAlive && piece->getPosition() == lastMove.from) {
                piece->isAlive = true;
                board[starty][startx] = piece.get();
                break;
            }
        }
    } else {
        Piece* pieceThatMoved = board[endy][endx];
        board[starty][startx] = pieceThatMoved;
        pieceThatMoved->setPosition(startx,starty);

        if (lastMove.disabledCastle) {
            pieceThatMoved->canCastle = true;
        }
    }

    board[endy][endx] = nullptr;

    //capturing piece
    if (!lastMove.isCastle() && lastMove.capturedOrMovedPiece != nullptr){
        lastMove.capturedOrMovedPiece->isAlive = true;
        int aliveX = lastMove.capturedOrMovedPiece->x;
        int aliveY = lastMove.capturedOrMovedPiece->y;
        board[aliveY][aliveX] = lastMove.capturedOrMovedPiece;
    }

}


bool BoardState::canStartGame() {
    // Check that there is exactly one king of each color
    int whiteKingCount = 0;
    int blackKingCount = 0;
    for (const auto& piece : whitePieces) {
        // Check that no pawns are on the first or last row
        if (piece->isAlive && piece->getType() == PAWN) {
            if (piece->y == 0 || piece->y == 7) {
                return false;
            }
        }

        // Count kings
        if (piece->isAlive && piece->getType() == PieceType::KING) {
            whiteKingCount++;
        }
    }
    for (const auto& piece : blackPieces) {
        if (piece->isAlive && piece->getType() == PieceType::KING) {
            blackKingCount++;
        }
        if (piece->isAlive && piece->getType() == PAWN) {
            if (piece->y == 0 || piece->y == 7) {
                return false;
            }
        }
    }

    // Check that there is exactly one king of each color
    if (whiteKingCount != 1 || blackKingCount != 1) {
        return false;
    }

    // Ensure that the kings are not in check
    KingPiece* king = isWhiteTurn ? blackKing : whiteKing;
    if (getAttacked(king->x, king->y, isWhiteTurn)) {
        return false;
    }

    return true;
}


unique_ptr<Piece> BoardState::makePiece(char piece, int y, int x) {
    switch (piece) {
        case 'P':
            return make_unique<PawnPiece>(x, y, true);
        case 'p':
            return make_unique<PawnPiece>(x, y, false);
        case 'R':
            return make_unique<RookPiece>(x, y, true);
        case 'r':
            return make_unique<RookPiece>(x, y, false);
        case 'N':
            return make_unique<KnightPiece>(x, y, true);
        case 'n':
            return make_unique<KnightPiece>(x, y, false);
        case 'B':
            return make_unique<BishopPiece>(x, y, true);
        case 'b':
            return make_unique<BishopPiece>(x, y, false);
        case 'Q':
            return make_unique<QueenPiece>(x, y, true);
        case 'q':
            return make_unique<QueenPiece>(x, y, false);
        case 'K':
            return make_unique<KingPiece>(x, y, true);
        case 'k':
            return make_unique<KingPiece>(x, y, false);
        default:
            return nullptr;
    }
}

std::vector<Move> BoardState::allValidMoves() const {
    const vector<unique_ptr<Piece>>& pieces = isWhiteTurn ? whitePieces : blackPieces;
    vector<Move> moves;
    for (auto& piece : pieces) {
        moves.insert(moves.end(), piece->validMoves.begin(), piece->validMoves.end());
    }
    return moves;
}

bool BoardState::getStalemate(bool white) {
    const vector<unique_ptr<Piece>>& pieces = isWhiteTurn ? whitePieces : blackPieces;
    for (auto& piece : pieces) {
        if (piece->isAlive && !piece->validMoves.empty()) {
            return false;
        }
    }
    return true;
}

