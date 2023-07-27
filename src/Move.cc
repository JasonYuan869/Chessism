#include "Move.h"

#include <utility>

using namespace std;

Move::Move(pair<int, int> to,
           pair<int, int> from,
           char promotion
) : to{std::move(to)},
    from{std::move(from)},
    promotion{promotion},
    capturedOrMovedPiece{nullptr} {}

Move::Move() :
    to{-1, -1},
    from{-1, -1},
    promotion{'-'},
    capturedOrMovedPiece{nullptr} {}

Move::Move(int to_x, int to_y,
           int from_x, int from_y,
           char promotion
) : to{to_x, to_y},
    from{from_x, from_y},
    promotion{promotion},
    capturedOrMovedPiece{nullptr} {}


Move::Move(pair<int, int> to,
           pair<int, int> to2,
           pair<int, int> from,
           pair<int, int> from2,
           Piece* capturedOrMovedPiece
) : to{std::move(to)},
    from{std::move(from)},
    to2{std::move(to2)},
    from2{std::move(from2)},
    capturedOrMovedPiece{capturedOrMovedPiece} {}


Move::~Move() {
}

pair<int, int> Move::getTo() {
    return to;
}

pair<int, int> Move::getFrom() {
    return from;
}
