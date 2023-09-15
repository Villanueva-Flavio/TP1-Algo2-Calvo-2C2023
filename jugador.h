#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include "fichas.h"
#include "lista.h"

enum Tipo{
    TESORO,
    ESPIA,
    NADA
};

class Jugador{
    private:
        Lista<Fichas*>* tesorosRestantes;
        Lista<Fichas*>* espias; 
        Lista<Fichas*>* busqueda;
    
    public:
        Jugador();
        ~Jugador();
        Fichas* obtenerFicha(int id, Tipo Ficha);
        bool jugadorPerdio();
        void agregarFicha(Fichas* ficha, Tipo tipo);
        void eliminarFicha(Fichas* ficha, Tipo tipo);
        int buscar(Coordenadas* pos);
        Lista<Fichas*>* getFichas(Tipo tipo);        
};

#endif