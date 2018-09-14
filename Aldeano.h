#ifndef ALDEANO_H
#define ALDEANO_H

#include <string>
using namespace std;

class Aldeano{
    private:
        string sexo;
        int calimentacion,turno;
    public:
        Aldeano(string);
        int getTurno();
        void setTurno(int);
};

#endif