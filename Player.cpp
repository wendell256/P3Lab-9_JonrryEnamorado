#include "Player.h"

Player::Player(string name, Civilizacion* civ){
    this->name=name;
    this->civ=civ;
    turno=1;
}

string Player::getName(){
    return name;
}

Civilizacion* Player::getCivilizacion(){
    return civ;
}

int Player::getTurno(){
    return turno;
}

void Player::setTurno(int tturno){
    turno=tturno;
}