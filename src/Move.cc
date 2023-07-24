#include "Move.h"

using namespace std;

Move::Move(pair<int, int> to,
           pair<int, int> from,
           char promotion = '-'
) : to{to},
    from{from},
    promotion{promotion} {}

Move::Move() :
    to{-1, -1},
    from{-1, -1},
    promotion{'-'} {}

Move::Move(int to_x, int to_y,
           int from_x, int from_y,
           char promotion = '-'
) : to{to_x, to_y},
    from{from_x, from_y},
    promotion{promotion} {}


Move::Move(pair<int, int> to,
           pair<int, int> to2,
           pair<int, int> from,
           pair<int, int> from2,
           Piece* capturedOrMovedPiece
) : to{to},
    from{from},
    to2{to2},
    from2{from2},
    capturedOrMovedPiece{capturedOrMovedPiece} {}


Move::~Move() {
}

pair<int, int> Move::getTo() {
    return to;
}

pair<int, int> Move::getFrom() {
    return from;
}
