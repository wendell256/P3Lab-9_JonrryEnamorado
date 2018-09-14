#include "GuerreroEspecial.h"

GuerreroEspecial::GuerreroEspecial(string sexo):Tropa(sexo){
    calimentacion = 150;
    coro = 90;
    vida = 300;
    defensa = 15;
    //buff defensa
    defensa+=10;
    attack = 30;
    velocidad = 65;
    tiempot = 3;
}

int GuerreroEspecial::ataque(int enemigo){
    return attack*(1+velocidad/5) + enemigo*.15;
}