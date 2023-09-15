#include "jugador.h"

Jugador::Jugador(){
    this->tesorosRestantes = new Lista<Fichas*>();
    this->espias = new Lista<Fichas*>();
    this->busqueda = new Lista<Fichas*>();
}

Jugador::~Jugador(){
    delete this->tesorosRestantes;
    delete this->espias;
    delete this->busqueda;
}

Lista<Fichas*>* Jugador::getFichas(Tipo tipo){
    return (tipo == TESORO)? 
        this->tesorosRestantes : 
        (tipo == ESPIA)? 
            this->espias: 
            this->busqueda;
}

Fichas* Jugador::obtenerFicha(int id, Tipo tipo){
    return (tipo == TESORO)?
        this->tesorosRestantes->getLData(id):
        (tipo == ESPIA)?
            this->espias->getLData(id):
            this->busqueda->getLData(id);
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
        } else if (this->busqueda->getLData(i)->getX() == pos->getX() && this->busqueda->getLData(i)->getY() == pos->getY()){
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
    (tipo == TESORO)?
        this->tesorosRestantes->add(ficha):
        (tipo == ESPIA)?
            this->espias->add(ficha):
            this->busqueda->add(ficha);
}

void Jugador::eliminarFicha(Fichas* ficha, Tipo tipo){
    (tipo == TESORO)?
        this->tesorosRestantes->remove(this->tesorosRestantes->getIter()):
        (tipo == ESPIA)?
            this->espias->remove(this->espias->getIter()):
            this->busqueda->remove(this->busqueda->getIter());
}