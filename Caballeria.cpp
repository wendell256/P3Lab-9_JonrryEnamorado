#include "Caballeria.h"

Caballeria::Caballeria(string sexo):Tropa(sexo){
    calimentacion = 110;
    coro = 60;
    defensa = 5;
    vida = 150;
    velocidad = 85;
    tiempot = 2;
    attack = 30;
}

int Caballeria::ataque(int enemigo){
    //attack especial
    return attack + velocidad/2;
}

