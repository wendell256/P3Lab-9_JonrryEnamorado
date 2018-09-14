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

void Tropa::restarVida(int ataque){
    vida-=ataque;
    cout<<"TU TROPA HA PERDIDO"<<ataque<<" DE VIDA. Vida restante: ";
    if (vida>0){
        cout<<vida<<endl;
    } 
    else{
        cout<<0<<endl;
    }
}

int Tropa::getVida(){
    return vida;
}

Tropa::~Tropa(){
    cout<<"Tropa eliminada"<<endl;
}