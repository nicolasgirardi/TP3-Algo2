#include "fuego.h"

Fuego::Fuego(string nombre, int escudo, int vida): Personaje(nombre, escudo, vida) {
  alimento = "madera";
}

string Fuego::obtenerElemento() { return "fuego"; }

string Fuego::obtenerAlimento() { return alimento; }

void Fuego::alimentar() {
  int vidaSuministrada = 0;
  int energiaSuministrada = 0;

  while (vida < TOPE_VIDA && vidaSuministrada < AUMENTO_FUEGO) {
    vida++;
    vidaSuministrada++;
  }

  while (energia < TOPE_ENERGIA &&
         energiaSuministrada < ENERGIA_LIMITE) {  // Ese 10 puede ser constante. =10
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
  gastarEnergia(ENERGIA_ATAQUE_FUEGO);
  for (int i = 0; i < MAX_PERSONAJES; i++) {
    if (abs(this->coordenada->obtenerFila() - enemigos[i]->obtenerCoordenada()->obtenerFila()) <= 1) {
      enemigos[i]->daniar(this->obtenerDanio(enemigos[i]->obtenerElemento()));
    }
  }
}

void Fuego::defensa() {
  gastarEnergia(ENERGIA_DEFENSA_FUEGO);
  asignarVida(this->vida + 10);
}

bool Fuego::puedeAtacar(){
	if(this->energia >= ENERGIA_ATAQUE_FUEGO)
		return true;
	else
		return false;	
}

bool Fuego::puedeDefender(){
	if(this->energia >= ENERGIA_DEFENSA_FUEGO)
		return true;
	else
		return false;	
}
