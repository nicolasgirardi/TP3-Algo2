#include "menu.h"

Menu::Menu() { opcion = "0"; }

void Menu::crearPersonaje(string elemento, string nombre, int escudo, int vida) {
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
  diccionarioPersonajes.alta(personajeCreado);
}

Diccionario Menu::obtenerDiccionario() { return diccionarioPersonajes; }


void Menu::elegirOpcion() {
  cout << "Ingrese la opción que desee llevar a cabo: " << endl;
  cin >> this->opcion;
}

void Menu::mostrarMenuPrincipal() {
  cout << endl;
  cout << "Menú" << endl;
  cout << "1) Agregar personaje" << endl;
  cout << "2) Eliminar personaje" << endl;
  cout << "3) Mostrar todos los nombres de los personajes" << endl;
  cout << "4) Buscar por nombre los detalles de un personaje en particular" << endl;
  cout << "5) Comenzar juego" << endl;
  cout << "6) Salir" << endl;
  cout << endl;
}

void Menu::mostrarMenuJuego() {
  cout << endl;
  cout << "Menú" << endl;
  cout << "1) Buscar por nombre los detalles de un personaje en particular" << endl;
  cout << "2) Mostrar todos los nombres de los personajes" << endl;
  cout << "3) Seleccionar personaje" << endl;
  cout << "4) Salir" << endl << endl;

}

void Menu::mostrarSubmenuUno() {
  cout << "Ingrese una de las siguientes opciones:" << endl;
  cout << "1) Alimentar personaje:" << endl;
  cout << "2) Mover personaje." << endl;
  cout << "3) Pasar opcion" << endl;
}

void Menu::mostrarSubmenuDos() {
  cout << "Ingrese una de las siguientes opciones:" << endl;
  cout << "1) Atacar personaje:" << endl;
  cout << "2) Defender personaje." << endl;
  cout << "3) Pasar opcion" << endl;
}

bool Menu::elementoValido(string elemento) {
  return (elemento == "tierra" || elemento == "agua" || elemento == "aire" ||
          elemento == "fuego");
}

void Menu::pedirElemento(string* elemento) {
  cout << endl;
  cout << "Ingrese el elemento del personaje. Puede ser: fuego, tierra, aire o agua" << endl;
  cin >> (*elemento);
  while (!elementoValido(*elemento)) {
    cout << "Elemento incorrecto. Favor de ingresar: fuego, tierra, aire o agua" << endl;
    cin >> (*elemento);
  }
}

void Menu::pedirNombre(string* nombre) {
  cout << endl;
  cout << "Ingrese el nombre del personaje:" << endl;
  cin >> (*nombre);
}

void Menu::ingresarNombre(string* nombre) {
  pedirNombre(nombre);
  while (diccionarioPersonajes.consultaClave(*nombre)) {
    cout << "Este nombre ya está en uso. Favor de ingresar un nuevo nombre" << endl;
    pedirNombre(nombre);
  }
}

void Menu::determinarEscudo(int* escudo) { (*escudo) = rand() % 3; }

void Menu::cargarVida(int* vida) { (*vida) = rand() % 100 + 10; }

void Menu::agregarPersonaje() {
  string elemento, nombre;
  int escudo, vida;

  pedirElemento(&elemento);
  pedirNombre(&nombre);
  determinarEscudo(&escudo);
  cargarVida(&vida);
  crearPersonaje(elemento, nombre, escudo, vida);
}

Personaje* Menu::buscarNombre(string* nombre) {
  pedirNombre(nombre);  // esto no va en otro metodo?
  while (!diccionarioPersonajes.consultaClave(*nombre)) {
    cout << "Nombre no encontrado. Vuelva a ingresar un nombre" << endl;
    pedirNombre(nombre);
  }
  return diccionarioPersonajes.consultaNodo(*nombre);
}

void Menu::eliminarPersonaje() {
  string nombre;
  pedirNombre(&nombre);
  diccionarioPersonajes.baja(nombre);  // Hechar vistazo a dicc.
}

void Menu::mostrarNombres() { diccionarioPersonajes.imprimirClaves(); }

void Menu::verDetalles() {
  string nombre;
  buscarNombre(&nombre);
  diccionarioPersonajes.consultaInfo(nombre);
}

void Menu::iniciarJuego(char* estadoJuego) { *estadoJuego = JUGANDO; }

