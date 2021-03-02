//
// Created by ginov on 01/03/2021.
//

#ifndef DICCIONARIO_CPP_MENUJUEGO_H
#define DICCIONARIO_CPP_MENUJUEGO_H

#include "menu.h"

class MenuJuego: public Menu {

public:

    MenuJuego();


    void procesarSeleccion(Personaje* jugadorUno[MAX_PERSONAJES],int* topeUno,Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos, Diccionario* diccionarioPersonajes);

    void seleccionarPersonaje(Personaje* jugador[MAX_PERSONAJES], int* tope, string* nombre, Diccionario* diccionarioPersonajes);

    void nombreValido(string *nombre, Diccionario* diccionarioPersonajes);

    void mostrarMenu();

    void ejecutarOpcionJuego(Personaje* jugadorUno[MAX_PERSONAJES], int* topeUno, Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos, Diccionario* diccionarioPersonajes);

    void procesarMenuJuego(Personaje* jugadorUno[MAX_PERSONAJES],int* topeUno,Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos,Diccionario* diccionarioPersonajes);

    void imprimirUsado();


    ~MenuJuego();



};



#endif //DICCIONARIO_CPP_MENUJUEGO_H
