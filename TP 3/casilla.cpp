#include "casilla.h"

Casilla::Casilla() { this->ocupante = 0; }

bool Casilla::Ocupacion() {
  if (!!ocupante)
    return true;
  else
    return false;
}

void Casilla::Ocupar(Personaje* personaje) { ocupante = personaje; }

void Casilla::Vaciar() { ocupante = 0; }

Personaje* Casilla::obtenerPersonaje() { return this->ocupante; }
