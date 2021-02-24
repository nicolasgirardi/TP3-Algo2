#include "juego.h"

Juego::Juego() {
    cantidadPersonajesUno = 0;
    cantidadPersonajesDos = 0;
    mapaPartida.mapear("mapa.csv"); //crea el tablero
}

void Juego::definirPreliminares(Mapa* mapa) {
    menuPartida.procesarArchivo();
    menuPartida.procesarMenuPrincipal(
            estadoJuego);  // esto está bien o debo usar el método asignarEstado?
}


bool Juego::filaValida(int fila){
    return (fila >= MINIMO_TABLERO && fila <= MAXIMO_TABLERO);
}

bool Juego::columnaValida(int columna){
    return (columna >= MINIMO_TABLERO && columna <= MAXIMO_TABLERO);
}

void Juego::pedirFila(int* fila){
    cout << "Ingrese fila: ";
    cin >> fila;
    while (!filaValida(*fila)){
        cout << "Fila ingresada en el rango incorrecto, debe ingresar una fila entre 1 y 8: ";
        cin >> fila;
    }
}

void Juego::pedirColumna(int* columna){
    cout << "Ingrese columna: ";
    cin >> columna;
    while (!columnaValida(*columna)){
        cout << "Columna ingresada en el rango incorrecto, debe ingresar una columna entre 1 y 8: ";
        cin >> columna;
    }
}

void Juego::consultarCoordenada(Coordenada* coor, Personaje* personajes[MAX_PERSONAJES], int* i){
    int fila, columna;
    bool puedoConsultar =  true;
    while (puedoConsultar){
        cout << "Indique las coordenadas donde desea posicionar a "<< personajes[*i]->obtenerNombre() << ":" << endl;
        pedirFila(&fila);
        pedirColumna(&columna);
        coor->cambiarFilaYColumna(fila,columna);
        if(mapaPartida->ocupado(coor)) {
            cout << "El lugar elegido se encuentra ocupado, vuelva a elegir uno.";
        } else {
            puedoConsultar = false;
        }
    }
}



void Juego::posicionarPersonaje(Personaje* personajes[MAX_PERSONAJES], int* i){
    Coordenada* coor = new Coordenada(0,0);
    //MUESTRO EL MAPA POR PANTALLA
    consultarCoordenada(coor,personajes,i);
    personajes[*i]->asignarCoordenada(coor->obtenerFila(),coor->obtenerColumna());
    mapaPartida->consulta(*coor)->obtenerDato()->ocupar(personajes[*i]);
    (*i)++;
    delete coor;
}


void Juego::procesarUbicacion(Personaje* personajesPrimero[MAX_PERSONAJES], int topeUno, Personaje* personajesSegundo[MAX_PERSONAJES], int topeDos) {
    int i = 0, j = 0;
    while ( (i < topeUno) && (j < topeDos)) { //acá tengo en cuenta que ambos jugadores tienen exactamente 3 personajes elegidos
        posicionarPersonaje(personajesPrimero,&i);
        posicionarPersonaje(personajesSegundo,&j);
    }
}

void Juego::ubicarPersonajes() {
    bool empiezaUno;
    elegirPrimerLugar(&empiezaUno);
    if (empiezaUno) {
        imprimirMensajeUno();
        procesarUbicacion(personajesJugadorUno, cantidadPersonajesUno, personajesJugadorDos, cantidadPersonajesDos);
    } else {
        imprimirMensajeDos();
        procesarUbicacion(personajesJugadorDos, cantidadPersonajesDos, personajesJugadorUno, cantidadPersonajesUno);
    }
}

void Juego::elegirPersonajes() {
    menuPartida.procesarMenuJuego(personajesJugadorUno, &cantidadPersonajesUno, personajesJugadorDos, &cantidadPersonajesDos);
    ubicarPersonajes();
}

void Juego::elegirPrimerLugar(bool* empiezaUno) { (*empiezaUno) = rand() % 2; }

Mapa Juego::obtenerMapa() { return mapaPartida; }

int Juego::contarMuertos(Personaje* personajes[MAX_PERSONAJES], int tope) {
    int muertos;
    for (int i = 0; i < tope; i++) {
        if (personajes[i]->obtenerVida() == 0) muertos++;
    }
    return muertos;
}

bool Juego::consultaEliminado() {
    if (contarMuertos(personajesJugadorUno, cantidadPersonajesUno) == cantidadPersonajesUno) {
        return true;
    } else if (contarMuertos(personajesJugadorDos, cantidadPersonajesDos) == cantidadPersonajesDos) {
        return true;
    } else {
        return false;
    }
}

