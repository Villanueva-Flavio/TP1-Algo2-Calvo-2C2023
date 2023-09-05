#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include "fichas.h"
#include "coordenadas.h"
#include "lista.h"

enum Tipo{
    TESORO,
    ESPIA
};

class Jugador{
    private:
        Lista<Fichas>* tesorosRestantes;
        Lista<Fichas>* espias; 
    
    public:
        Jugador();
        ~Jugador();
        Fichas obtenerFicha(int id, Tipo Ficha);
        bool jugadorPerdio();
        void agregarFicha(Fichas ficha, Tipo tipo);
        void eliminarFicha(Fichas ficha, Tipo tipo);

};

Jugador::Jugador(){
    tesorosRestantes = new Lista<Fichas>();
    espias = new Lista<Fichas>();
}

Jugador::~Jugador(){
    delete tesorosRestantes;
    delete espias;
}

Fichas Jugador::obtenerFicha(int id, Tipo tipo){
    if(tipo == TESORO){
        return tesorosRestantes->getLData(id);
    }else{
        return espias->getLData(id);
    }
}

bool Jugador::jugadorPerdio(){
    return tesorosRestantes->getSize() == 0;
}

void Jugador::agregarFicha(Fichas ficha, Tipo tipo){
    if(tipo == TESORO){
        tesorosRestantes->add(ficha);
    }else{
        espias->add(ficha);
    }
}

void Jugador::eliminarFicha(Fichas ficha, Tipo tipo){
    if(tipo == TESORO){
        this->tesorosRestantes->remove(this->tesorosRestantes->getIter());
    } else {
        this->espias->remove(this->espias->getIter());
    }
}


#endif