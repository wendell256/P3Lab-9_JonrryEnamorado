#include "Civilizacion.h"

Civilizacion::Civilizacion(string tname, int toro,int tmadera, int tpiedra, int talimento, int tpmax, int tpcapacidad){
    name = tname;
    oro = toro;
    madera = tmadera;
    piedra = tpiedra;
    alimento = talimento;
    pmax = tpmax;
    pcapacidad = tpcapacidad;

    pactual=0;
}

Civilizacion::Civilizacion(){

}

int Civilizacion::getAlimento(){
    return alimento;
}

void Civilizacion::setAlimento(int talimento){
    alimento = talimento;
}

int Civilizacion::getOro(){
    return oro;
}

void Civilizacion::setOro(int toro){
    oro = toro;
}

int Civilizacion::getMadera(){
    return madera;
}

void Civilizacion::setMadera(int tmadera){
    madera = tmadera;
}

int Civilizacion::getPiedra(){
    return piedra;
}

void Civilizacion::setPiedra(int tpiedra){
    piedra=tpiedra;
}

int Civilizacion::getPmax(){
    return pmax;
}

void Civilizacion::setPmax(int tpmax){
    pmax=tpmax;
}

int Civilizacion::getPactual(){
    return pactual;
}

void Civilizacion::setPactual(int tpmax){
    pmax=tpmax;
}

int Civilizacion::getPcapacidad(){
    return pcapacidad;
}

void Civilizacion::setPcapacidad(int tpcapacidad){
    pcapacidad=tpcapacidad;
}

void Civilizacion::addPcapacidad(){
    pcapacidad+=5;
    if(pcapacidad>=pmax){
        pcapacidad = pmax;
        cout<<"Has llegado al limite de poblacion";
    }

}

string Civilizacion::getName(){
    return name;
}

bool Civilizacion::crearAldeano(string sex){
    if(alimento>=55 && pactual<pcapacidad){
        alimento-=55;
        queueAldeanos.push_back(new Aldeano(sex));
        cout<<"Aldeano creado exitosamente!"<<endl;
        pactual++;
        return true;
    }else{
        cout<<"No es posible!"<<endl;
        return false;
    }

}

bool Civilizacion::crearSoldado(string sex){
    if(alimento>=90 && oro>=25 && pactual<pcapacidad){
        alimento-=90;
        oro-=25;
       
        queueTropas.push_back(new Soldado(sex));
        cout<<"Soldado añadido a queue exitosamente!"<<endl;
        pactual++;
        
        return true;
    }
    else{
        cout<<"No es posible!"<<endl;
       
        return false;
    }
}

bool Civilizacion::crearCaballeria(string sex){
    if(alimento>=110 && oro>=60 && pactual<pcapacidad){
        alimento-=110;
        oro-=60;
        queueTropas.push_back(new Caballeria(sex));
        cout<<"Caballeria añadido a queue exitosamente!"<<endl;
        pactual++;
        return true;
    }
    else{
        cout<<"No es posible!"<<endl;
        return false;
    }
}

bool Civilizacion::crearGuerreroEspecial(string sex){
    if(alimento>=150 && oro>=90 && pactual<pcapacidad){
        alimento-=150;
        oro-=90;
        queueTropas.push_back(new GuerreroEspecial(sex));
        cout<<"Guerrero Especial añadido a queue exitosamente!"<<endl;
        pactual++;
        return true;
    }
    else{
        cout<<"No es posible!"<<endl;
        return false;
    }
}

bool Civilizacion::crearCasa(){
    if(madera>=50){
        madera-=50;
        queueEdificios.push_back(new Casa());
        cout<<"Casa añadido a queue exitosamente!"<<endl;
        addPcapacidad();
        
        return true;

    }
    else
    {
        cout<<"No tienes suficiente recursos!"<<endl;
        return false;
    }
}

bool Civilizacion::crearCuartel(){
    if(madera>=120 && piedra>=80){
        madera-=120;
        piedra-=80;
        queueEdificios.push_back(new Cuartel());
        cout<<"Cuartel añadido a queue exitosamente!"<<endl;
        
        return true;

    }
    else
    {
        cout<<"No tienes suficiente recursos!"<<endl;
        return false;
    }
}

