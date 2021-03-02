#include "casilla.h"

Casilla::Casilla() { this->ocupante = 0; }

bool Casilla::ocupacion() {
    if (!!ocupante)
        return true;
    else
        return false;
}

void Casilla::ocupar(Personaje* personaje) { ocupante = personaje; }

void Casilla::vaciar() { ocupante = 0; }

Personaje* Casilla::obtenerPersonaje() { return this->ocupante; }
