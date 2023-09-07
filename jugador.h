#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include "fichas.h"
#include "lista.h"

enum Tipo{
    TESORO,
    ESPIA
};

class Jugador{
    private:
        Lista<Fichas*>* tesorosRestantes;
        Lista<Fichas*>* espias; 
    
    public:
        Jugador();
        ~Jugador();
        Fichas* obtenerFicha(int id, Tipo Ficha);
        bool jugadorPerdio();
        void agregarFicha(Fichas* ficha, Tipo tipo);
        void eliminarFicha(Fichas* ficha, Tipo tipo);
        int buscar(Coordenadas* pos);

};

Jugador::Jugador(){
    this->tesorosRestantes = new Lista<Fichas*>();
    this->espias = new Lista<Fichas*>();
}

Jugador::~Jugador(){
    delete this->tesorosRestantes;
    delete this->espias;
}

Fichas* Jugador::obtenerFicha(int id, Tipo tipo){
    if(tipo == TESORO){
        return this->tesorosRestantes->getLData(id);
    }else{
        return this->espias->getLData(id);
    }
}

int Jugador::buscar(Coordenadas* pos){
    int resultado = -1;

    for(int i = 0; i < this->tesorosRestantes->getSize(); i++){
        if(this->tesorosRestantes->getLData(i)->getX() == pos->getX() && this->tesorosRestantes->getLData(i)->getY() == pos->getY()){
            resultado = i;
            i = this->tesorosRestantes->getSize();
        } else if (this->espias->getLData(i)->getX() == pos->getX() && this->espias->getLData(i)->getY() == pos->getY()){
            resultado = i;
            i = this->tesorosRestantes->getSize();
        }
    }
    return resultado;
}


bool Jugador::jugadorPerdio(){
    return this->tesorosRestantes->getSize() == 0;
}

void Jugador::agregarFicha(Fichas* ficha, Tipo tipo){
    if(tipo == TESORO){
        this->tesorosRestantes->add(ficha);
    }else{
        this->espias->add(ficha);
    }
}

void Jugador::eliminarFicha(Fichas* ficha, Tipo tipo){
    if(tipo == TESORO){
        this->tesorosRestantes->remove(this->tesorosRestantes->getIter());
    } else {
        this->espias->remove(this->espias->getIter());
    }
}


#endif