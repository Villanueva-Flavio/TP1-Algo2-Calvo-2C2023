#include "coordenadas.h"

Coordenadas::Coordenadas(){
    this->x = 0;
    this->y = 0;
}

Coordenadas::Coordenadas(int x, int y){
    this->x = x;
    this->y = y;
}

int Coordenadas::getX(){
    return this->x;
}

int Coordenadas::getY(){
    return this->y;
}

void Coordenadas::setX(int x){
    this->x = x;
}

void Coordenadas::setY(int y){
    this->y = y;
}

