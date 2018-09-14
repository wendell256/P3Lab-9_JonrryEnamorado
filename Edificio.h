#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>
using namespace std;
class Edificio{
    protected:
        int cpiedra,cmadera,tiempot;
    public:
        Edificio();
        virtual int verTipo(){};
        int getTurno();
        void setTurno(int);
    ~Edificio();
};

#endif