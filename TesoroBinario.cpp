#include "Juego.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

#define MAX_SIZE 20

using namespace std;

enum Tipo{TESORO, ESPIA};






void preguntarCoordenada(Coordenada* pos){
    cout << "Ingrese una coordenada en formato X Y" << endl;
    cin >> pos->x >> pos->y;
    pos->x -= 1;
    pos->y -= 1;
    while(pos->x < 0 || pos->x > MAX_SIZE || pos->y < 0 || pos->y > MAX_SIZE){
        cout << "Coordenada fuera de rango, ingrese otra" << endl;
        cin >> pos->x >> pos->y;
    }
}

bool coordenadaOcupada(Coordenada pos, Jugador jugador[MAX_JUGADORES]){
    bool resultado = false;
    for(int i = 0; i < MAX_JUGADORES; i++){
        for(int j = 0; j < jugador[i].cantTesoros; j++){
            if(jugador[i].tesoros[j].posicion.x == pos.x && jugador[i].tesoros[j].posicion.y == pos.y){
                resultado = true;
            }
        }
        for(int j = 0; j < jugador[i].cantEspias; j++){
            if(jugador[i].espias[j].posicion.x == pos.x && jugador[i].espias[j].posicion.y == pos.y){
                resultado = true;
            }
        }
    }
    return resultado;
}

Coordenada obtenerPosicion(Jugador jugador[MAX_JUGADORES]){
    Coordenada pos;
    cout << "Ficha numero " << jugador->cantTesoros + jugador->cantEspias + 1 << endl;
    preguntarCoordenada(&pos);
    while(coordenadaOcupada(pos, jugador)){
        cout << "Coordenada ocupada, ingrese otra" << endl;
        preguntarCoordenada(&pos);
    }
    return pos;
}

void generarFicha(Jugador jugador[MAX_JUGADORES], int jugadorActual, Tipo tipo){
    system("clear");
    cout << "Jugador " << jugadorActual + 1 << endl;
    Coordenada pos = obtenerPosicion(jugador);
    jugador[jugadorActual].tesoros[jugador[jugadorActual].cantTesoros].posicion = pos;
    jugador[jugadorActual].cantTesoros++;
    if(tipo == ESPIA){
        jugador[jugadorActual].espias[jugador[jugadorActual].cantEspias].posicion = pos;
        jugador[jugadorActual].cantEspias++;
    }
}

void limpiarTopes(Juego* juego){
    for(int i = 0; i < MAX_JUGADORES; i++){
        juego->jugador[i].cantTesoros = 0;
        juego->jugador[i].cantEspias = 0;
    }
    juego->cantInactivas = 0;
}

void iniciarJuego(Juego* juego){
    limpiarTopes(juego);
    for(int i = 0; i < MAX_TESOROS+1; i++){
        for(int j = 0; j < MAX_JUGADORES; j++){
            generarFicha(juego->jugador, j, (i == MAX_TESOROS)? ESPIA : TESORO);
        }
    }
}

int jugadorGanador(Juego juego){
    return (juego.jugador[0].cantTesoros == 0)? 1 : (juego.jugador[1].cantTesoros == 0)? 0 : -1;
}

bool estaEnRango(Coordenada pos){
    return (pos.x >= 0 && pos.x <= MAX_SIZE && pos.y >= 0 && pos.y <= MAX_SIZE);
}

bool hayUnTesoro(Juego juego, Coordenada pos){
    bool resultado = false;
    for(int i = 0; i < MAX_JUGADORES; i++){
        for(int j = 0; j < juego.jugador[i].cantTesoros; j++){
            if(juego.jugador[i].tesoros[j].posicion.x == pos.x && juego.jugador[i].tesoros[j].posicion.y == pos.y){
                resultado = true;
            }
        }
    }
    return resultado;
}

bool hayUnEspia(Juego juego, Coordenada pos){
    bool resultado = false;
    for(int i = 0; i < MAX_JUGADORES; i++){
        for(int j = 0; j < juego.jugador[i].cantEspias; j++){
            if(juego.jugador[i].espias[j].posicion.x == pos.x && juego.jugador[i].espias[j].posicion.y == pos.y){
                resultado = true;
            }
        }
    }
    return resultado;
}

bool estaInactiva(Juego juego, Coordenada pos){
    bool resultado = false;
    for(int i = 0; i < juego.cantInactivas; i++){
        if(juego.inactivas[i].posicion.x == pos.x && juego.inactivas[i].posicion.y == pos.y){
            resultado = true;
        }
    }
    return resultado;
}

void disminuirTurnoInactivo(Juego* juego){
    for(int i = 0; i < juego->cantInactivas; i++){
        juego->inactivas[i].turnosInactiva--;
        if(juego->inactivas[i].turnosInactiva == 0){
            juego->inactivas[i] = juego->inactivas[juego->cantInactivas - 1];
            juego->cantInactivas--;
        }
    }
}

