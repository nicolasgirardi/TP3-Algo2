#include "pila.h"

void Pila::apilar(coordPtr d) {
    NodoPila* nuevo = new NodoPila(d);
    nuevo->cambiar_siguiente(ultimo);
    ultimo = nuevo;
}

void Pila::desapilar() {
    NodoPila* borrar = ultimo;
    ultimo = borrar->obtener_siguiente();
    delete borrar->obtener_dato();
    delete borrar;
}

coordPtr Pila::consultar() {
    return ultimo->obtener_dato();
}

bool Pila::vacia() {
    return (ultimo == 0);
}

Pila::~Pila() {
    while (! vacia())
        desapilar();
}
