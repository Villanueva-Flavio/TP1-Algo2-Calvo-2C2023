Tesoro Binario V1.0
Resumen
Enunciado:

    Jugadores: 2
    Objetivos (Tesoros): 4
    Tamaño del mapa: 20 x 20
    Espías por jugador: 1

    Orden Inicial
        Se suelta 1 espía en el mapa
        Se sueltan 4 tesoros por jugador en el mapa

    Orden Loop
        Si hay tesoro lo recupera (demora 5 turnos y está inactiva en el proceso)
        El jugador mueve uno de sus tesoros en Horiz, Vert, Diag.
        (Si Tesoro choca con tesoro, deja un aviso)
        (Si casilla inactiva no se puede mover el tesoro)
        Se coloca un espía
        (Si el jugador pone un espia donde hay otro se eliminan ambos)
        Gana el que le sigue quedando tesoros

" " - Vacio
"X" - Inactivo
"1" - J1
"2" - J2

Por cada turno: se exporta estado del tablero en un texto (para j1 y j2)