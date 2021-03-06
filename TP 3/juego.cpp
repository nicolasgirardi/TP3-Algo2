#include "juego.h"

Juego::Juego() {
    cantidadPersonajesUno = 0;
    cantidadPersonajesDos = 0;
    mapaPartida.mapear("mapa.csv");//crea el tablero
    cargarPersonajes();
    inicializarCostos();
    this->partidaCargada = false;
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
    if (archivoPersonajes.procesarArchivo()) {
        while (!archivoPersonajes.finArchivo()) {
            archivoPersonajes.descomponerLineaBasica(&elemento, &nombre, &escudo, &vida);
            menuPrincipal.crearPersonaje(elemento, nombre, escudo, vida, &diccionarioPersonajes);
        }
    }
}


void Juego::consultarCoordenada(Coordenada* coor, Personaje* personajes[MAX_PERSONAJES], int i){
    bool puedoConsultar =  true;
    while (puedoConsultar){
        cout << "Indique las coordenadas donde desea posicionar a "<< personajes[i]->obtenerNombre() << ":" << endl << endl;
        coor->pedirCoordenada();
        if(mapaPartida.ocupado(*coor)) {
            cout << "El lugar elegido se encuentra ocupado, vuelva a elegir uno." << endl << endl;
        } else {
            puedoConsultar = false;
        }
    }
}



void Juego::posicionarPersonaje(Personaje* aliados[MAX_PERSONAJES], Personaje* enemigos[MAX_PERSONAJES],  int i){
    Coordenada* coor = new Coordenada(0,0);
    mapaPartida.mostrarMapa(aliados[i],aliados,enemigos);
    consultarCoordenada(coor,aliados,i);
    aliados[i]->asignarCoordenada(coor->obtenerFila(),coor->obtenerColumna());
    mapaPartida.consulta(*coor)->obtenerDato()->ocupar(aliados[i]);
    delete coor;
}


