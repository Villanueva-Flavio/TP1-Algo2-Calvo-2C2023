#ifndef __FICHAS_H__
#define __FICHAS_H__

#include "coordenadas.h"

class Fichas{
    private:
        Coordenadas pos;
        bool activa;

    public:
        Fichas(int x, int y);
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        bool getActiva();
        void setActiva(bool activa);
};

Fichas::Fichas(int x, int y) : pos(x, y), activa(true){}

bool Fichas::getActiva(){
    return this->activa;
}

void Fichas::setActiva(bool activa){
    this->activa = activa;
}

#endif