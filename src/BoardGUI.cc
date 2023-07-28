//
// Created by jason on 2023-07-28.
//

#include "BoardGUI.h"
#include <string>
using namespace std;

const char * BLACK_FILENAMES[] = {
        "assets/bp.png",
        "assets/br.png",
        "assets/bn.png",
        "assets/bb.png",
        "assets/bq.png",
        "assets/bk.png"
};

const char * WHITE_FILENAMES[] = {
        "assets/wp.png",
        "assets/wr.png",
        "assets/wn.png",
        "assets/wb.png",
        "assets/wq.png",
        "assets/wk.png"
};

BoardGUI::BoardGUI() {
    blackPieces.reserve(6);
    whitePieces.reserve(6);
    for (int i = 0; i < 6; i++) {
        blackPieces.push_back(Gdk::Pixbuf::create_from_file(BLACK_FILENAMES[i]));
        whitePieces.push_back(Gdk::Pixbuf::create_from_file(WHITE_FILENAMES[i]));
    }

    boardImage = Gdk::Pixbuf::create_from_file("assets/board.png");
}

BoardGUI::~BoardGUI() {}

Glib::RefPtr<Gdk::Pixbuf> BoardGUI::image(Piece *piece) {
    if (piece->isWhite) {
        return whitePieces[piece->getType()];
    } else {
        return blackPieces[piece->getType()];
    }
}

Glib::RefPtr<Gdk::Pixbuf> BoardGUI::board() {
    return boardImage;
}



