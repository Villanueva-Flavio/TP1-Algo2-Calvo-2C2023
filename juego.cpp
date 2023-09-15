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

void Juego::preguntarCoordenada(int jugador, Tipo tipo){
    int x, y;
    std::cout << "Jugador: " << jugador + 1 << " ingrese las coordenadas en X Y" << std::endl;
    std::cin >> x >> y;
    while(x < 0 || x > DEFAULT_SIZE || y < 0 || y > DEFAULT_SIZE){
        std::cout << "Coordenadas fuera de rango, ingrese nuevamente: ";
        std::cin >> x >> y;
        std::cout << std::endl;
    }
    (jugador == 0)?
        this->jugador1->getFichas(tipo)->add(new Fichas(x, y)):
        this->jugador2->getFichas(tipo)->add(new Fichas(x, y));
}

int Juego::buscarFicha(Coordenadas* pos){
    return this->jugador1->buscar(pos) == -1 ? this->jugador2->buscar(pos) : -1;
}

void Juego::asignarFichas(int jugador, Tipo tipo){

    this->preguntarCoordenada(jugador, tipo);
    Coordenadas aux = (jugador == 0)? 
        this->jugador1->getFichas(tipo)->getLData(this->jugador1->getFichas(tipo)->getSize() - 1)->getPos():
        this->jugador2->getFichas(tipo)->getLData(this->jugador2->getFichas(tipo)->getSize() - 1)->getPos();
    
    Coordenadas* pos = new Coordenadas(aux.getX(), aux.getY());
    
    while (this->jugador1->buscar(pos) != -1 && this->jugador2->buscar(pos) != -1){
        std::cout << "Coordenada ya ocupada, ingrese otra" << std::endl;
        (jugador == 0)?
            this->jugador1->getFichas(tipo)->remove(this->jugador1->buscar(pos)):
            this->jugador2->getFichas(tipo)->remove(this->jugador2->buscar(pos));
        this->preguntarCoordenada(jugador, tipo);
    }

    delete pos;
}

void Juego::iniciarJuego(){
    for(int fichas = 0; fichas < OBJETIVOS_MAXIMOS; fichas++){
        for(int jugador = 0; jugador < JUGADORES_MAXIMOS; jugador++){
            this->asignarFichas(jugador, TESORO);
        }
    }
}