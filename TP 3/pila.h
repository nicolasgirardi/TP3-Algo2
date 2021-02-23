#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "nodo_pila.h"


class Pila {
private:
    // Atributos
    NodoPila* ultimo = 0;

public:
    // Metodos
    // PRE:
    // POS: agrega d en la cima de la pila
    void apilar(coordPtr d);

    // PRE: pila no esta vacia
    // POS: quita el ultimo dato de la pila
    void desapilar();


    // PRE: -
    // POS: ultimo = 0
    bool vacia();

    // PRE: pila no vacia
    // POS: devuelve el ultimo dato
    coordPtr consultar();

    ~Pila();

};


#endif // PILA2_H_INCLUDED