void Juego::asignarEstadoJuego(char estado){
    estadoJuego = estado;
}

// si entra acá es porque hay alguno con vida
void Juego::jugarTurno(Personaje* personajes[MAX_PERSONAJES], int topeUno, int* i) {
    if ((*i) >= (topeUno)) {
        (*i) = 0;
    }
    if (personajes[*i]->obtenerVida() != 0) {
        return menuPartida.procesarTurno(personajes[*i]);  //(Mapa* mapa, Personaje* personaje, Costos* costos)
    }
    (*i)++;
    return jugarTurno(personajes, topeUno, i);
}

bool Juego::opcionValida(char opcion) {
    return (opcion == AFIRMATIVO || opcion == NEGATIVO);
}

void Juego::pedirGuardado(char* opcion) {
    cout << "Desea guardar el progreso de la partida y salir del juego? S para Sí, N para no" << endl;
    cin >> opcion;
    while (!opcionValida(*opcion)) {
        cout << "Ingresó un caracter incorrecto. Vuelva a ingresar" << endl;
        cin >> opcion;
    }
}

void Juego::procesarGuardado(char opcion, bool* guardo) {
    if (opcion == AFIRMATIVO) {
        archivoPartida.asignarPath("partida.csv");
        archivoPartida.escribirArchivo(personajesJugadorUno, cantidadPersonajesUno, personajesJugadorDos, cantidadPersonajesDos);
    }
}

void Juego::consultarGuardado(bool* guardo) {
    char opcion;
    pedirGuardado(&opcion);
    procesarGuardado(opcion, guardo);
}

void Juego::procesarTurnos(Personaje* personajesPrimero[MAX_PERSONAJES], int topeUno, Personaje* personajesSegundo[MAX_PERSONAJES], int topeDos) {
    int i = 0, j = 0;
    bool guardo = false;
    while (!consultaEliminado() && !guardo) {
        jugarTurno(personajesPrimero, topeUno, &i);
        jugarTurno(personajesSegundo, topeDos, &j);
        if (!consultaEliminado()) {
            consultarGuardado(&guardo);
        }
    }
    if (guardo) {
        asignarEstadoJuego(GUARDADO);
    } else {
        asignarEstadoJuego(FINALIZADO);
    }
}

void Juego::asignarPersonaje(Personaje* personajes[MAX_PERSONAJES], int* tope, Personaje* personajeNuevo) {
    personajes[*tope] = personajeNuevo;
    (*tope)++;
}

// acá tengo que actualizar la info de los vectoresjugador y de la info de los
// personajes (no crearlos)
void Juego::cargarPartida() {
    string elemento, nombre;
    int escudo, vida, energia, fila, columna, cant_leidos;
    while (!archivoPartida.finArchivo()) {
        archivoPartida.descomponerLineaPartida (&elemento, &nombre, &escudo, &vida, &energia, &fila, &columna);
        menuPartida.obtenerDiccionario().modificarContenido(nombre, escudo, vida, energia, fila, columna);
        Personaje* personajeLeido = menuPartida.obtenerDiccionario().consultaNodo(nombre);
        if (cant_leidos < MAX_PERSONAJES) {
            asignarPersonaje(personajesJugadorUno, &cantidadPersonajesUno, personajeLeido);
        } else {
            asignarPersonaje(personajesJugadorDos, &cantidadPersonajesDos, personajeLeido);
        }
    }
}

void Juego::revisarPartida() {
    archivoPartida.asignarPath("partida.csv");
    if (archivoPartida.procesarArchivo()) {
        cargarPartida();
    } else {
        elegirPersonajes();
    }
}

void Juego::imprimirMensajeUno(){
    cout << "Comenzará el jugador Uno y se irán turnando hasta finalizar." << endl;
}

void Juego::imprimirMensajeDos(){
    cout << "Comenzará el jugador Dos y se irán turnando hasta finalizar." << endl;
}

void Juego::procesarJuego() {
    definirPreliminares();
    if (estadoJuego == JUGANDO) {
        revisarPartida();
        bool empiezaUno;
        elegirPrimerLugar(&empiezaUno);
        if (empiezaUno) {
            imprimirMensajeUno();
            procesarTurnos(personajesJugadorUno, cantidadPersonajesUno, personajesJugadorDos, cantidadPersonajesDos);
        } else {
            imprimirMensajeDos();
            procesarTurnos(personajesJugadorDos, cantidadPersonajesDos, personajesJugadorUno, cantidadPersonajesUno);
        }
    }
    if (estadoJuego == FINALIZADO) {
        archivoPartida.eliminarArchivo();
    }
}
