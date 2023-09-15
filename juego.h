#ifndef __JUEGO_H__
#define __JUEGO_H__

#include "jugador.h"

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

#endif