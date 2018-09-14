#include "Edificio.h"

Edificio::Edificio(){
    
    cpiedra = 0;
    cmadera = 0;
}

int Edificio::getTurno(){
    return tiempot;
}

void Edificio::setTurno(int tturno){
    tiempot=tturno;
}

Edificio::~Edificio(){
    cout<<"Edificio Eliminado"<<endl;;
}