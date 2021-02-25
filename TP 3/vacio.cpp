#include "vacio.h"

Vacio::Vacio(): Casilla(){
	costo = 15;
}

string Vacio::Tipo(){
	return "vacio";
}

int Vacio::obtenerCosto(string elemento){
	return costo;
}
