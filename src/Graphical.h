#ifndef GRAPHICAL_H 
#define GRAPHICAL_H

#include "Observer.h"
#include "Game.h"
#include "BoardGUI.h"

class Graphical : public Observer {
    Game* game;


    public: 
        explicit Graphical(Game* game);
        ~Graphical() override;
        void notify() override;
};

#endif
