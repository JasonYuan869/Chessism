//
// Created by jason on 2023-07-29.
//

#include "GraphicalTile.h"
#include "PiecePixels.h"

GraphicalTile::GraphicalTile(int x, int y, PieceType pieceType, bool white, Graphical *parent) : x{x}, y{y},
                                                                                                 pieceType{pieceType},
                                                                                                 white{white},
                                                                                                 parent{parent} {}

void GraphicalTile::draw() {
    int tileColour = (x + y) % 2 == 0 ? Graphical::Sienna : Graphical::PeachPuff;

    int pixelX = x * TILE_SIZE;
    int pixelY = WINDOW_SIZE - (y + 1) * TILE_SIZE;

    parent->fillRectangle(pixelX, pixelY, TILE_SIZE, TILE_SIZE, tileColour);

    const char *pieceBitmap = nullptr;
    switch (pieceType) {
        case PieceType::PAWN:
            pieceBitmap = white ? &wp[0] : &bp[0];
            break;
        case PieceType::ROOK:
            pieceBitmap = white ? &wr[0] : &br[0];
            break;
        case PieceType::KNIGHT:
            pieceBitmap = white ? &wn[0] : &bn[0];
            break;
        case PieceType::BISHOP:
            pieceBitmap = white ? &wb[0] : &bb[0];
            break;
        case PieceType::QUEEN:
            pieceBitmap = white ? &wq[0] : &bq[0];
            break;
        case PieceType::KING:
            pieceBitmap = white ? &wk[0] : &bk[0];
            break;
        case PieceType::EMPTY:
            return;
    }
    parent->drawPiece(pixelX, pixelY, pieceBitmap);
}

void GraphicalTile::update(PieceType pieceType, bool white) {
    bool changed = false;
    if (this->pieceType != pieceType) {
        this->pieceType = pieceType;
        changed = true;
    }
    if (this->white != white) {
        this->white = white;
        changed = true;
    }
    if (changed) {
        draw();
    }
}