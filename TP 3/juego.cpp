#include "juego.h"

Juego::Juego() {
  cantidadPersonajesUno = 0;
  cantidadPersonajesDos = 0;
  // mapaPartida. (crear tablero)
}

void Juego::definirPreliminares(Mapa* mapa) {
  menuPartida.procesarArchivo();
  menuPartida.procesarMenuPrincipal(
      estadoJuego);  // esto está bien o debo usar el método asignarEstado?
}

void Juego::coorValidas(Coordenada* coor,){
	int fila,columna;
	bool valida = false;
	while(!valida)
	cout<<"Ingrese fila: ";
	cin>>fila;
	cout<<"Ingrese columna: ";
	cin>>columna;
	while(fila < 1 || fila > 8){
		cout<<"valor incorrecto, debe ingresar una fila entre 1 y 8: ";
		cin>>*fila;
	}
	while(columna < 1 || columna > 8){
		cout<<"valor incorrecto, debe ingresar una columna entre 1 y 8: ";
		cin>>*columna;
	for	
	}
		
}
void Juego::ubicarPersonajes() {
  // IMprimir tablero
  int i;
  Coordenada* coor = new Coordenada(0,0);
  
  bool* empiezaUno;
  if(empiezaUno){
      for (int i = 0; i < MAX_PERSONAJES; ++i) {          
	  cout << "Jugador 1, indique las coordenadas donde desea posicionar a "<<personajesJugadorUno[i]->obtenerNombre() <<":" << endl; 
	  coorValidas(coor,i);
	  personajesJugadorUno[i]->asignarCoordenada(coor->obtenerFila(),coor->obtenerColumna());
	  mapaPartida->consulta(*coor)->obtenerDato()->ocupar(personajesJugadorUno[i]);

      cout << "Jugador 2, indique en que fila desea posicionar a " <<personajesJugadorDos[i]->obtenerNombre() <<":" << endl;
	  coorValidas(coor);
	  personajesJugadorDos[i]->asignarCoordenada(fila,columna);
      }
  }
  else{
 	  cout << "Jugador 2, indique en que fila desea posicionar a " <<personajesJugadorDos[i]->obtenerNombre() <<":" << endl;
	  coorValidas(&fila,&columna);
	  personajesJugadorDos[i]->asignarCoordenada(fila,columna);	
	  
	  cout << "Jugador 1, indique las coordenadas donde desea posicionar a "<<personajesJugadorUno[i]->obtenerNombre() <<":" << endl; 
	  coorValidas(&fila,&columna);
	  personajesJugadorUno[i]->asignarCoordenada(fila,columna);
  }
   
}

void Juego::elegirPersonajes() {
  menuPartida.procesarMenuJuego(personajesJugadorUno, &cantidadPersonajesUno,
                                personajesJugadorDos, &cantidadPersonajesDos);
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
  if (contarMuertos(personajesJugadorUno, cantidadPersonajesUno) ==
      cantidadPersonajesUno) {
    return true;
  } else if (contarMuertos(personajesJugadorDos, cantidadPersonajesDos) ==
             cantidadPersonajesDos) {
    return true;
  } else {
    return false;
  }
}

void Juego::asignarEstadoJuego(char estado) { estadoJuego = estado; }

// si entra acá es porque hay alguno con vida
void Juego::jugarTurno(Personaje* personajes[MAX_PERSONAJES], int topeUno,
                       int* i) {
  if ((*i) >= (topeUno)) {
    (*i) = 0;
  }
  if (personajes[*i]->obtenerVida() != 0) {
    return menuPartida.procesarTurno(
        personajes[*i]);  //(Mapa* mapa, Personaje* personaje, Costos* costos)
  }
  (*i)++;
  return jugarTurno(personajes, topeUno, i);
}

bool Juego::opcionValida(char opcion) {
  return (opcion == AFIRMATIVO || opcion == NEGATIVO);
}

void Juego::pedirGuardado(char* opcion) {
  cout << "Desea guardar el progreso de la partida y salir del juego? S para "
          "Sí, N para no"
       << endl;
  cin >> opcion;
  while (!opcionValida(*opcion)) {
    cout << "Ingresó un caracter incorrecto. Vuelva a ingresar" << endl;
    cin >> opcion;
  }
}

void Juego::procesarGuardado(char opcion, bool* guardo) {
  if (opcion == AFIRMATIVO) {
    archivoPartida.asignarPath("partida.csv");
    archivoPartida.escribirArchivo(personajesJugadorUno, cantidadPersonajesUno,
                                   personajesJugadorDos, cantidadPersonajesDos);
  }
}

void Juego::consultarGuardado(bool* guardo) {
  char opcion;
  pedirGuardado(&opcion);
  procesarGuardado(opcion, guardo);
}

void Juego::procesarTurnos(Personaje* personajesPrimero[MAX_PERSONAJES],
                           int topeUno,
                           Personaje* personajesSegundo[MAX_PERSONAJES],
                           int topeDos) {
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

void Juego::asignarPersonaje(Personaje* personajes[MAX_PERSONAJES], int* tope,
                             Personaje* personajeNuevo) {
  personajes[*tope] = personajeNuevo;
  (*tope)++;
}

// acá tengo que actualizar la info de los vectoresjugador y de la info de los
// personajes (no crearlos)
void Juego::cargarPartida() {
  string elemento, nombre;
  int escudo, vida, energia, fila, columna, cant_leidos;
  while (!archivoPartida.finArchivo()) {
    archivoPartida.descomponerLineaPartida(&elemento, &nombre, &escudo, &vida,
                                           &energia, &fila, &columna);
    menuPartida.obtenerDiccionario().modificarContenido(nombre, escudo, vida,
                                                        energia, fila, columna);
    Personaje* personajeLeido =
        menuPartida.obtenerDiccionario().consultaNodo(nombre);
    if (cant_leidos < MAX_PERSONAJES) {
      asignarPersonaje(personajesJugadorUno, &cantidadPersonajesUno,
                       personajeLeido);
    } else {
      asignarPersonaje(personajesJugadorDos, &cantidadPersonajesDos,
                       personajeLeido);
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

void Juego::procesarJuego() {
  definirPreliminares();  //(Mapa* mapa) ???
  if (estadoJuego == JUGANDO) {
    revisarPartida();
    bool empiezaUno = rand() % 2;
    if (empiezaUno) {
      procesarTurnos(personajesJugadorUno, cantidadPersonajesUno,
                     personajesJugadorDos, cantidadPersonajesDos);
    } else {
      procesarTurnos(personajesJugadorDos, cantidadPersonajesDos,
                     personajesJugadorUno, cantidadPersonajesUno);
    }
  }
  if (estadoJuego == FINALIZADO) {
    archivoPartida.eliminarArchivo();
  }
}
