#ifndef GUERREROESPECIAL_H
#define GUERREROESPECIAL_H

#include "Tropa.h"

class GuerreroEspecial: public Tropa{
    public:
        GuerreroEspecial(string);
        virtual int ataque(int);
};

#endif