#ifndef __JUEGO_H__
#define __JUEGO_H__

#include "jugador.h"
#include "lista.h"

#define DEFAULT_SIZE 20
#define OBJETIVOS_MAXIMOS 4
#define JUGADORES_MAXIMOS 2

class Juego{
    private:
        Jugador* jugador1;
        Jugador* jugador2;
        Lista<Coordenadas>* inactivas;
        int size;
    
    public: 
        Juego();
        ~Juego();
        void iniciarJuego();
        void imprimirTableros();
        void jugarTurno(int jugador);
        void preguntarCoordenada(Coordenadas* pos);
        void asignarFichas(Coordenadas* pos, int jugador);
        int buscarFicha(Coordenadas* pos);
};

Juego::Juego(){
    this->jugador1 = new Jugador();
    this->jugador2 = new Jugador();
    this->inactivas = new Lista<Coordenadas>();
    this->size = DEFAULT_SIZE;
}

Juego::~Juego(){
    delete jugador1;
    delete jugador2;
    delete inactivas;
}

void Juego::preguntarCoordenada(Coordenadas* pos){
    int x, y;
    std::cout << "Ingrese las coordenadas en X Y" << std::endl;
    std::cin >> x >> y;
    while(x < 0 || x > DEFAULT_SIZE || y < 0 || y > DEFAULT_SIZE){
        std::cout << "Ingrese las coordenadas en X Y" << std::endl;
        std::cin >> x >> y;
    }
    pos->setX(x);
    pos->setY(y);
}

int Juego::buscarFicha(Coordenadas* pos){
    return this->jugador1->buscar(pos) == -1 ? this->jugador2->buscar(pos) : -1;
}

void Juego::asignarFichas(Coordenadas* pos, int jugador){
    preguntarCoordenada(pos);
    while (this->inactivas->find(*pos) != -1 && this->jugador1->buscar(pos) != -1 && this->jugador2->buscar(pos) != -1){
        std::cout << "Coordenada ya ocupada, ingrese otra" << std::endl;
        preguntarCoordenada(pos);
    }
}

void Juego::iniciarJuego(){
    for(int fichas = 0; fichas < OBJETIVOS_MAXIMOS; fichas++){
        for(int jugadores = 0; jugadores < JUGADORES_MAXIMOS; jugadores++){
            Coordenadas* pos = new Coordenadas();
            asignarFichas(pos, jugadores);
            delete pos;
        }
    }
}

#endif