bool Civilizacion::crearCastillo(){
    if(madera>=275 && piedra>=200){
        madera-=275;
        piedra-=200;
        queueEdificios.push_back(new Castillo());
        cout<<"Cuartel añadido a queue exitosamente!"<<endl;
       
        return true;

    }
    else
    {
        cout<<"No tienes suficiente recursos!"<<endl;
        return false;
    }
}

void Civilizacion::moreResources(){
    int numAldeanos = AldeanosCreados.size();
    alimento+=50*numAldeanos;
    oro+= 30*numAldeanos;
    piedra+= 20*numAldeanos;
}

void Civilizacion::contarAldeanos(){
    cout<<"Aldeanos: "<<AldeanosCreados.size()<<endl;
}

void Civilizacion::contarTropas(){
    int soldado=0,caballeria=0,guerreros=0;
    for(int i=0;i<TropasCreadas.size();i++){
        Soldado* tmp_s = dynamic_cast<Soldado*>(TropasCreadas[i]);
        Caballeria* tmp_c = dynamic_cast<Caballeria*>(TropasCreadas[i]);
        GuerreroEspecial* tmp_g = dynamic_cast<GuerreroEspecial*>(TropasCreadas[i]);
        if(tmp_s!=NULL){
            soldado++;
        }
        else if(tmp_c!=NULL){
            caballeria++;
        }
        else if(tmp_g!=NULL){
            guerreros++;
        }
    }
    cout<<"Soldados: "<<soldado<<endl<<"Caballeria: "<<caballeria<<endl<<"Guerreros Especiales:"<<guerreros<<endl;
}

void Civilizacion::contarEdificios(){
    int casas=0,cuarteles=0,castillos=0;
    for(int i=0;i<EdificiosCreados.size();i++){
        Casa* tmp_s = dynamic_cast<Casa*>(EdificiosCreados[i]);
        Cuartel* tmp_c = dynamic_cast<Cuartel*>(EdificiosCreados[i]);
        Castillo* tmp_g = dynamic_cast<Castillo*>(EdificiosCreados[i]);
        if(tmp_s!=NULL){
            casas++;
        }
        else if(tmp_c!=NULL){
            cuarteles++;
        }
        else if(tmp_g!=NULL){
            castillos++;
        }
    }
    cout<<"Casas: "<<casas<<endl<<"Cuarteles: "<<cuarteles<<endl<<"Castillos:"<<castillos<<endl;
}

void Civilizacion::restarTurno(){
    for(int i=0;i<queueAldeanos.size();i++){
        queueAldeanos[i]->setTurno(queueAldeanos[i]->getTurno()-1);
    }
    for(int i=0;i<queueEdificios.size();i++){
        queueEdificios[i]->setTurno(queueEdificios[i]->getTurno()-1);
    }
    for(int i=0;i<queueTropas.size();i++){
        queueTropas[i]->setTurno(queueTropas[i]->getTurno()-1);
    }
}

void Civilizacion::inicio(){
    for(int i=0;i<queueAldeanos.size();i++){
       if(queueAldeanos[i]->getTurno()==0){
           cout<<"Nuevo aldeano creado"<<endl;
           AldeanosCreados.push_back(queueAldeanos[i]);
           Aldeano* tmp = queueAldeanos[i];
           delete tmp;
       }
    }
    for(int i=0;i<queueEdificios.size();i++){
        if(queueEdificios[i]->getTurno()==0){
           cout<<"Nuevo edificio creado"<<endl;
           EdificiosCreados.push_back(queueEdificios[i]);
           Edificio* tmp = queueEdificios[i];
           delete tmp;
       }
    }
    for(int i=0;i<queueTropas.size();i++){
       if(queueTropas[i]->getTurno()==0){
           cout<<"Nueva tropa creada"<<endl;
           TropasCreadas.push_back(queueTropas[i]);
           Tropa* tmp = queueTropas[i];
           delete tmp;
       }
    }
}
void Civilizacion::destierro(){
    queueAldeanos.clear();
    queueEdificios.clear();
    queueTropas.clear();

    AldeanosCreados.clear();
    TropasCreadas.clear();
    EdificiosCreados.clear();

    alimento = 100;
    piedra=0;
    oro=0;
    madera=0;
}

