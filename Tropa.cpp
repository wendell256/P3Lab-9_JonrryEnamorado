#include "Tropa.h"

Tropa::Tropa(string sexo){
    this->sexo = sexo;
}

int Tropa::getTurno(){
    return tiempot;
}

void Tropa::setTurno(int tturno){
    tiempot=tturno;
}
