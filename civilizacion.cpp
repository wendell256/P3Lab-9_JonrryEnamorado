#include "civilizacion.h"

Civilizacion::Civilizacion(string tname, int toro,int tmadera, int tpiedra, int talimento, int tpmax, int tpcapacidad){
    name = tname;
    oro = toro;
    madera = tmadera;
    piedra = tpiedra;
    alimento = talimento;
    pmax = tpmax;
    pcapacidad = tpcapacidad;

    pactual=0;
}

Civilizacion::Civilizacion(){

}

int Civilizacion::getAlimento(){
    return alimento;
}

void Civilizacion::setAlimento(int talimento){
    alimento = talimento;
}

int Civilizacion::getOro(){
    return oro;
}

void Civilizacion::setOro(int toro){
    oro = toro;
}

int Civilizacion::getMadera(){
    return madera;
}

void Civilizacion::setMadera(int tmadera){
    madera = tmadera;
}

int Civilizacion::getPiedra(){
    return piedra;
}