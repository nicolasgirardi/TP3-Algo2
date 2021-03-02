

#ifndef DICCIONARIO_CPP_MENUPRINCIPAL_H
#define DICCIONARIO_CPP_MENUPRINCIPAL_H

#include "menu.h"

class MenuPrincipal: public Menu {
private:
	//POST: deja inicializada la vida con un valor válido
    void cargarVida(int* vida);
	
	//POST:deja inicializado el escudo con un valor válido
    void determinarEscudo(int* escudo);
    
    //POST: devuelve true si es uno de los 4 elementos del juego: aire, tierra, agua, fuego
    bool elementoValido(string elemento);
    
    //POST: pide por pantalla al usuario ingresar un elemento válido
    void pedirElemento(string* elemento);
	
	//POST: procesa el agregado del personaje
    void agregarPersonaje(Diccionario* diccionarioPersonajes);
	
	//POST: da de baja un personaje del diccionario
    void eliminarPersonaje(Diccionario* diccionarioPersonajes);

	//POST: cambia el estado de juego a jugando
    void iniciarJuego(char* estadoJuego);
	
	//POST: llamada a la función correspondiente de acuerdo a la opcion elegida
    void ejecutarOpcionPrincipal(char* estadoJuego,Diccionario* diccionarioPersonajes);

	
	//POST: imprime por pantalla el menu
    void mostrarMenu();
	
public:  

	//POST: crea un objeto menu con la opcion en 0
    MenuPrincipal();

    //POST: crea un personaje en la memoria dinámica y los da de alta en el diccionario
    void crearPersonaje(string elemento, string nombre, int escudo, int vida, Diccionario* diccionarioPersonajes);

	//POST: procesa el menu hasta que opcion sea SALIR o Empezar juego
    void procesarMenuPrincipal(char* estadoJuego,Diccionario* diccionarioPersonajes);

    //POST: procesa el pedido del nombre hasta que sea válido (no se encuentre en el diccionario)
    void ingresarNombre(string* nombre,Diccionario* diccionarioPersonajes);

    ~MenuPrincipal();










};


#endif //DICCIONARIO_CPP_MENUPRINCIPAL_H
