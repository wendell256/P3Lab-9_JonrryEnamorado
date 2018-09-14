#include "Civilizacion.h"
#include "Player.h"
#include "Aldeano.h"
#include "Caballeria.h"
#include "Casa.h"
#include "Castillo.h"
#include "Cuartel.h"
#include "Edificio.h"
#include "GuerreroEspecial.h"
#include "Soldado.h"
#include "Tropa.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*COSAS PREDETERMINADAS README FIRST
    aldeanos = {alimentacion = 55} recoge = {+50 alimento;+40madera;+30 oro; +20 piedra; turnos = 1}
    soldado = {alimentacion = 90; oro = 25; ataque = 30; defensa = 15; vida = 100; velocidad = 50;turnos =1}
    caballeria = {alimentacion = 110; oro = 60; defensa = 5; vida = 150; velocidad = 85 ;turnos = 2}
    guerro especial = {alimentacion = 150; oro = 90; vida = 300; turnos = 3}

    casa = {madera = 50; turnos = 1}
    cuartel = {madera = 120; piedra = 80; turnos = 2}
    castillo = {madera = 275; piedra = 200; turnos = 3}
*/
//funciones
int menuPrincipal();
void crearCiv();
void crearPlayer();
void ingresar();
void destierro();
void fight();
void listCivs();
void listPlayers();
void listEverything(Civilizacion*);
int revisarGane();
void destructores();

//variables globales
vector<Civilizacion*> Civs;
vector<Player*> players;
Player* actual;
Player* enemy;
int forzar,turno=0;
Tropa* actualfight;
Tropa* enemyfight;

int main(){
    char resp='s';
    int seleccion;
    int forzar=0;
    while(resp=='s' || resp=='S' || forzar==1 && seleccion!=5 ){
        forzar =0;
        seleccion = menuPrincipal();
        switch(seleccion){
            case 1:
                crearCiv();
                break;
            case 2:
                if(Civs.empty()){
                    cout<<"ERROR NO HAY CIVILIZACIONES"<<endl;
                }else{
                crearPlayer();
                }
                break;
            case 3:
                //texto
                break;
            case 4:
                if(players.size()==0)
                    cout<<"*ERROR no hay players*";
                else
                    ingresar();
                break;
            case 5:
                break;
            default:
                cout<<"ERROR. Finalizando...";
                break;
        }
        cout<<"Reiniciar?s/n"<<endl;
        cin>>resp;

    }
    destructores();
}

int menuPrincipal(){
    int seleccion;
    cout<<endl<<"AGE OF EMPIRE II"<<endl<<endl<<"1) Crear Civilización"<<endl<<"2) Crear Jugador"<<endl
        <<"3) Guardar Información"<<endl<<"4) Ingresar"<<endl<<"5) FINALIZAR"<<endl<<"Ingrese una opcion: "<<endl;
    cin>>seleccion;
    while(seleccion<1 || seleccion>4){
        cout<<"ERROR seleccione una opcion valida:"<<endl;
        cin>>seleccion;    
    }
    return seleccion;
}

void crearCiv(){
    string name;
    int oro,madera,piedra,alimento,pmax,pcapacity;
    cout<<"NUEVA CIVILIZACION"<<endl<<endl<<"Ingrese el nombre de nueva civilizacion:"<<endl;
    cin>>name;
    cout<<name<<" empieza con esta cantidad de oro:"<<endl;
    cin>>oro;
    cout<<name<<" empieza con esta cantidad de alimento:"<<endl;
    cin>>alimento;
    cout<<name<<" empieza con esta cantidad de madera:"<<endl;
    cin>>madera;
    cout<<name<<" empieza con esta cantidad de piedra:"<<endl;
    cin>>piedra;
    cout<<name<<" puede tener este maximo de poblacion: "<<endl;
    cin>>pmax;
    cout<<name<<" empieza con esta cantidad de capacidad de poblacion: "<<endl;
    cin>>pcapacity;
    Civs.push_back(new Civilizacion(name,oro,madera,piedra,alimento,pmax,pcapacity));
    cout<<"NUEVA CIVILIZACION CREADA EXITOSAMENTE"<<endl;

}

void crearPlayer(){
    string name;
    Civilizacion* civ;
    int sel;
    cout<<"NUEVO JUGADOR"<<endl<<"Ingrese el nombre del nuevo jugador:"<<endl;
    cin>>name;
    cout<<endl<<"*Seleccionar civilizacion*"<<endl;
    listCivs();
    cout<<"Seleccione Civilizacion para jugador:"<<endl;
    cin>>sel;
    while(sel<1 || sel>Civs.size()){
        cout<<"ERROR seleccione de nuevo:"<<endl;
        cin>>sel;
    }
    sel--;
    civ = Civs[sel];

    players.push_back(new Player(name,civ));
    cout<<"NUEVO JUGADOR CREADO EXITOSAMENTE"<<endl;
}

