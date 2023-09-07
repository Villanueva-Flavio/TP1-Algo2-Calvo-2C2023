#include "juego.h"

int main(){
    Juego* TesoroBinario = new Juego();
    TesoroBinario->iniciarJuego();
    delete TesoroBinario;
    return 0;
}