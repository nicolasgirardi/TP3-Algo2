//
// Created by ginov on 01/03/2021.
//

#ifndef DICCIONARIO_CPP_MENUJUEGO_H
#define DICCIONARIO_CPP_MENUJUEGO_H

#include "menu.h"

class MenuJuego: public Menu {

	public:

		// Contructor del Menu Juego
		MenuJuego();
		
		// POST: muestra el menu por pantalla
		void mostrarMenu();

		// POST: procesa la seleccion de personajes
		void procesarSeleccion(Personaje* jugadorUno[MAX_PERSONAJES],int* topeUno,Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos, Diccionario* diccionarioPersonajes);

		// POST: se encarga de seleccionar un personaje del diccionario de personajes,
		// y se lo asigna al vector de los personajes del jugador.
		void seleccionarPersonaje(Personaje* jugador[MAX_PERSONAJES], int* tope, string* nombre, Diccionario* diccionarioPersonajes);

		// POST: verifica si el nombre ingresado pertenece al diccionario
		void nombreValido(string *nombre, Diccionario* diccionarioPersonajes);

		// POST: imprime por pantalla si un personaje ya ha sido seleccionado
		void imprimirUsado();
	
		// POST: ejecuta la opcion seleccionada por el usuario del menu Juego.
		void ejecutarOpcionJuego(Personaje* jugadorUno[MAX_PERSONAJES], int* topeUno, Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos, Diccionario* diccionarioPersonajes);

		// POST: se encarga de procesar el menu del Juego.
		void procesarMenuJuego(Personaje* jugadorUno[MAX_PERSONAJES],int* topeUno,Personaje* jugadorDos[MAX_PERSONAJES],int* topeDos,Diccionario* diccionarioPersonajes);

		// Destructor
		~MenuJuego();
};



#endif //DICCIONARIO_CPP_MENUJUEGO_H
