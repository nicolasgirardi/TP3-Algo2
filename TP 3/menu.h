#ifndef TP2_MENU_H
#define TP2_MENU_H

#include "agua.h"
#include "aire.h"
#include "archivo.h"
#include "costos.h"
#include "diccionario.h"
#include "fuego.h"
#include "mapa.h"
#include "tierra.h"

class Menu {
    protected:
        
        string opcion;

    public:
        // POST: construye un menu. Se inicializa opcion con un valor distinto a la
        // salida (6 menu, 4 submenu) para asegurarse entrar al ciclo aunque sea una
        // vez.
        Menu();

        // POST: se realiza el movimiento de un personaje en el transcurso del juego, 
        // cuando el usuario elige la opcion de jugar. 
        void concretarMovimiento(Mapa* mapa, Personaje* personaje,Coordenada destino, int costo,bool* mover);

        // POST: asigna una nueva opcion del menu
        void asignarOpcion(string d);

        // POST: obtiene la opcion del menu
        string obtenerOpcion();

        //POST: pide y guarda la opción ingresada por el usuario
        void elegirOpcion();

        // POST: pide y guarda el nombre ingresado por el usuario
        void pedirNombre(string* nombre);

        // POST: procesa para mostrar detalles de un personaje a elección
        void verDetalles(Diccionario* diccionarioPersonajes);

        // POST: muestra por pantalla un listado con los nombres de cada personaje de
        // la lista
        void mostrarNombres(Diccionario* diccionarioPersonajes);

        // POST: busca un nombre en el diccionario y devuelve el personaje
        Personaje* buscarNombre(string* nombre,Diccionario* diccionarioPersonajes);

        // POST: limpia la pantalla
        void borrarPantalla();

        // POST: imprime por pantalla el menu del juego.
        virtual void mostrarMenu() = 0;

        // POST:libera la memoria
        virtual ~Menu();
};

#endif  // TP2_MENU_H
