#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include <iostream>
#include <string>

#include <vector>
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

class Civilizacion{
    protected:
        string name;
        int oro, madera,piedra,alimento,pmax,pactual,pcapacidad;
        vector<Edificio*> queueEdificios;
        vector<Tropa*> queueTropas;
        vector<Aldeano*> queueAldeanos;
        bool cuartel=false;
        vector<Edificio*> EdificiosCreados;
        vector<Tropa*> TropasCreadas;
        vector<Aldeano*> AldeanosCreados;
    public:
        Civilizacion();
        Civilizacion(string,int,int,int,int,int,int);//name, oro, madera,piedra,alimento,pmax,pcapacidad
        string getName();
        bool getCuartel();
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
        bool crearAldeano(string);
        bool crearSoldado(string);
        bool crearCaballeria(string);
        bool crearGuerreroEspecial(string);
        bool crearCasa();
        bool crearCuartel();
        bool crearCastillo();
        void moreResources();
        void contarAldeanos();
        void contarTropas();
        void contarEdificios();
        void restarTurno();
        void destierro();
        void inicio();
        Tropa* RestarSoldado();
        Tropa* RestarCaballeria();
        Tropa* RestarGuerreroEspecial();
        int contarSoldados();
        int contarCaballeria();
        int contarGuerreros();
        ~Civilizacion();
};

#endif