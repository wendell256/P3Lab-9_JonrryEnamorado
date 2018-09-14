#include "Civilizacion.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

//variables globales
vector<Civilizacion*> Civs;

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

}