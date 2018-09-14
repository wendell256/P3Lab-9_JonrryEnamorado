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

void Civilizacion::setPiedra(int tpiedra){
    piedra=tpiedra;
}

int Civilizacion::getPmax(){
    return pmax;
}

void Civilizacion::setPmax(int tpmax){
    pmax=tpmax;
}

int Civilizacion::getPactual(){
    return pactual;
}

void Civilizacion::setPactual(int tpmax){
    pmax=tpmax;
}

int Civilizacion::getPcapacidad(){
    return pcapacidad;
}

void Civilizacion::setPcapacidad(int tpcapacidad){
    pcapacidad=tpcapacidad;
}

void Civilizacion::addPcapacidad(){
    pcapacidad+=5;
    if(pcapacidad>=pmax){
        pcapacidad = pmax;
        cout<<"Has llegado al limite de poblacion";
    }

}