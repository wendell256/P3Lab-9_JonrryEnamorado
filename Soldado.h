#ifndef SOLDADO_H
#define SOLDADO_H

#include "Tropa.h"

class Soldado:public Tropa{
    public:
        Soldado(string);
        virtual int ataque(int);
};

#endif