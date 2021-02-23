#include "precipicio.h"

Precipicio::Precipicio() : Casilla() {
  tipo = "precipicio";
  costo = 1;
}

string Precipicio::Tipo() { return tipo; }

int Precipicio::obtenerCosto(string elemento) {
  if (elemento == "aire") {
    return 0;
  } else if (elemento == "tierra") {
    return 2;
  } else {
    return costo;
  }
}