void eliminarTesoro(Juego* juego, Coordenada pos){
    for(int i = 0; i < MAX_JUGADORES; i++){
        for(int j = 0; j < juego->jugador[i].cantTesoros; j++){
            if(juego->jugador[i].tesoros[j].posicion.x == pos.x && juego->jugador[i].tesoros[j].posicion.y == pos.y){
                juego->jugador[i].tesoros[j] = juego->jugador[i].tesoros[juego->jugador[i].cantTesoros - 1];
                juego->jugador[i].cantTesoros--;
                juego->cantInactivas++;
                juego->inactivas[juego->cantInactivas - 1].posicion = pos;
                juego->inactivas[juego->cantInactivas - 1].turnosInactiva = 5;
            }
        }
    }
}

void eliminarEspia(Juego* juego, Coordenada pos){
    for(int i = 0; i < MAX_JUGADORES; i++){
        for(int j = 0; j < juego->jugador[i].cantEspias; j++){
            if(juego->jugador[i].espias[j].posicion.x == pos.x && juego->jugador[i].espias[j].posicion.y == pos.y){
                juego->jugador[i].espias[j] = juego->jugador[i].espias[juego->jugador[i].cantEspias - 1];
                juego->jugador[i].cantEspias--;
            }
        }
    }
}

void eliminarAmbosEspias(Juego* juego, Coordenada pos){
    for(int i = 0; i < MAX_JUGADORES; i++){
        for(int j = 0; j < juego->jugador[i].cantEspias; j++){
            if(juego->jugador[i].espias[j].posicion.x == pos.x && juego->jugador[i].espias[j].posicion.y == pos.y){
                juego->jugador[i].espias[j] = juego->jugador[i].espias[juego->jugador[i].cantEspias - 1];
                juego->jugador[i].cantEspias--;
            }
        }
    }
}

bool insercionCorrecta(char direccion){
    return (direccion == 'W' ||
            direccion == 'A' || 
            direccion == 'S' || 
            direccion == 'D' || 
            direccion == 'Q' || 
            direccion == 'E' || 
            direccion == 'Z' || 
            direccion == 'C' || 
            direccion == 'X');
}

bool tieneEspiaVivo(Jugador jugador){
   return (jugador.cantEspias > 0);
}

bool limiteDeEspias(Jugador jugador){
    return (jugador.cantEspias == MAX_ESPIAS);
}

void salirDelJuego(){
    cout << "Saliendo del juego..." << endl;
    system("rm j1.txt");
    system("rm j2.txt");
    exit(0);
}

Coordenada obtenerNuevaPosicion(char direccion, Coordenada aux){
    Coordenada pos = aux;
    switch(direccion){
        case 'W':
            pos.x--;
            break;
        case 'A':
            pos.y--;
            break;
        case 'S':
            pos.x++;
            break;
        case 'D':
            pos.y++;
            break;
        case 'Q':
            pos.x--;
            pos.y--;
            break;
        case 'E':
            pos.x--;
            pos.y++;
            break;
        case 'Z':
            pos.x++;
            pos.y--;
            break;
        case 'C':
            pos.x++;
            pos.y--;
            break;
        case 'X':
            salirDelJuego();
            break;
    }
    return pos;
}

void seleccionarEspia(int* seleccion, int cantidad){
    cout << "Ingrese el numero del espia que desea mover" << endl;
    cin >> *seleccion;
    *seleccion -= 1;
    while((*seleccion < 0 || *seleccion > cantidad) && cantidad > 0){
        cout << "Numero de espia invalido, ingrese otro" << endl;
        cin >> *seleccion;
        *seleccion -= 1;
    }
}

void notificarTesoro(int jugadorActual, Coordenada nueva){
    ofstream archivo((jugadorActual == 0)? "j1.txt" : "j2.txt", ios_base::app);
    archivo << endl << endl << "Tesoro encontrado en: (" << nueva.x +1 << ", " << nueva.y +1 << ")" << endl;
    archivo.close();
}

void imprimirMensajeMovimientos(){
    cout << "[W] Arriba           " << "[A] Izquierda      " << "[S] Abajo           " << "[D] Derecha       " << endl;
    cout << "[Q] Arriba-Izquierda " << "[E] Arriba-Derecha " << "[Z] Abajo-Izquierda " << "[C] Abajo-Derecha " << endl;
    cout << "[X] Salir del programa." << endl;
}

void solicitarDireccion(char* direccionAux, Juego* juego, int jugadorActual, int espiaActual){
    Coordenada nueva;
    cout << "Seleccione una dirección: " << endl;
    imprimirMensajeMovimientos();
    cin >> *direccionAux;
    nueva = obtenerNuevaPosicion(*direccionAux, juego->jugador[jugadorActual].espias[espiaActual].posicion);
    while(!estaEnRango(nueva) || estaInactiva(*juego, nueva) || !insercionCorrecta(*direccionAux)){
        cout << "Direccion invalida, ingrese otra" << endl;
        cin >> *direccionAux;
        nueva = obtenerNuevaPosicion(*direccionAux, juego->jugador[jugadorActual].espias[espiaActual].posicion);
        if(hayUnTesoro(*juego, nueva)){
            notificarTesoro(jugadorActual, nueva);
        }
    }
}

