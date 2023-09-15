#include "fichas.h"

Fichas::Fichas(int x, int y) : pos(x, y), activa(true){}

bool Fichas::getActiva(){
    return this->activa;
}

void Fichas::setActiva(bool activa){
    this->activa = activa;
}

int Fichas::getX(){
    return this->pos.getX();
}

int Fichas::getY(){
    return this->pos.getY();
}

void Fichas::setX(int x){
    this->pos.setX(x);
}

void Fichas::setY(int y){
    this->pos.setY(y);
}