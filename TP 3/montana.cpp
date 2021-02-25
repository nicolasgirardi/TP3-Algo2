#include "montana.h"

Montana::Montana() : Casilla() {
  costo = 1;
}

string Montana::Tipo() { return "montana"; }

int Montana::obtenerCosto(string elemento) {
  if (elemento == "tierra") {
    return 0;
  } else if (elemento == "aire") {
    return 2;
  } else {
    return costo;
  }
}
