#include "lago.h"

Lago::Lago() : Casilla() {
  tipo = "lago";
  costo = 1;
}

string Lago::Tipo() { return tipo; }

int Lago::obtenerCosto(string elemento) {
  if (elemento == "agua") {
    return 0;
  } else if (elemento == "fuego") {
    return 2;
  } else {
    return costo;
  }
}
