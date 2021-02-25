#include "tierra.h"

Tierra::Tierra(string nombre, int escudo, int vida): Personaje(nombre, escudo, vida) {
  alimento = "hierbas";
  defensaActivada = false;
}

string Tierra::obtenerElemento() { return "tierra"; }

string Tierra::obtenerAlimento() { return alimento; }

void Tierra::alimentar() {
  int energiaSuministrada = 0;
  while (energia < TOPE_ENERGIA && energiaSuministrada < AUMENTO_TIERRA) {
    energia++;
    energiaSuministrada++;
  }
}

int Tierra::obtenerDanio(string elemento, int zona) {
  int danio;
  if (elemento == "aire")
    danio = 10;
  else
    switch (zona) {
      case (0):
        danio = 30;
        break;
      case (1):
        danio = 20;
        break;
      case (2):
        danio = 10;
        break;
    }
  if (elemento == "agua") danio = danio + 20;
  return danio;
}

int Tierra::zona(Coordenada* objetivo) {
  int dfila;
  int dcolumna;
  dfila = abs(this->coordenada.obtenerFila() - objetivo->obtenerFila());
  dcolumna = abs(this->coordenada.obtenerColumna() - objetivo->obtenerColumna());
  if (dfila <= 2 && dcolumna <= 2)
    return 0;
  else if (dfila <= 4 && dcolumna <= 4)
    return 1;
  else
    return 2;
}

void Tierra::ataque(Personaje* aliados[MAX_PERSONAJES]) {
  gastarEnergia(ENERGIA_ATAQUE_TIERRA);
  int zona;
  for (int i = 0; i < MAX_PERSONAJES; i++) {
    zona = this->zona(enemigos[i]->obtenerCoordenada());
    enemigos[i]->daniar(this->obtenerDanio(enemigos[i]->obtenerElemento(),zona));
    }
}

void Tierra::defensa(Personaje* aliados[MAX_PERSONAJES]) {
  gastarEnergia(ENERGIA_DEFENSA_TIERRA);
  asignarEscudo(this->escudo + 2);
  defensaActivada = true;
}

void Tierra::reseteoDefensa() {
	if (defensaActivada){
		asignarEscudo(this->escudo - 2);
		defensaActivada = false;
	}
}

bool Tierra::puedeAtacar(){
	if(this->energia >= ENERGIA_ATAQUE_TIERRA)
		return true;
	else
		return false;	
}

bool Tierra::puedeDefender(){
	if(this->energia >= ENERGIA_DEFENSA_TIERRA)
		return true;
	else
		return false;	
}
