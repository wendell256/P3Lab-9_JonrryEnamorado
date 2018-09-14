#ifndef TROPA_H
#define TROPA_H

#include <string>
using namespace std;

class Tropa{
    protected:
        string sexo;
        int calimentacion, coro, attack,defensa,vida,velocidad, tiempot;
    public:
        Tropa(string);
        virtual int ataque(int);
};

#endif