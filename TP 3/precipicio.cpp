#include "precipicio.h"

Precipicio::Precipicio() : Casilla() {
  costo = 1;
}

string Precipicio::Tipo() { return "precipicio"; }

int Precipicio::obtenerCosto(string elemento) {
  if (elemento == "aire") {
    return 0;
  } else if (elemento == "tierra") {
    return 2;
  } else {
    return costo;
  }
}