void listCivs(){
    for(int i=0;i<Civs.size();i++){
        cout<<i+1<<") "<<Civs[i]->getName()<<endl;
    }
}

void listPlayers(){
    for(int i=0; i<players.size();i++){
        cout<<i+1<<") "<<players[i]->getName()<<endl;
    }
}

void ingresar(){
    int sel,opc,opc2,seguir=0;
    bool recursos=false;
    string sex;
    cout<<"SELECCIONE JUGADOR"<<endl;
    listPlayers();
    cout<<"Seleccione una opcion: "<<endl;
    cin>>sel;
    while(sel<1 || sel>players.size()){
        cout<<"ERROR seleccione de nuevo:"<<endl;
        cin>>sel;
    }
    sel--;
    actual = players[sel];
    while(actual->getTurno()==0){
        cout<<"ERROR ya jugaste tu turno esta ronda elige otro player:"<<endl;
        cin>>sel;
        while(sel<1 || sel>players.size()){
            cout<<"ERROR seleccione de nuevo:"<<endl;
            cin>>sel;
        }
        sel--;
        actual = players[sel];
    }
    cout<<endl;
    actual->getCivilizacion()->inicio();
    cout<<endl;
    listEverything(actual->getCivilizacion());
    cout<<endl;
    while(seguir==0){
        cout<<"Que deseas hacer en este turno?"<<endl<<"1) Nuevo aldeano"<<endl<<"2) Buscar Recursos"<<endl<<"3) Nuevo Edificio"<<endl
            <<"4) Nueva Tropa"<<endl<<"5) Desterrar poblacion"<<endl<<"6) Batalla"<<endl<<"7) Finalizar Turno"<<endl<<"8) Volver a menu principal"<<endl<<"Seleccione una opcion:"<<endl;
        cin>>opc;
        switch(opc){
            case 1:
                cout<<"Ingrese sexo:"<<endl;
                cin>>sex;
                actual->getCivilizacion()->crearAldeano(sex);
                break;
            case 2:
                recursos = true;
                cout<<"*Has enviado a todos tus recolectores a recoger, eso es si tienes aldeanos...*"<<endl;
                break;
            case 3: 
                cout<<"1) Casa"<<endl<<"2) Cuartel"<<endl<<"3) Castillo"<<endl<<"Ingrese opcion:"<<endl;
                cin>>opc2;
                switch(opc2){
                    case 1:
                        actual->getCivilizacion()->crearCasa();
                        break;
                    case 2:
                        actual->getCivilizacion()->crearCuartel();
                        break;
                    case 3:
                        actual->getCivilizacion()->crearCastillo();
                        break;
                    default:
                        cout<<"ERROR"<<endl;
                }
                break;
            case 4:
                if(actual->getCivilizacion()->getCuartel()){
                    cout<<"Sexo de nueva tropa:"<<endl;
                    cin>>sex;
                    cout<<"1) Soldado"<<endl<<"2) Caballeria"<<endl<<"3) Guerrero Especial"<<endl<<"Ingrese opcion:"<<endl;
                    cin>>opc2;
                    switch(opc2){
                        case 1:
                            actual->getCivilizacion()->crearSoldado(sex);
                            break;
                        case 2:
                            actual->getCivilizacion()->crearCaballeria(sex);
                            break;
                        case 3:
                            if(actual->getCivilizacion()->getCastillo()){
                                actual->getCivilizacion()->crearGuerreroEspecial(sex);
                            }
                            else{
                                cout<<"NO TIENES CASTILLO"<<endl;
                            }
                            break;
                        default:
                            cout<<"ERROR"<<endl;
                    }
                }
                else{
                    cout<<"**NO TIENES CUARTEL**"<<endl;
                }
                break;
            case 5:
                actual->getCivilizacion()->destierro();
                cout<<"DESTIERRO EXITOSO!"<<endl;
                break;
            case 6:
                fight();
                break;
            case 7:
                cout<<"Finalizando turno..."<<endl;
                seguir=1;
                actual->setTurno(0);
                if(recursos){
                    actual->getCivilizacion()->moreResources();
                }
                
              
                
                    actual->getCivilizacion()->restarTurno();
                
                break;
            case 8:
                forzar=1;
                cout<<"Finalizando turno..."<<endl;
                actual->setTurno(0);
                seguir=1;
                if(recursos){
                    actual->getCivilizacion()->moreResources();
                }
                actual->getCivilizacion()->restarTurno();
                
                break;
            default:
            cout<<"ERROR"<<endl;
        }
    }
    int tmp=0;
    for(int i=0;i<players.size();i++){
        
            if(players[i]->getTurno()!=0){
                tmp++;
            }
    }
    if(tmp==0){
        for(int i=0;i<players.size();i++){
            players[i]->setTurno(1);
        }
    }
}

