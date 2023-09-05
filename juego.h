#ifndef __JUEGO_H__
#define __JUEGO_H__

#include "jugador.h"
#include "lista.h"

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
        // Seguir mas adelante con setters y getters y jugar
};

#endif