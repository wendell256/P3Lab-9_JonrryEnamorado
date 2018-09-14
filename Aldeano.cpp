#include "Aldeano.h"

Aldeano::Aldeano(string sexo){
    this->sexo=sexo;
    calimentacion = 50;
    turno=1;
}

int Aldeano::getTurno(){
    return turno;
}

void Aldeano::setTurno(int tturno){
    turno=tturno;
}