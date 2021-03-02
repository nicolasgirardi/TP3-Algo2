#include "menuJuego.h"

MenuJuego::MenuJuego():Menu(){

}

void MenuJuego::mostrarMenu() {
    cout << endl;
    cout << "Menú" << endl;
    cout << "1) Buscar por nombre los detalles de un personaje en particular" << endl;
    cout << "2) Mostrar todos los nombres de los personajes" << endl;
    cout << "3) Seleccionar personaje" << endl;
    cout << "4) Salir" << endl << endl;

}

void MenuJuego::seleccionarPersonaje(Personaje* jugador[MAX_PERSONAJES], int* tope, string* nombre, Diccionario* diccionarioPersonajes) {
    cout << *nombre << endl;
    jugador[*tope] = diccionarioPersonajes->consultaNodo(*nombre);
    cout << jugador[*tope]->obtenerNombre() << endl;
    jugador[*tope]->asignarCondicion(true);

    diccionarioPersonajes->todoDetalles(diccionarioPersonajes->obtenerRaiz());

    (*tope)++;
}

void MenuJuego::nombreValido(string *nombre, Diccionario* diccionarioPersonajes)
{
    if(!(diccionarioPersonajes->consultaClave(*nombre))) {
        cout << "Este nombre no se encuentra en la lista de personajes." << endl;
        pedirNombre(nombre);
        nombreValido(nombre,diccionarioPersonajes);
    }
    if((diccionarioPersonajes->consultaNodo(*nombre))->obtenerCondicion()){
        diccionarioPersonajes->todoDetalles(diccionarioPersonajes->obtenerRaiz());
        imprimirUsado();
        pedirNombre(nombre);
        nombreValido(nombre,diccionarioPersonajes);
    }
}

void MenuJuego::procesarSeleccion(Personaje* jugadorUno[MAX_PERSONAJES],int* topeUno,Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos, Diccionario* diccionarioPersonajes) {
    for (int i = 0; i < MAX_PERSONAJES; ++i){
        string* nombre1 = new string;
        string* nombre2 = new string;

        cout << "Jugador uno:" << endl;
        pedirNombre(nombre1);
        nombreValido(nombre1,diccionarioPersonajes);
        seleccionarPersonaje(jugadorUno, topeUno, nombre1,diccionarioPersonajes);
        cout << *nombre1 << " ha sido seleccionado con éxito." << endl << endl;

        cout << "Jugador dos:" << endl;
        pedirNombre(nombre2);
        nombreValido(nombre2,diccionarioPersonajes);
        seleccionarPersonaje(jugadorDos, topeDos, nombre2,diccionarioPersonajes);
        cout << *nombre2 << " ha sido seleccionado con éxito." << endl << endl;

        delete nombre1;
        delete nombre2;
    }
}


void MenuJuego::imprimirUsado() {
    cout << "Este personaje ya está seleccionado." << endl;
}


void MenuJuego::ejecutarOpcionJuego(Personaje* jugadorUno[MAX_PERSONAJES], int* topeUno, Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos, Diccionario* diccionarioPersonajes) {
    switch (stoi(opcion)) {

        case OPCION_DETALLAR:
            verDetalles(diccionarioPersonajes);
            break;
        case OPCION_LISTAR:
            mostrarNombres(diccionarioPersonajes);
            break;
        case OPCION_SELECCIONAR:
            procesarSeleccion(jugadorUno, topeUno, jugadorDos, topeDos, diccionarioPersonajes);
            break;
    }
}

void MenuJuego::procesarMenuJuego(Personaje* jugadorUno[MAX_PERSONAJES],int* topeUno,Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos, Diccionario* diccionarioPersonajes)
{
    while (stoi(opcion) != SALIDA_JUEGO && stoi(opcion) != OPCION_SELECCIONAR){
        mostrarMenu();
        elegirOpcion();
        borrarPantalla();
        ejecutarOpcionJuego(jugadorUno, topeUno, jugadorDos, topeDos, diccionarioPersonajes);
    }
}

MenuJuego::~MenuJuego(){}

