#include "Move.h"

#include <utility>

using namespace std;


Move::Move() :
        to{-1, -1},
        from{-1, -1},
        promotion{'-'},
        capturedOrMovedPiece{nullptr},
        rookTo{-1, -1},
        rookFrom{-1, -1},
        isCastle{false},
        disabledCastle{false} {}

Move::Move(pair<int, int> to,
           pair<int, int> from,
           char promotion,
           bool isCastle,
           bool disabledCastle
) : to{std::move(to)},
    from{std::move(from)},
    promotion{promotion},
    capturedOrMovedPiece{nullptr},
    rookTo{-1, -1},
    rookFrom{-1, -1},
    isCastle{isCastle},
    disabledCastle{disabledCastle} {}

Move::Move(std::pair<int, int> to,
           std::pair<int, int> from,
           Piece *capturedOrMovedPiece,
           bool disabledCastle
): to{std::move(to)},
    from{std::move(from)},
    promotion{'-'},
    capturedOrMovedPiece{capturedOrMovedPiece},
    rookTo{-1, -1},
    rookFrom{-1, -1},
    isCastle{false},
    disabledCastle{disabledCastle} {}

Move::Move(std::pair<int, int> to,
           std::pair<int, int> from,
           Piece *capturedOrMovedPiece,
           char promotion
) : to{std::move(to)},
    from{std::move(from)},
    promotion{promotion},
    capturedOrMovedPiece{capturedOrMovedPiece},
    rookTo{-1, -1},
    rookFrom{-1, -1},
    isCastle{false},
    disabledCastle{false} {}


Move::Move(pair<int, int> to,
           pair<int, int> from,
           pair<int, int> rookTo,
           pair<int, int> rookFrom,
           Piece *capturedOrMovedPiece
) : to{std::move(to)},
    from{std::move(from)},
    promotion{'-'},
    capturedOrMovedPiece{capturedOrMovedPiece},
    rookTo{std::move(rookTo)},
    rookFrom{std::move(rookFrom)},
    isCastle{true},
    disabledCastle{true} {}


Move::~Move() {}

pair<int, int> Move::getTo() const {
    return to;
}

pair<int, int> Move::getFrom() const {
    return from;
}


bool Move::sameMoveAs(Move &other) const {
    return (promotion == other.promotion
            && to == other.to
            && from == other.from
    );
}