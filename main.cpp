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
/*COSAS PREDETERMINADAS
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

//variables globales
vector<Civilizacion*> Civs;
vector<Player*> players;
Player* actual;
int forzar;

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
}

int menuPrincipal(){
    int seleccion;
    cout<<endl<<"AGE OF EMPIRE II"<<endl<<endl<<"1) Crear Civilización"<<endl<<"2) Crear Jugador"
        <<"3) Guardar Información"<<endl<<"4) Ingresar"<<endl<<"5) FINALIZAR"<<"Ingrese una opcion: "<<endl;
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
    listCivs();
    cout<<"Seleccione Civilizacion para jugador:"<<endl;
    cin>>sel;
    while(sel<1 || sel>Civs.size()-1){
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
    int sel,opc,opc2;
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
    actual = players[sel];
    actual->getCivilizacion()->inicio();
    listEverything(actual->getCivilizacion());

    cout<<"Que deseas hacer en este turno?"<<endl<<"1) Nuevo aldeano"<<endl<<"2) Buscar Recursos"<<endl<<"3) Nuevo Edificio"<<endl
        <<"4) Nueva Tropa"<<endl<<"5) Desterrar poblacion"<<endl<<"6) Batalla"<<endl<<"7) Finalizar Turno"<<"8) Volver a menu principal"<<endl<<"Seleccione una opcion:"<<endl;
    cin>>opc;
    switch(opc){
        case 1:
            cout<<"Ingrese sexo:"<<endl;
            cin>>sex;
            actual->getCivilizacion()->crearAldeano(sex);
            break;
        case 2:
            recursos = true;
            break;
        case 3: 
            cout<<"1) Casa"<<endl<<"2) Cuartel"<<"3) Castillo"<<endl<<"INgrese opcion:"<<endl;
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
            cout<<"Sexo de nueva tropa:"<<endl;
            cin>>sex;
            cout<<"1) Soldado"<<endl<<"2) Caballeria"<<"3) Guerrero Especial"<<endl<<"Ingrese opcion:"<<endl;
            cin>>opc2;
            switch(opc2){
                case 1:
                    actual->getCivilizacion()->crearSoldado(sex);
                    break;
                case 2:
                    actual->getCivilizacion()->crearCaballeria(sex);
                    break;
                case 3:
                    actual->getCivilizacion()->crearGuerreroEspecial(sex);
                    break;
                default:
                    cout<<"ERROR"<<endl;
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
            if(recursos){
                actual->getCivilizacion()->moreResources();
            }
            actual->getCivilizacion()->restarTurno();
            break;
        case 8:
            forzar=1;
            break;
        default:
        cout<<"ERROR"<<endl;
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

}