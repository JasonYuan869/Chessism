#include "Graphical.h"

Graphical::Graphical(Game* game) : game{game} {
    // Sets some properties of the window.
    set_title( "Chessism" );
    set_border_width( 10 );
    set_default_size( 250, 100 ); // width, height in pixels

    // The final step is to display the buttons (they display themselves).
    show_all();

    // Register view as observer of model.
    game->attach(this);

    // Start the game loop
    game->setup();
}

Graphical::~Graphical() {}

void Graphical::update() {

}

void Graphical::notify() {

}
