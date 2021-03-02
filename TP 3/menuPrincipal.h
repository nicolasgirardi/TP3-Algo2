

#ifndef DICCIONARIO_CPP_MENUPRINCIPAL_H
#define DICCIONARIO_CPP_MENUPRINCIPAL_H

#include "menu.h"

class MenuPrincipal: public Menu {
private:

public:  //VER CUALES PONER PRIVATE

    MenuPrincipal();


    void procesarMenuPrincipal(char* estadoJuego,Diccionario* diccionarioPersonajes);

    void agregarPersonaje(Diccionario* diccionarioPersonajes);

    void eliminarPersonaje(Diccionario* diccionarioPersonajes);

    void iniciarJuego(char* estadoJuego);

    void ejecutarOpcionPrincipal(char* estadoJuego,Diccionario* diccionarioPersonajes);

    void crearPersonaje(string elemento, string nombre, int escudo, int vida, Diccionario* diccionarioPersonajes);


    void mostrarMenu();

    void determinarEscudo(int* escudo);

    void cargarVida(int* vida);

    bool elementoValido(string elemento);

    void pedirElemento(string* elemento);

    void ingresarNombre(string* nombre,Diccionario* diccionarioPersonajes);


    ~MenuPrincipal();










};


#endif //DICCIONARIO_CPP_MENUPRINCIPAL_H
