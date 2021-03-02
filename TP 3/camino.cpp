#include "camino.h"

Camino::Camino() : Casilla() {
    costo = 1;
}

string Camino::Tipo() { return "camino"; }

int Camino::obtenerCosto(string elemento) { return costo; }
