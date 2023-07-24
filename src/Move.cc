#include "Move.h"

using namespace std;

Move::Move(pair<int, int> to, pair<int, int> from, char promotion='-'): to{to}, from{from}, promotion{promotion},nextMove{0} {}
Move::Move() {
    to = pair{-1, -1};
    from = pair{-1, -1};
    promotion = '-';
}
Move::Move(int to_x,int to_y, 
            int from_x,int from_y,
            char promotion = '-' ) : to{to_x,to_y}, from{from_x,from_y}, promotion{promotion},nextMove{0}{}


Move::Move(int to_x,int to_y, int from_x,int from_y,int to_x2,int to_y2, int from_x2,int from_y2,int nextMove
): to{to_x,to_y},from{from_x,from_y},to2{to_x2,to_y2},from2{from_x2,from_y2},nextMove{nextMove} {}



Move::~Move() {

}

pair<int, int> Move::getTo() {
    return to;
}

pair<int, int> Move::getFrom(){
    return from;
}
