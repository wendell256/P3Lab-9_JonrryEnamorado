#include "Soldado.h"

Soldado::Soldado(string sexo):Tropa(sexo){
    calimentacion = 90;
    coro = 25;
    defensa = 15;
    vida = 100;
    velocidad = 50;
    tiempot = 1;
}

int Soldado::ataque(int oponente){
    return 30;
}