#include "camino.h"

Camino::Camino() : Casilla() {
  tipo = "camino";
  costo = 1;
}

string Camino::Tipo() { return tipo; }

int Camino::obtenerCosto(string elemento) { return costo; }
