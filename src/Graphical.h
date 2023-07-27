#ifndef GRAPHICAL_H 
#define GRAPHICAL_H

#include "Observer.h"
#include "Game.h"
#include <gtkmm.h>

class Graphical : public Observer, public Gtk::Window {
    Game* game; 
    public: 
        Graphical(Game* game);
        ~Graphical() override;
        void update();
        void notify() override;
};

#endif
