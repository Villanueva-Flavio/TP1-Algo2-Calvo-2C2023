#include "juego.h"
#include <cstdlib>
#define DEFAULT_SIZE 20
#define OBJETIVOS_MAXIMOS 4
#define JUGADORES_MAXIMOS 2

Juego::Juego(){
    this->jugador1 = new Jugador();
    this->jugador2 = new Jugador();
    this->size = DEFAULT_SIZE;
}

Juego::~Juego(){
    delete jugador1;
    delete jugador2;
}

void Juego::preguntarCoordenada(Coordenadas* pos){
    int x, y;
    std::cout << "ingrese las coordenadas en X Y" << std::endl;
    std::cin >> x >> y;
    while(x < 0 || x > DEFAULT_SIZE || y < 0 || y > DEFAULT_SIZE){
        std::cout << "Coordenadas fuera de rango, ingrese nuevamente: ";
        std::cin >> x >> y;
        std::cout << std::endl;
    }
    pos->setX(x);
    pos->setY(y);
}

int Juego::buscarFicha(Coordenadas* pos){
    return this->jugador1->buscar(pos) == -1 ? this->jugador2->buscar(pos) : -1;
}

void Juego::asignarFichas(Coordenadas* pos, int jugador){
    //std::system("clear");
    std::cout << "Jugador " << jugador + 1 << std::endl;
    preguntarCoordenada(pos);
    std::cout << std::endl << this->jugador1->buscar(pos) << "   " << this->jugador2->buscar(pos) << std::endl;
    std::cin;
    while (this->jugador1->buscar(pos) != -1 && this->jugador2->buscar(pos) != -1){
        std::cout << "Coordenada ya ocupada, ingrese otra" << std::endl;
        preguntarCoordenada(pos);
    }
    if(jugador == 0){
        this->jugador1->agregarFicha(new Fichas(pos->getX(), pos->getY()), TESORO);
        std::cout << "ADDED P1" << std::endl;
    } else {
        this->jugador2->agregarFicha(new Fichas(pos->getX(), pos->getY()), TESORO);
        std::cout << "ADDED P2" << std::endl;
    }
}

void Juego::iniciarJuego(){
    for(int fichas = 0; fichas < OBJETIVOS_MAXIMOS; fichas++){
        for(int jugadores = 0; jugadores < JUGADORES_MAXIMOS; jugadores++){
            Coordenadas* pos = new Coordenadas();
            asignarFichas(pos, jugadores);
        }
    }
}