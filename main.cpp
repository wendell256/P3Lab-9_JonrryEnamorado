#include "Civilizacion.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*COSAS PREDETERMINADAS
    aldeanos = {alimentacion = 55} recoge = {+50 alimento;+40madera;+30 oro; +20 piedra}
    soldado = {alimentacion = 90; oro = 25; ataque = 30; defensa = 15; vida = 100; velocidad = 50}
    caballeria = {alimentacion = 110; oro = 60; defensa = 5; vida = 150; velocidad = 85}
    guerro especial = {alimentacion = 150; oro = 90; vida = 300}

    casa = {madera = 50}
    cuartel = {madera = 120; piedra = 80}
    castillo = {madera = 275; piedra = 200}
*/
//funciones
int menuPrincipal();
void crearCiv();
void crearPlayer();
void ingresar();
void nuevoAldeano();
void recursos();
void nuevoEdificio();
void nuevaTropa();
void destierro();
void fight();
void listCivs();
//variables globales
vector<Civilizacion*> Civs;
vector<Player*> players;
Player* actual;

int main(){
    char resp='s';
    int seleccion;
    while(resp=='s' || resp=='S' && seleccion!=5){
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
        cout<<i+1<<") "<<Civs[0]->getName()<<endl;
    }
}

void ingresar(){

}