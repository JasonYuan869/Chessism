#include "Graphical.h"
#include <string>
using namespace std;

Graphical::Graphical(Game* game) : game{game} {
    // Register view as observer of model.
    game->attach(this);
}

Graphical::~Graphical() {}

void Graphical::notify() {

}
