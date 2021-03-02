#ifndef NODO_pila_H_INCLUDED
#define NODO_pila_H_INCLUDED

#include "coordenada.h"

typedef Coordenada* coordPtr;

class NodoPila {
    private:
        
        coordPtr dato;
        NodoPila* siguiente;

    public:
        // Constructor
        // PRE:
        // POST: crea un nodo con dato = d y siguiente = 0
        NodoPila(coordPtr d);

        // POST: cambia el dato por el dato ingresado
        void cambiar_dato(coordPtr d);

        // POST: cambia el nodo siguiente por uno nuevo ingresado
        void cambiar_siguiente(NodoPila* s);

        // POST: devuelve el dato
        coordPtr obtener_dato();

        // POST: devuelve el siguiente
        NodoPila* obtener_siguiente();
};

#endif // NODO_H_INCLUDED