void listEverything(Civilizacion* tmp){
    cout<<"RECURSOS"<<endl<<"Alimento: "<<tmp->getAlimento()<<endl<<"Oro: "<<tmp->getOro()<<endl<<"Piedra: "<<tmp->getPiedra()<<endl<<"Madera: "<<tmp->getMadera()<<endl;
    cout<<"VALORES POBLACIONALES"<<endl<<"Poblacion: "<<tmp->getPactual()<<" de "<<tmp->getPcapacidad()<<"(Maximo: "<<tmp->getPmax()<<")"<<endl;
    tmp->contarAldeanos();
    tmp->contarTropas();
    tmp->contarEdificios();
}

void fight(){
    int sel,opc,gane=-1;
    actualfight=NULL;
    enemyfight=NULL;
    cout<<"SELECCIONE JUGADOR ENEMIGO"<<endl;
    listPlayers();
    cout<<"Seleccione una opcion: "<<endl;
    cin>>sel;
    while(sel<1 || sel>players.size()){
        cout<<"ERROR seleccione de nuevo:"<<endl;
        cin>>sel;
    }
    sel--;
    enemy = players[sel];
    if(actual->getName()==enemy->getName()){
        cout<<"ES UNA GUERRA CIVIL";
    }
    while(gane<0){
        if(actualfight==NULL){
            cout<<actual->getName()<< " selecciona tropa a mandar a batalla: "<<endl;
            actual->getCivilizacion()->contarTropas();
            cout<<"1) Soldado"<<endl<<"2) Caballeria"<<endl<<"3) Guerrero Especial"<<endl<<"Ingrese opcion:"<<endl;
            cin>>opc;
            switch(opc){
                case 1:
                    actualfight=actual->getCivilizacion()->RestarSoldado();

                    break;
                case 2:
                    actualfight=actual->getCivilizacion()->RestarCaballeria();
                    break;
                case 3:
                    actualfight=actual->getCivilizacion()->RestarGuerreroEspecial();
                    break;
                default:
                    cout<<"ERROR"<<endl;
            }
        }
            if(actualfight != NULL){
                if(enemyfight == NULL){
                    cout<<enemy->getName()<< " selecciona tropa a mandar a batalla: "<<endl;
                    enemy->getCivilizacion()->contarTropas();
                    cout<<"1) Soldado"<<endl<<"2) Caballeria"<<endl<<"3) Guerrero Especial"<<endl<<"Ingrese opcion:"<<endl;
                    cin>>opc;
                    switch(opc){
                        case 1:
                            enemyfight=enemy->getCivilizacion()->RestarSoldado();

                            break;
                        case 2:
                            enemyfight=enemy->getCivilizacion()->RestarCaballeria();
                            break;
                        case 3:
                            enemyfight=enemy->getCivilizacion()->RestarGuerreroEspecial();
                            break;
                        default:
                            cout<<"ERROR"<<endl;
                    }
                }
                if(enemyfight != NULL){
                    cout<<"BATALLA COMIENZA"<<endl;
                    while(actualfight->getVida()>0 && enemyfight->getVida()>0){
                        cout<<enemy->getName()<<": "<<endl<<" ";
                        enemyfight->restarVida(actualfight->ataque(enemyfight->getVida()));
                        cout<<actual->getName()<<": "<<endl<<" ";
                        actualfight->restarVida(enemyfight->ataque(actualfight->getVida()));
                    }
                }
                else{
                    cout<<"error no se pudo inicializar"<<endl;
                }
            }else{
                cout<<"error no se pudo inicializar"<<endl;
            }
        gane=revisarGane();
    }

}

int revisarGane(){
    if(actual->getCivilizacion()->contarSoldados()==0 && actual->getCivilizacion()->contarCaballeria()==0 && actual->getCivilizacion()->contarGuerreros()==0 &&actualfight->getVida()==0){
        cout<<"HA GANADO "<<enemy->getName();
        return 1;
    }
    else if(enemy->getCivilizacion()->contarSoldados()==0 && enemy->getCivilizacion()->contarCaballeria()==0 && enemy->getCivilizacion()->contarGuerreros()==0 &&enemyfight->getVida()==0){
        cout<<"HA GANADO "<<actual->getName();
        return 0;
    }
    else{
        return -1;
    }
}

void destructores(){
    delete actual;
    delete enemy;
    for(int i=0;i<Civs.size();i++){
        delete Civs[i];
    }
    for(int i=0;i<players.size();i++){
        delete players[i];
    }
}