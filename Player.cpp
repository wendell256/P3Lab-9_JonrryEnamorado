#include "Player.h"

Player::Player(string name, Civilizacion* civ){
    this->name=name;
    this->civ=civ;
}

string Player::getName(){
    return name;
}

Civilizacion* Player::getCivilizacion(){
    return civ;
}