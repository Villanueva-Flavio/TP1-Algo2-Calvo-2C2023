#include "Jugador.h"

#ifndef __JUEGO_H__
#define __JUEGO_H__

#define MAX_JUGADORES 2
#define MAX_INACTIVAS 50
struct Juego{
    Jugador jugador[MAX_JUGADORES];
    Fichas inactivas[MAX_INACTIVAS];
    int cantInactivas;
};

#endif