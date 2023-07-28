#include "Move.h"

#include <utility>

using namespace std;


Move::Move() :
    to{-1, -1},
    from{-1, -1},
    promotion{'-'},
    capturedOrMovedPiece{nullptr},
    to2{-1,-1},
    from2{-1,-1} {}

Move::Move(pair<int, int> to,
           pair<int, int> from,
           char promotion = '-'
) : to{std::move(to)},
    from{std::move(from)},
    promotion{promotion},
    capturedOrMovedPiece{nullptr},
    to2{-1,-1},
    from2{-1,-1} {}

Move::Move(pair<int, int> to,
           pair<int, int> from,
           char promotion = '-'
) : to{std::move(to)},
    from{std::move(from)},
    promotion{promotion},
    capturedOrMovedPiece{nullptr},
    to2{-1,-1},
    from2{-1,-1} {}

Move::Move(pair<int, int> to,
           pair<int, int> to2,
           pair<int, int> from,
           pair<int, int> from2,
           Piece* capturedOrMovedPiece
) : to{std::move(to)},
    from{std::move(from)},
    to2{std::move(to2)},
    from2{std::move(from2)},
    capturedOrMovedPiece{capturedOrMovedPiece},
    promotion{'-'} {}


Move::~Move() {
}

pair<int, int> Move::getTo() {
    return to;
}

pair<int, int> Move::getFrom() {
    return from;
}


bool Move::operator==(Move& other){
    return (promotion == other.promotion
    && to == other.to 
    && from == other.from
    && to2 == other.to2
    && from2== other.from2
    && capturedOrMovedPiece == other.capturedOrMovedPiece
    );
}
