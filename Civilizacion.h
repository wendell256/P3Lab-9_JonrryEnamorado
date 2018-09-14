#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include <iostream>
#include <string>
using namespace std;

class Civilizacion{
    protected:
        string name;
        int oro, madera,piedra,alimento,pmax,pactual,pcapacidad;
    public:
        Civilizacion();
        Civilizacion(string,int,int,int,int,int,int);//name, oro, madera,piedra,alimento,pmax,pcapacidad
        int getOro();
        void setOro(int);
        int getMadera();
        void setMadera(int);
        int getPiedra();
        void setPiedra(int);
        int getAlimento();
        void setAlimento(int);
        int getPmax();
        void setPmax(int);
        int getPactual();
        void setPactual(int);
        int getPcapacidad();
        void setPcapacidad(int);
        void addPcapacidad();
};

#endif