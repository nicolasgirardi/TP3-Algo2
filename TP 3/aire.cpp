#include "aire.h"

Aire::Aire(string nombre, int escudo, int vida): Personaje(nombre, escudo, vida) {
	alimento = "aire";
	defensaActivada = false;
}

void Aire::alimentar() {
	cout << "No se pueden alimentar los personajes de aire" << endl;
}

string Aire::obtenerElemento() { return "aire"; }

string Aire::obtenerAlimento() { return "Este personaje no se puede alimentar"; }

int Aire::obtenerDanio(string elemento) {
	int danio = 15;
	if (elemento == "tierra")
		danio += 5;
	else if (elemento == "fuego")
		danio -= 5;
	return danio;
}

void Aire::recuperarEnergia(){
    asignarEnergia(this->energia + ENERGIA_TURNO);
}

void Aire::ataque(Personaje* enemigos[MAX_PERSONAJES]) {
	gastarEnergia(ENERGIA_ATAQUE_AIRE);
	for (int i = 0; i < MAX_PERSONAJES; i++) {
        if (enemigos[i]->obtenerVida() > 0) {
            enemigos[i]->daniar(this->obtenerDanio(enemigos[i]->obtenerElemento()));
            cout << this->nombre << " ataco a " << enemigos[i]->obtenerNombre() << " y quedo con "
                 << enemigos[i]->obtenerVida() << " de vida." << endl << endl;
        }
	}
}

void Aire::defensa(Personaje* aliados[MAX_PERSONAJES]) {
	gastarEnergia(ENERGIA_DEFENSA_AIRE);
	this->defensaActivada = true;
}

void Aire::reseteoDefensa(){
	if(defensaActivada)
		defensaActivada = false;
}

bool Aire::puedeAtacar(){
	if(this->energia >= ENERGIA_ATAQUE_AIRE)
		return true;
	else
		return false;	
}

bool Aire::puedeDefender(){
	if(this->energia >= ENERGIA_DEFENSA_AIRE)
		return true;
	else
		return false;	
}
