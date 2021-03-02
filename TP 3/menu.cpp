#include "menu.h"

Menu::Menu() { opcion = "0"; }



void Menu::asignarOpcion(string d){
    this->opcion = d;
}

void Menu::elegirOpcion() {
  cout << "Ingrese la opción que desee llevar a cabo: " << endl;
  cin >> this->opcion;
}


void Menu::pedirNombre(string* nombre) {
  cout << endl;
  cout << "Ingrese el nombre del personaje:" << endl;
  cin >> (*nombre);
}

void Menu::mostrarNombres(Diccionario* diccionarioPersonajes) { diccionarioPersonajes->imprimirClaves(); }


Personaje* Menu::buscarNombre(string* nombre,Diccionario* diccionarioPersonajes) {
    pedirNombre(nombre);// esto no va en otro metodo?
    cout << *nombre << endl;
    while (!diccionarioPersonajes->consultaClave(*nombre)) {
        cout << "Nombre no encontrado. Vuelva a ingresar un nombre" << endl;
        pedirNombre(nombre);
    }
    return diccionarioPersonajes->consultaNodo(*nombre);
}

void Menu::verDetalles(Diccionario* diccionarioPersonajes) {
    string nombre;
    buscarNombre(&nombre,diccionarioPersonajes);
    cout << nombre << endl;
    diccionarioPersonajes->consultaInfo(nombre);
}

void Menu::pedirCoordenada(Coordenada* destino, Personaje* personaje) {
    int fila, columna;
    cout << "Indique las coordenadas a donde desea mover "
         << personaje->obtenerNombre() << ":" << endl;
    pedirFila(&fila);
    pedirColumna(&columna);
    destino->cambiarFilaYColumna(fila, columna);
}

void Menu::concretarMovimiento(Mapa* mapa, Personaje* personaje,Coordenada destino, int costo,bool* mover) {
    mapa->consulta(destino)->obtenerDato()->ocupar(personaje);
    mapa->consulta(*(personaje->obtenerCoordenada()))->obtenerDato()->vaciar();
    personaje->asignarCoordenada(destino.obtenerFila(), destino.obtenerColumna());
    personaje->gastarEnergia(costo);
    (*mover) = true;
}


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




string Menu::obtenerOpcion(){
    return opcion;
};


Menu::~Menu() {}

// los metodos de atacar, mover, alimentar personaje, no deberian de ir en la
// clase Personaje?? Hecho, solo falta el de moverr
