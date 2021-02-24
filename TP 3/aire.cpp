#include "aire.h"

Aire::Aire(string nombre, int escudo, int vida, int fila, int columna)
    : Personaje(nombre, escudo, vida, fila, columna) {
  elemento = "aire";
  alimento = "aire";
  defensaActivada = false;
}

void Aire::alimentar() {
  cout << "No se pueden alimentar los personajes de aire" << endl;
}

string Aire::obtenerElemento() { return elemento; }

string Aire::obtenerAlimento() { return alimento; }

int Aire::obtenerDanio(string elemento) {
  int danio = 15;
  if (elemento == "tierra")
    danio += 5;
  else if (elemento == "fuego")
    danio -= 5;
  return danio;
}

void Aire::ataque(Personaje* enemigos[]) {
  gastarEnergia(8);

  int i;
  for (i = 0; i < MAX_PERSONAJES; i++) {
    enemigos[i]->daniar(this->obtenerDanio(enemigos[i]->obtenerElemento()));
  }
}

void Aire::defensa() {
  gastarEnergia(15);
  this->defensaActivada = true;
}

void Aire::reseteoDefensa(){
	if(defensaActivada)
		defensaActivada = false;
}
