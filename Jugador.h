#include "Fichas.h"

#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#define MAX_TESOROS 5
#define MAX_ESPIAS 50

struct Jugador{
    Fichas tesoros[MAX_TESOROS];
    Fichas espias[MAX_ESPIAS];
    int cantTesoros;
    int cantEspias;
};

#endif