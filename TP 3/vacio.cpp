#include "vacio.h"

Vacio::Vacio(): Casilla(){
	tipo = "vacio";
	costo = 15;
}

string Vacio::Tipo(){
	return tipo;
}

int Vacio::obtenerCosto(string elemento){
	return costo;
}
