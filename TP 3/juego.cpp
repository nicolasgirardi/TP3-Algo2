#include "juego.h"

Juego::Juego() {
    cantidadPersonajesUno = 0;
    cantidadPersonajesDos = 0;
    mapaPartida.mapear("mapa.csv");//crea el tablero
    cargarPersonajes();
    inicializarCostos();
}

void Juego::inicializarCostos(){
    this->costos[0] = new Costos("agua", &this->mapaPartida);
    this->costos[1] = new Costos("fuego", &this->mapaPartida);
    this->costos[2] = new Costos("tierra", &this->mapaPartida);
    this->costos[3] = new Costos("aire", &this->mapaPartida);
}

void Juego::borrarCostos(){
    for (int i = 0; i < 4; ++i) {
        delete this->costos[i];
    }
}




void Juego::cargarPersonajes() {
  string elemento, nombre;
  int escudo, vida, fila, columna;
  archivoPersonajes.asignarPath("personajes.csv");
  if(archivoPersonajes.procesarArchivo()){
    while (!archivoPersonajes.finArchivo()) {
        archivoPersonajes.descomponerLineaBasica(&elemento, &nombre, &escudo, &vida);
        menuPartida.crearPersonaje(elemento, nombre, escudo, vida);
    }
  }
}


bool Juego::filaValida(int fila){
    return (fila >= MINIMO_TABLERO && fila <= MAXIMO_TABLERO);
}

bool Juego::columnaValida(int columna){
    return (columna >= MINIMO_TABLERO && columna <= MAXIMO_TABLERO);
}

void Juego::pedirFila(int* fila){
    cout << "Ingrese fila: ";
    cin >> *fila;
    while (!filaValida(*fila)){
        cout << "Fila ingresada en el rango incorrecto, debe ingresar una fila entre 1 y 8: ";
        cin >> *fila;
    }
}

void Juego::pedirColumna(int* columna){
    cout << "Ingrese columna: ";
    cin >> *columna;
    while (!columnaValida(*columna)){
        cout << "Columna ingresada en el rango incorrecto, debe ingresar una columna entre 1 y 8: ";
        cin >> *columna;
    }
}

void Juego::consultarCoordenada(Coordenada* coor, Personaje* personajes[MAX_PERSONAJES], int i){
    int fila, columna;
    bool puedoConsultar =  true;
    while (puedoConsultar){
        cout << "Indique las coordenadas donde desea posicionar a "<< personajes[i]->obtenerNombre() << ":" << endl << endl;
        pedirFila(&fila);
        pedirColumna(&columna);
        coor->cambiarFilaYColumna(fila,columna);
        if(mapaPartida.ocupado(*coor)) {
            cout << "El lugar elegido se encuentra ocupado, vuelva a elegir uno." << endl << endl;
        } else {
            puedoConsultar = false;
        }
    }
}



void Juego::posicionarPersonaje(Personaje* personajes[MAX_PERSONAJES], int i){
    Coordenada* coor = new Coordenada(0,0);
    //MUESTRO EL MAPA POR PANTALLA
    consultarCoordenada(coor,personajes,i);
    personajes[i]->asignarCoordenada(coor->obtenerFila(),coor->obtenerColumna());
    mapaPartida.consulta(*coor)->obtenerDato()->ocupar(personajes[i]);
    i++;
    delete coor;
}


void Juego::procesarUbicacion(bool empiezaUno) {
    int i = 0;
    if (empiezaUno)
        while ((i < MAX_PERSONAJES)) { //acá tengo en cuenta que ambos jugadores tienen exactamente 3 personajes elegidos
            posicionarPersonaje(personajesJugadorUno, i);
            posicionarPersonaje(personajesJugadorDos, i);
            i++;
        }
    else
        while ((i < MAX_PERSONAJES)) { //acá tengo en cuenta que ambos jugadores tienen exactamente 3 personajes elegidos
            posicionarPersonaje(personajesJugadorDos, i);
            posicionarPersonaje(personajesJugadorUno, i);
            i++;
        }
}

void Juego::ubicarPersonajes() {
    bool empiezaUno;
    elegirPrimerLugar(&empiezaUno);
    if (empiezaUno) {
        imprimirMensajeUno();
        procesarUbicacion(empiezaUno);
    } else {
        imprimirMensajeDos();
        procesarUbicacion(empiezaUno);
    }
}

void Juego::elegirPersonajes() {
    int i;
    int topeUno = 0;
    int topeDos = 0;

    menuPartida.procesarMenuJuego(personajesJugadorUno, &topeUno, personajesJugadorDos, &topeDos);

    if (stoi(menuPartida.obtenerOpcion()) == OPCION_SELECCIONAR){

        cantidadPersonajesUno = topeUno;
        cantidadPersonajesDos = topeDos;

        cout << "Personajes Jugador 1:" << endl << endl;
        for(i = 0; i < MAX_PERSONAJES; i++){
            cout << i+1 << ". "<< personajesJugadorUno[i]->obtenerNombre() << endl;
        }
        cout << endl << endl;
        cout << "Personajes Jugador 2:" << endl << endl;
        for(i = 0; i < MAX_PERSONAJES; i++){
            cout << i+1 << ". "<< personajesJugadorDos[i]->obtenerNombre() << endl;
        }
        cout << endl << endl;

        ubicarPersonajes();
    }
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
void Juego::jugarTurno(Personaje* personajes[MAX_PERSONAJES], int topeUno, int* i, Personaje* enemigos[MAX_PERSONAJES]) {
    if ((*i) >= (topeUno)) {
        (*i) = 0;
    }
    if (personajes[*i]->obtenerVida() != 0) {
        return menuPartida.procesarTurno(&mapaPartida,personajes[*i], this->costos, personajes, enemigos);
    }
    (*i)++;
    return jugarTurno(personajes, topeUno, i, enemigos);
}

bool Juego::opcionValida(char opcion) {
    return (opcion == SI|| opcion == NO);
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
    if (opcion == SI) {
        archivoPartida.asignarPath("partida.csv");
        archivoPartida.escribirArchivo(personajesJugadorUno, cantidadPersonajesUno, personajesJugadorDos, cantidadPersonajesDos);
    }
}

void Juego::consultarGuardado(bool* guardo) {
    char opcion;
    pedirGuardado(&opcion);
    procesarGuardado(opcion, guardo);
}

string Juego::mensajeRandom() {
    int i;
    string mensaje = "";
    return mensaje;
}
void Juego::procesarTurnos(Personaje* personajesPrimero[MAX_PERSONAJES], int topeUno, Personaje* personajesSegundo[MAX_PERSONAJES], int topeDos) {
    int i = 0, j = 0;
    bool guardo = false;
    while (!consultaEliminado() && !guardo) {
        cout << "Jugador uno " << mensajeRandom() << endl << endl;
        jugarTurno(personajesPrimero, topeUno, &i, personajesSegundo);
        cout << "Jugador dos" << mensajeRandom() << endl << endl;
        jugarTurno(personajesSegundo, topeDos, &j, personajesPrimero);
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
    char estado;
    menuPartida.procesarMenuPrincipal(&estado);
    estadoJuego = estado;
    if (estadoJuego == JUGANDO) {
        revisarPartida();
        if (stoi(menuPartida.obtenerOpcion()) == OPCION_SELECCIONAR)
        {
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
    }
    if (stoi(menuPartida.obtenerOpcion()) == SALIDA_JUEGO){
        estadoJuego = FINALIZADO;
    }
    if (estadoJuego == FINALIZADO) {
        archivoPartida.eliminarArchivo();
    }
}

Juego::~Juego(){

}
