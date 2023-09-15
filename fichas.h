#ifndef __FICHAS_H__
#define __FICHAS_H__

#include "coordenadas.h"

class Fichas{
    private:
        Coordenadas pos;
        bool activa;

    public:
        Fichas(int x, int y);
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        bool getActiva();
        void setActiva(bool activa);
};


#endif