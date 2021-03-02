#ifndef CASILLA_H_INCLUDED
#define CASILLA_H_INCLUDED

#include "libraries.h"
#include "personaje.h"

class Casilla {
    protected:
        
        Personaje* ocupante;

    public:
        // PRE:
        // POST: construye una casilla sin ocupante
        Casilla();

        // Verifica si la casilla esta ocupada o no
        // PRE:
        // POST:devuelve true si esta ocupada, false si no
        bool ocupacion();

        // Ocupa la casilla con un personaje
        // PRE: Ocupaci�n debe ser falso
        // POST: pone a un personaje que se pasa dentro de la casilla
        void ocupar(Personaje* personaje);

        // Consulta que personaje esta en la casilla
        // PRE: ocupacion debe ser true
        // POST: devuelve el puntero al personaje de la casilla
        Personaje* obtenerPersonaje();

        // Vacia la casilla de quien la ocupe
        // PRE:
        // POST: ocupante pasa a apuntar a null
        void vaciar();

        // Devuelve el coste de llegar a esta casilla desde una vecina para cada elemento
        // PRE:
        // POST: devuelve el coste de llegar a esta casilla desde una vecina
        virtual int obtenerCosto(string elemento) = 0;
};

#endif  // CASILLA_H_INCLUDED
