#include "fuego.h"

Fuego::Fuego(string nombre, int escudo, int vida): Personaje(nombre, escudo, vida) {
	alimento = "madera";
}

string Fuego::obtenerElemento() { return "fuego"; }

string Fuego::obtenerAlimento() { return alimento; }

void Fuego::alimentar() {
	int vidaSuministrada = 0;
  	int energiaSuministrada = 0;

  	asignarVida(this->vida + AUMENTO_FUEGO);
  	asignarEnergia(this->energia + ENERGIA_LIMITE);
  	cout << "has alimentado a " << this->nombre << " con exito." << endl;
  	cout << "Su vida y energia han aumentado a " << this->vida << " y " << this->energia << " respectivamente." << endl;
  	cout << "Te sientes un poco quemado luego de esto." << endl;
}

int Fuego::obtenerDanio(string elemento) {
	int danio = 20;
  	if (elemento == "aire")
    	danio += 10;
  	else if (elemento == "agua")
    	danio -= 10;
  	return danio;
}

void Fuego::ataque(Personaje* enemigos[MAX_PERSONAJES]) {
  	gastarEnergia(ENERGIA_ATAQUE_FUEGO);
  	for (int i = 0; i < MAX_PERSONAJES; i++) {
    	if (abs(this->coordenada.obtenerFila() - enemigos[i]->obtenerCoordenada()->obtenerFila()) <= 1) {
      		enemigos[i]->daniar(this->obtenerDanio(enemigos[i]->obtenerElemento()));
      		cout << this->nombre << " ataco a " << enemigos[i]->obtenerNombre() << " y quedo con " << enemigos[i]->obtenerVida() << " de vida." << endl << endl;
		}
	}
}

void Fuego::defensa(Personaje* aliados[MAX_PERSONAJES]) {
	gastarEnergia(ENERGIA_DEFENSA_FUEGO);
	asignarVida(this->vida + 10);
	cout << this->nombre << " se curo y ahora tiene " << this->vida << " de vida." << endl << endl;
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
