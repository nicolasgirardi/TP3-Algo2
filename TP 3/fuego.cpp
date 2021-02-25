#include "fuego.h"

Fuego::Fuego(string nombre, int escudo, int vida, int fila, int columna)
    : Personaje(nombre, escudo, vida, fila, columna) {
  alimento = "madera";
  elemento = "fuego";
}

string Fuego::obtenerElemento() { return elemento; }

string Fuego::obtenerAlimento() { return alimento; }

void Fuego::alimentar() {
  int vidaSuministrada = 0;
  int energiaSuministrada = 0;

  while (vida < TOPE_VIDA && vidaSuministrada < AUMENTO_FUEGO) {
    vida++;
    vidaSuministrada++;
  }

  while (energia < TOPE_ENERGIA &&
         energiaSuministrada < 10) {  // Ese 10 puede ser constante.
    energia++;
    energiaSuministrada++;
  }
}

int Fuego::obtenerDanio(string elemento) {
  int danio = 20;
  if (elemento == "aire")
    danio += 10;
  else if (elemento == "agua")
    danio -= 10;
  return danio;
}

void Fuego::ataque(Personaje* enemigos[]) {
  int i;
  for (i = 0; i < MAX_PERSONAJES; i++) {
    if (abs(this->coordenada->obtenerFila() -
            enemigos[i]->obtenerCoordenada()->obtenerFila()) <= 1) {
      enemigos[i]->daniar(this->obtenerDanio(enemigos[i]->obtenerElemento()));
      gastarEnergia(5);
    }
  }
}

void Fuego::defensa() {
  gastarEnergia(10);
  asignarVida(this->vida + 10);
}

bool Fuego::puedeAtacar(){
	if(this->energia >= 5)
		return true;
	else
		return false;	
}

bool Tierra::puedeDefender(){
	if(this->energia >= 10)
		return true;
	else
		return false;	
}