void limpiarMapa(char mapa[MAX_SIZE][MAX_SIZE]){
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = 0; j < MAX_SIZE; j++){
            mapa[i][j] = ' ';
        }
    }
}

void llenarMapa(Juego juego, int jugadorActual, char mapa[MAX_SIZE][MAX_SIZE]){
    for(int i = 0; i < juego.jugador[jugadorActual].cantTesoros; i++){
        mapa[juego.jugador[jugadorActual].tesoros[i].posicion.x][juego.jugador[jugadorActual].tesoros[i].posicion.y] = 'T';
    }
    for(int i = 0; i < juego.jugador[jugadorActual].cantEspias; i++){
        mapa[juego.jugador[jugadorActual].espias[i].posicion.x][juego.jugador[jugadorActual].espias[i].posicion.y] = (jugadorActual == 0)? '1' : '2';
    }
    for(int i = 0; i < juego.cantInactivas; i++){
        mapa[juego.inactivas[i].posicion.x][juego.inactivas[i].posicion.y] = 'X';
    }
}

void imprimirMapa(char mapa[MAX_SIZE][MAX_SIZE], int jugadorActual){
    FILE* archivo = fopen((jugadorActual == 0)? "j1.txt" : "j2.txt", "w");
    fprintf(archivo, " ________________________________________\n");
    for(int i = 0; i < MAX_SIZE; i++){
        fprintf(archivo, "%c", '|');
        for(int j = 0; j < MAX_SIZE; j++){
            fprintf(archivo, "%c ", mapa[i][j]);
        }
        fprintf(archivo, "|\n");
    }
    fprintf(archivo, "|________________________________________|\n");
    fclose(archivo);
}

void mostrarMapa(Juego juego, int jugadorActual){
    char mapa[MAX_SIZE][MAX_SIZE];
    limpiarMapa(mapa);
    llenarMapa(juego, jugadorActual, mapa);
    imprimirMapa(mapa, jugadorActual);
    limpiarMapa(mapa);
}

void mostrarEspiasVivos(Jugador jugador, int jugadorActual){
    ofstream archivo((jugadorActual == 0)? "j1.txt" : "j2.txt", ios_base::app);
    archivo << endl << endl << "Espias vivos: " << jugador.cantEspias << endl;
    archivo << "Posiciones: " << endl;
    for(int i = 0; i < jugador.cantEspias; i++){
        archivo << i +1 << " -> (" << jugador.espias[i].posicion.x +1 << ", " << jugador.espias[i].posicion.y +1 << ") " << endl;
    }
    archivo << endl;
    archivo.close();
}

void moverEspia(Juego* juego, int espiaActual, char direccion, int jugadorActual){
    Coordenada nueva = obtenerNuevaPosicion(direccion, juego->jugador[jugadorActual].espias[espiaActual].posicion);
    if(hayUnTesoro(*juego, nueva)){
        notificarTesoro(jugadorActual, nueva);
        eliminarTesoro(juego, nueva);
    }
    if(hayUnEspia(*juego, nueva)){
        eliminarAmbosEspias(juego, nueva);
    }
    juego->jugador[jugadorActual].espias[espiaActual].posicion = nueva;
    disminuirTurnoInactivo(juego);
}

void jugar(Juego* juego){
    int seleccionAux;
    char direccionAux;
    while(jugadorGanador(*juego) == -1){
        for(int i = 0; i < MAX_JUGADORES; i ++){
            system("clear");
            mostrarMapa(*juego, i);
            mostrarEspiasVivos(juego->jugador[i], i);
            if(tieneEspiaVivo(juego->jugador[i])){
                cout << "Jugador " << i + 1 << endl;
                seleccionarEspia(&seleccionAux, juego->jugador[i].cantEspias);
                solicitarDireccion(&direccionAux, juego, i, seleccionAux);
                moverEspia(juego, seleccionAux, direccionAux, i);                
            }
            if(!limiteDeEspias(juego->jugador[i])){
                generarFicha(juego->jugador, i, ESPIA);
            }
        }
    }
}

void mensajeGanador(Juego juego){
    int ganador = jugadorGanador(juego);
    system("clear");
    cout << endl << endl << endl << "HA GANADO EL JUGADOR " << ganador + 1 << endl << endl << endl;
}

int main(){
    Juego juego;
    iniciarJuego(&juego);
    jugar(&juego);
    mensajeGanador(juego);
    salirDelJuego();
    return 0;
}