#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Civilizacion.h"
#include "Edificio.h"
#include "Tropa.h"
#include "Casa.h"
#include "Castillo.h"
#include "Cuartel.h"
#include "Soldado.h"
#include "Caballeria.h"
#include "GuerreroEspecial.h"
#include "Aldeano.h"

using namespace std;

class Player{
    private:
        string name;
        int turno;
        Civilizacion* civ;
        
    public:
        int getTurno();
        void setTurno(int);
        Player(string,Civilizacion*);
        string getName();
        Civilizacion* getCivilizacion();

};

#endif