void Juego::procesarUbicacion(bool empiezaUno) {
    int i = 0;
    if (empiezaUno)
        while ((i < MAX_PERSONAJES)) { //acá tengo en cuenta que ambos jugadores tienen exactamente 3 personajes elegidos
            posicionarPersonaje(personajesJugadorUno,personajesJugadorDos,i);
            posicionarPersonaje(personajesJugadorDos,personajesJugadorUno,i);
            i++;
        }
    else
        while ((i < MAX_PERSONAJES)) { //acá tengo en cuenta que ambos jugadores tienen exactamente 3 personajes elegidos
            posicionarPersonaje(personajesJugadorDos,personajesJugadorUno,i);
            posicionarPersonaje(personajesJugadorUno,personajesJugadorDos,i);
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
    Personaje* personajesUno[MAX_PERSONAJES];
    Personaje* personajesDos[MAX_PERSONAJES];

    menuJuego.procesarMenuJuego(personajesUno, &topeUno, personajesDos, &topeDos, &diccionarioPersonajes);

    for (i = 0; i < MAX_PERSONAJES; i++) {
        personajesJugadorUno[i] = personajesUno[i];
        personajesJugadorDos[i] = personajesDos[i];
    }

    if (stoi(menuJuego.obtenerOpcion()) == OPCION_SELECCIONAR){
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
    int muertos = 0;
    for (int i = 0; i < tope; i++) {
        if (personajes[i]->obtenerVida() <= 0){
            muertos++;
            mapaPartida.consulta(*personajes[i]->obtenerCoordenada())->obtenerDato()->vaciar();
            personajes[i]->asignarCoordenada(0,0);
        }
    }
    return muertos;
}

bool Juego::consultaEliminado() {
    if (contarMuertos(personajesJugadorUno, cantidadPersonajesUno) == cantidadPersonajesUno) {
        cout << "FELICITACIONES AL JUGADOR 2!!!! GANASTE EL JUEGO" << endl;
        cout << endl;
        cout << "El jugador 1 perdio" << endl;
        return true;
    } else if (contarMuertos(personajesJugadorDos, cantidadPersonajesDos) == cantidadPersonajesDos) {
        cout << "FELICITACIONES AL JUGADOR 1!!!! GANASTE EL JUEGO" << endl;
        cout << endl;
        cout << "El jugador 2 perdio" << endl;
        return true;
    } else {
        return false;
    }
}

void Juego::asignarEstadoJuego(char estado){
    estadoJuego = estado;
}

void Juego::recuperarAire(Personaje* personaje){

    if(personaje->obtenerElemento() == "aire"){
        personaje->recuperarEnergia();
    }

}


void Juego::ejecutarTurno(Personaje* personaje, Personaje* enemigos[MAX_PERSONAJES],  Personaje* aliados[MAX_PERSONAJES]) {
    personaje->reseteoDefensa();
    recuperarAire(personaje);
    cout << "Le toca jugar a " << personaje->obtenerNombre() << endl << endl;

    mapaPartida.mostrarMapa(personaje, aliados, enemigos);
    cout << "Estos son sus detalles:" << endl << endl;
    personaje->consultaDatos();

    submenuUno.mostrarMenu();
    submenuUno.elegirOpcion();
    if (stoi(submenuUno.obtenerOpcion()) != PASAR) {
        submenuUno.ejecutarOpcion(&mapaPartida, personaje, costos);
    }
    submenuDos.mostrarMenu();
    submenuDos.elegirOpcion();
    if (stoi(submenuDos.obtenerOpcion()) != PASAR) {
        submenuDos.ejecutarOpcion(personaje, enemigos, aliados);
        if((personaje->obtenerElemento() == "aire") && (stoi(submenuDos.obtenerOpcion()) == OPCION_DEFENDER))
            submenuDos.moverGratis(&mapaPartida,personaje);
    }
}

// si entra acá es porque hay alguno con vida
void Juego::jugarTurno(Personaje* personajes[MAX_PERSONAJES], int topeUno, int* i, Personaje* enemigos[MAX_PERSONAJES]) {
    if (*i < topeUno) {
        if (personajes[*i]->obtenerVida() > 0)
            ejecutarTurno(personajes[*i], enemigos, personajes);
        *i = *i + 1;
        jugarTurno(personajes, topeUno, i, enemigos);
    }
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

void Juego::reseteoDefensas(){
    for(int i = 0; i < cantidadPersonajesUno; i++){
        personajesJugadorUno[i]->reseteoDefensa();
    }
    for(int i = 0; i < cantidadPersonajesDos; i++){
        personajesJugadorDos[i]->reseteoDefensa();
    }
}

void Juego::procesarGuardado(char opcion, bool* guardo) {
    if (opcion == SI) {
        reseteoDefensas();
        archivoPartida.asignarPath("partida.csv");
        archivoPartida.escribirArchivo(personajesJugadorUno, cantidadPersonajesUno, personajesJugadorDos, cantidadPersonajesDos);
        *guardo = true;
    }
}

void Juego::consultarGuardado(bool* guardo) {
    char opcion;
    pedirGuardado(&opcion);
    procesarGuardado(opcion, guardo);
}

string Juego::mensajeRandom() {
    int i;
    string mensaje;
    i = rand() % 24;
    switch(i){
        case(0):
            mensaje = "yo se que vos podes";
            break;
        case(1):
            mensaje = "no le digas al otro, pero yo apuesto por vos";
            break;
        case(3):
            mensaje = "que tengas un buen turno";
            break;
        case(4):
            mensaje = "mi jugador favorito!";
            break;
        case(5):
            mensaje = "esta fresco afuera, no?";
            break;
        case(6):
            mensaje = "tu puedes carlitos, tu puedes";
            break;
        case(7):
            mensaje = "haz tu jugada, estoy segura de que perderas";
            break;
        case(8):
            mensaje = "hacé lo que quieras";
            break;
        case(9):
            mensaje = "tic tac, el tiempo corre";
            break;
        case(10):
            mensaje = "my family asked me to stop singing wonderwall. I said maybe";
            break;
        case(11):
            mensaje = "today is gonna be the day that they're gonna throw it back to you";
            break;
        case(12):
            mensaje = "bonjour";
            break;
        case(13):
            mensaje = "pro tip: ante la duda, ataca";
            break;
        case(14):
            mensaje = "te prometo que vamos a nerfear a marta";
            break;
        case(15):
            mensaje = "julia necesita alto buff";
            break;
        case(16):
            mensaje = "no es un bug, es un feature";
            break;
        case(17):
            mensaje = "Heed my battle cry";
            break;
        case(18):
            mensaje = "black clouds fill the sky";
            break;
        case(19):
            mensaje = "thunder will bring forth";
            break;
        case(20):
            mensaje = "tenes un momento para hablar de bitcoin?";
            break;
        case(21):
            mensaje = "pro tip: licua tus activos, inverti en andycoins";
            break;
        case(22):
            mensaje = "no existe el nivel de las vacas";
            break;
        case(23):
            mensaje = "all your base are belong to us";
            break;
        default:
            mensaje = "los mejores graficos estan en tu imaginacion";
            break;
    }
    return mensaje;
}

void Juego::procesarTurnos(Personaje* personajesPrimero[MAX_PERSONAJES], int topeUno, Personaje* personajesSegundo[MAX_PERSONAJES], int topeDos) {
    int i = 0, j = 0;
    bool guardado = false;
    while (!consultaEliminado() && !guardado) {
        menuPrincipal.borrarPantalla();
        cout << "Jugador uno. " << endl;
        cout << mensajeRandom() << endl << endl;
        jugarTurno(personajesPrimero, topeUno, &i, personajesSegundo);
        cout << endl;
        cout << "Jugador dos." << endl;
        cout << mensajeRandom() << endl << endl;
        jugarTurno(personajesSegundo, topeDos, &j, personajesPrimero);
        if (!consultaEliminado()) {
            consultarGuardado(&guardado);
        }
        i = 0;
        j= 0;
    }
    if (guardado) {
        asignarEstadoJuego(GUARDADO);
    } else {
        asignarEstadoJuego(FINALIZADO);
    }
}

void Juego::asignarPersonaje(Personaje* personajes[MAX_PERSONAJES], int* tope, Personaje* personajeNuevo) {
    personajes[*tope] = personajeNuevo;
    (*tope)++;
}

Personaje* Juego::crearPersonajeNuevo(string elemento, string nombre, int escudo, int vida) {
    Personaje* personajeCreado;
    if (elemento == "tierra") {
        personajeCreado = new Tierra(nombre, escudo, vida);
    } else if (elemento == "agua") {
        personajeCreado = new Agua(nombre, escudo, vida);
    } else if (elemento == "aire") {
        personajeCreado = new Aire(nombre, escudo, vida);
    } else if (elemento == "fuego") {
        personajeCreado = new Fuego(nombre, escudo, vida);
    }
    return personajeCreado;
}

// acá tengo que actualizar la info de los vectoresjugador y de la info de los
// personajes (no crearlos)
void Juego::cargarPartida() {
    string elemento, nombre;
    int escudo, vida, energia, fila, columna, cant_leidos = 0;
    while (!archivoPartida.finArchivo()) {
        archivoPartida.descomponerLineaPartida (&elemento, &nombre, &escudo, &vida, &energia, &fila, &columna);
        Personaje* personajeLeido = crearPersonajeNuevo(elemento, nombre, escudo, vida);
        personajeLeido->asignarEnergia(energia);
        personajeLeido->asignarCoordenada(fila,columna);
        if (personajeLeido->obtenerVida() > 0) {
            this->mapaPartida.consulta(*personajeLeido->obtenerCoordenada())->obtenerDato()->ocupar(personajeLeido);
        }
        if (cant_leidos < MAX_PERSONAJES) {
            asignarPersonaje(personajesJugadorUno, &cantidadPersonajesUno, personajeLeido);
        } else {
            asignarPersonaje(personajesJugadorDos, &cantidadPersonajesDos, personajeLeido);
        }
       cant_leidos++;
    }
}

void Juego::revisarPartida() {
    archivoPartida.asignarPath("partida.csv");
    if (archivoPartida.procesarArchivo()) {
        cargarPartida();
        this->partidaCargada = true;
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
    menuPrincipal.procesarMenuPrincipal(&estado,&diccionarioPersonajes);
    this->estadoJuego = estado;
    if (this->estadoJuego == JUGANDO) {
        revisarPartida();
        if ((stoi(menuJuego.obtenerOpcion()) == OPCION_SELECCIONAR) || (stoi(menuPrincipal.obtenerOpcion()) == OPCION_JUGAR))
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
    if (stoi(menuJuego.obtenerOpcion()) == SALIDA_JUEGO){
        estadoJuego = FINALIZADO;
    }
    if (estadoJuego == FINALIZADO) {
        archivoPartida.eliminarArchivo();
    }
}

Juego::~Juego(){
    for(int i = 0; i < 4; i++){
        delete costos[i];
    }
    if (partidaCargada) {
        for (int i = 0; i < MAX_PERSONAJES; i++) {
            delete personajesJugadorUno[i];
            delete personajesJugadorDos[i];
        }
    }
}
