#ifndef NODO_pila_H_INCLUDED
#define NODO_pila_H_INCLUDED

#include "coordenada.h"

typedef Coordenada* coordPtr;

class NodoPila {
private:
    // atributos
    coordPtr dato;
    NodoPila* siguiente;

public:
    // metodos
    // constructor
    // PRE:
    // POS: crea un nodo con dato = d y siguiente = 0
    NodoPila(coordPtr d);

    void cambiar_dato(coordPtr d);

    void cambiar_siguiente(NodoPila* s);

    coordPtr obtener_dato();

    NodoPila* obtener_siguiente();
};

#endif // NODO_H_INCLUDED
