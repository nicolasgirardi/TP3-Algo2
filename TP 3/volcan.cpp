#include "volcan.h"

Volcan::Volcan() : Casilla() {
  tipo = "volcan";
  costo = 1;
}

string Volcan::Tipo() { return tipo; }

int Volcan::obtenerCosto(string elemento) {
  if (elemento == "fuego") {
    return 0;
  } else if (elemento == "agua") {
    return 2;
  } else {
    return costo;
  }
}
