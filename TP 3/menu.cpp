#include "menu.h"

Menu::Menu() { opcion = "0"; }

void Menu::asignarOpcion(string d){
    this->opcion = d;
}

void Menu::elegirOpcion() {
    cout << "Ingrese la opción que desee llevar a cabo: " << endl;
    cin >> this->opcion;
    cout << endl;
}


void Menu::pedirNombre(string* nombre) {
    cout << endl;
    cout << "Ingrese el nombre del personaje:" << endl;
    cin >> (*nombre);
}

void Menu::mostrarNombres(Diccionario* diccionarioPersonajes) { diccionarioPersonajes->imprimirClaves(); }


Personaje* Menu::buscarNombre(string* nombre,Diccionario* diccionarioPersonajes) {
    pedirNombre(nombre);
    while (!diccionarioPersonajes->consultaClave(*nombre)) {
        cout << "Nombre no encontrado. Vuelva a ingresar un nombre" << endl;
        pedirNombre(nombre);
    }
    return diccionarioPersonajes->consultaNodo(*nombre);
}

void Menu::verDetalles(Diccionario* diccionarioPersonajes) {
    string nombre;
    buscarNombre(&nombre,diccionarioPersonajes);
    diccionarioPersonajes->consultaInfo(nombre);
}


void Menu::concretarMovimiento(Mapa* mapa, Personaje* personaje,Coordenada destino, int costo,bool* mover) {
    mapa->consulta(destino)->obtenerDato()->ocupar(personaje);
    mapa->consulta(*(personaje->obtenerCoordenada()))->obtenerDato()->vaciar();
    personaje->asignarCoordenada(destino.obtenerFila(), destino.obtenerColumna());
    personaje->gastarEnergia(costo);
    (*mover) = true;
}

void Menu::borrarPantalla(){
    for(int i = 0; i < 30; i++){
        cout << endl;
    }
}



string Menu::obtenerOpcion(){
    return opcion;
};


Menu::~Menu() {}