void Menu::ejecutarOpcionPrincipal(char* estadoJuego) {
  switch (stoi(opcion)) {
    case OPCION_NUEVO_PERSONAJE:
      agregarPersonaje();
      break;
    case OPCION_ELIMINAR_PERSONAJE:
      eliminarPersonaje();
      break;
    case OPCION_MOSTRAR_NOMBRES:
      mostrarNombres();
      break;
    case OPCION_BUSCAR_PERSONAJE:
      verDetalles();
      break;
    case OPCION_JUGAR:
      iniciarJuego(estadoJuego);
      break;
  }
}

void Menu::imprimirError() {
  cout << "Ya eligió el máximo número de personajes permitidos, que es 3."
       << endl;
}

void Menu::imprimirUsado() {
  cout << "Este personaje ya está seleccionado." << endl;
}

void Menu::seleccionarPersonaje(Personaje* jugador[MAX_PERSONAJES], int* tope, string* nombre) {
    cout << *nombre << endl;
    jugador[*tope] = diccionarioPersonajes.consultaNodo(*nombre);
    cout << jugador[*tope]->obtenerNombre() << endl;
    jugador[*tope]->asignarCondicion(true);

    diccionarioPersonajes.todoDetalles(diccionarioPersonajes.obtenerRaiz());

    (*tope)++;
}

void Menu::nombreValido(string *nombre)
{
    if(!(diccionarioPersonajes.consultaClave(*nombre))) {
        cout << "Este nombre no se encuentra en la lista de personajes." << endl;
        pedirNombre(nombre);
        nombreValido(nombre);
    }
    if((diccionarioPersonajes.consultaNodo(*nombre))->obtenerCondicion()){
        diccionarioPersonajes.todoDetalles(diccionarioPersonajes.obtenerRaiz());
        imprimirUsado();
        pedirNombre(nombre);
        nombreValido(nombre);
    }
}


void Menu::procesarSeleccion(Personaje* jugadorUno[MAX_PERSONAJES],int* topeUno,Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos) {



    for (int i = 0; i < MAX_PERSONAJES; ++i){
        string* nombre1 = new string;
        string* nombre2 = new string;

        cout << "Jugador uno:" << endl;
        pedirNombre(nombre1);
        nombreValido(nombre1);
        seleccionarPersonaje(jugadorUno, topeUno, nombre1);
        cout << *nombre1 << " ha sido seleccionado con éxito." << endl << endl;

        cout << "Jugador dos:" << endl;
        pedirNombre(nombre2);
        nombreValido(nombre2);
        seleccionarPersonaje(jugadorDos, topeDos, nombre2);
        cout << *nombre2 << " ha sido seleccionado con éxito." << endl << endl;

        delete nombre1;
        delete nombre2;
    }



}

void Menu::ejecutarOpcionJuego(Personaje* jugadorUno[MAX_PERSONAJES], int* topeUno, Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos) {
  switch (stoi(opcion)) {

    case OPCION_DETALLAR:
      verDetalles();
      break;
    case OPCION_LISTAR:
      mostrarNombres();
      break;
    case OPCION_SELECCIONAR:
      procesarSeleccion(jugadorUno, topeUno, jugadorDos, topeDos);
      break;
  }
}

void Menu::limpiarOpcion() { this->opcion = "0"; }

// BUEN NOMBRE??? creo que si jej soy edu, el de la pregunta no fui yo ja
void Menu::procesarMenuJuego(Personaje* jugadorUno[MAX_PERSONAJES],int* topeUno,Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos)
{
    limpiarOpcion();

    while (stoi(opcion) != SALIDA_JUEGO && stoi(opcion) != OPCION_SELECCIONAR){
        mostrarMenuJuego();
        elegirOpcion();
        ejecutarOpcionJuego(jugadorUno, topeUno, jugadorDos, topeDos);
    }
}

void Menu::procesarMenuPrincipal(char* estadoJuego) {
  while (stoi(opcion) != SALIDA_MENU_PRINCIPAL && stoi(opcion) != OPCION_JUGAR) {
    mostrarMenuPrincipal();
    elegirOpcion();
    ejecutarOpcionPrincipal(estadoJuego);
  }
}

void Menu::alimentarPersonaje(Personaje* personaje) { personaje->alimentar(); }

bool Menu::filaValida(int fila){
    return (fila >= MINIMO_TABLERO && fila <= MAXIMO_TABLERO);
}

bool Menu::columnaValida(int columna){
    return (columna >= MINIMO_TABLERO && columna <= MAXIMO_TABLERO);
}

