#include "lago.h"

Lago::Lago() : Casilla() {
    costo = 1;
}

string Lago::Tipo() { return "lago"; }

int Lago::obtenerCosto(string elemento) {
    if (elemento == "agua") {
        return 0;
    } else if (elemento == "fuego") {
        return 2;
    } else {
        return costo;
    }
}
