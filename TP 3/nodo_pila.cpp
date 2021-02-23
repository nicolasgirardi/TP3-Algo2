#include "nodo_pila.h"

NodoPila::NodoPila(coordPtr d) {
    dato = d;
    siguiente = 0;
}

void NodoPila::cambiar_dato(coordPtr d) {
    dato = d;
}

void NodoPila::cambiar_siguiente(NodoPila* s) {
    siguiente = s;
}

coordPtr NodoPila::obtener_dato() {
    return dato;
}

NodoPila* NodoPila::obtener_siguiente() {
    return siguiente;
}
