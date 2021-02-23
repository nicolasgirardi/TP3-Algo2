#include "montana.h"

Montana::Montana() : Casilla() {
  tipo = "montana";
  costo = 1;
}

string Montana::Tipo() { return tipo; }

int Montana::obtenerCosto(string elemento) {
  if (elemento == "tierra") {
    return 0;
  } else if (elemento == "aire") {
    return 2;
  } else {
    return costo;
  }
}
