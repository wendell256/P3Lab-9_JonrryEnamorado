#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Civilizacion.h"

using namespace std;

class Player{
    private:
        string name;
        Civilizacion* civ;
    public:
        Player(string,Civilizacion*);
        string getName();
        Civilizacion* getCivilizacion();
};

#endif