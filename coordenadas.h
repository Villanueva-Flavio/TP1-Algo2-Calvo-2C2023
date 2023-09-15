#ifndef __COORDENADAS_H__
#define __COORDENADAS_H_

class Coordenadas{
    private:
        int x;
        int y;

    public: 
        Coordenadas(int x, int y);
        Coordenadas();
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
};

#endif