void Menu::pedirFila(int* fila){
    cout << "Ingrese fila: ";
    cin >> *fila;
    while (!filaValida(*fila)){
        cout << "Fila ingresada en el rango incorrecto, debe ingresar una fila entre 1 y 8: ";
        cin >> *fila;
    }
}

void Menu::pedirColumna(int* columna){
    cout << "Ingrese columna: ";
    cin >> *columna;
    while (!columnaValida(*columna)){
        cout << "Columna ingresada en el rango incorrecto, debe ingresar una columna entre 1 y 8: ";
        cin >> *columna;
    }
}

void Menu::pedirCoordenada(Coordenada* destino, Personaje* personaje){
    int fila, columna;
    cout << "Indique las coordenadas a donde desea mover "<< personaje->obtenerNombre() << ":" << endl;
    pedirFila(&fila);
    pedirColumna(&columna);
    destino->cambiarFilaYColumna(fila,columna);
}

void Menu::concretarMovimiento(Mapa* mapa, Personaje* personaje, Coordenada destino, int costo, bool* mover){
	mapa->consulta(destino)->obtenerDato()->ocupar(personaje);
    mapa->consulta(*(personaje->obtenerCoordenada()))->obtenerDato()->vaciar();
    personaje->asignarCoordenada(destino.obtenerFila(), destino.obtenerColumna());
    personaje->gastarEnergia(costo);
    (*mover) = true;
}
																			  
void Menu::moverPersonaje(Mapa* mapa, Personaje* personaje, Costos* costos) {
  Coordenada destino(0);
  int costoMovimiento;
  bool mover = false;
  do {
    pedirCoordenada(&destino,personaje);
    costoMovimiento = costos->consultarCosto(personaje->obtenerCoordenada(), &destino);
    if (costoMovimiento <= personaje->obtenerEnergia())
      if (mapa->consulta(destino)->obtenerDato()->ocupacion())
        cout << "La casilla de destino se encuentra ocupada, elija otra casilla" << endl;
      else {
        costos->consultarCaminoMinimo(personaje->obtenerCoordenada(),&destino);
		concretarMovimiento(mapa,personaje,destino,costoMovimiento,&mover);
      }
    else
      cout << "El personaje no cuenta con suficiente energia para ese movimiento, elija otra casilla" << endl;
  } while (!mover);
}
Costos* Menu::determinarCosto(string elemento, Costos* costos[4]){
    int i = 0;
    while (costos[i]->consultarElemento() != elemento)
    {
        i++;
    }
    return costos[i];
}

void Menu::ejecutarOpcionSubUno(Mapa* mapa, Personaje* personaje, Costos* costos[4]) {
    switch (stoi(opcion)) {
    case OPCION_ALIMENTAR:
      alimentarPersonaje(personaje);
      break;
    case OPCION_MOVER:
      moverPersonaje(mapa, personaje, determinarCosto(personaje->obtenerElemento(), costos));
      break;
  }
}


void Menu::ejecutarOpcionSubDos(Personaje* personaje, Personaje* enemigos[MAX_PERSONAJES], Personaje* aliados[MAX_PERSONAJES])
{
  switch (stoi(opcion)) {
    case OPCION_ATACAR:
			if (personaje->puedeAtacar()){
		 		personaje->ataque(enemigos);
			}
      break;
    case OPCION_DEFENDER:
			if (personaje->puedeDefender()){
			    personaje->defensa(aliados);
			}
      break;
  }
}

void Menu::procesarTurno(Mapa* mapa, Personaje* personaje, Costos* costos[4], Personaje* enemigos[MAX_PERSONAJES],  Personaje* aliados[MAX_PERSONAJES]) {
  personaje->reseteoDefensa();
  cout << "Le toca jugar a " << personaje->obtenerNombre() << endl << endl;
  cout << "Estos son sus detalles:" << endl << endl;
  diccionarioPersonajes.consultaInfo(personaje->obtenerNombre());

  mostrarSubmenuUno();
  elegirOpcion();
  if (stoi(opcion) != PASAR) {
    ejecutarOpcionSubUno(mapa, personaje, costos);
  }
  mostrarSubmenuDos();
  elegirOpcion();
  if (stoi(opcion) != PASAR) {
    ejecutarOpcionSubDos(personaje, enemigos, aliados);
  }
}

string Menu::obtenerOpcion(){
    return opcion;
};


Menu::~Menu() {}

// los metodos de atacar, mover, alimentar personaje, no deberian de ir en la
// clase Personaje?? Hecho, solo falta el de moverr
