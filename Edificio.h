#ifndef EDIFICIO_H
#define EDIFICIO_H

class Edificio{
    protected:
        int cpiedra,cmadera,tiempot;
    public:
        Edificio();
        virtual ~Edificio(){};
        int getTurno();
        void setTurno(int);
};

#endif