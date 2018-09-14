#ifndef TROPA_H
#define TROPA_H

#include <string>
#include <iostream>
using namespace std;

class Tropa{
    protected:
        string sexo;
        int calimentacion, coro, attack,defensa,vida,velocidad, tiempot;
    public:
        Tropa(string);
        virtual int ataque(int){};
        int getTurno();
        int getVida();
        void setTurno(int);
        void restarVida(int);
        ~Tropa();
};

#endif