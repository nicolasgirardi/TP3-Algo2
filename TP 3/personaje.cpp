#include "personaje.h"

Personaje::Personaje(string nombre, int escudo, int vida) {
  srand(time(0));
  this->nombre = nombre;
  this->escudo = escudo;
  this->vida = vida;
  this->energia = rand() % 21;
  this->jugando = false;

}

int Personaje::obtenerEscudo() { return escudo; }

string Personaje::obtenerNombre() { return nombre; }

int Personaje::obtenerEnergia() { return energia; }

int Personaje::obtenerVida() { return vida; }

Coordenada* Personaje::obtenerCoordenada() { return &coordenada; }

bool Personaje::obtenerCondicion() { return jugando; }

void Personaje::asignarEscudo(int escudoNuevo) { escudo = escudoNuevo; }

void Personaje::asignarEnergia(int energiaNueva) {
    if(energiaNueva < TOPE_ENERGIA)
        energia = energiaNueva;
    else
        energia = TOPE_ENERGIA;
}

void Personaje::asignarVida(int vidaNueva) {
    if(vida < TOPE_VIDA)
        vida = vidaNueva;
    else
        vida = TOPE_VIDA;
}

void Personaje::asignarCoordenada(int fila,int columna) {
  coordenada.cambiarFilaYColumna(fila,columna);
}

void Personaje::asignarCondicion(bool condicion) { jugando = condicion; }

bool Personaje::energiaValida(int energiaGastada) {
  int nuevaEnergia;
  nuevaEnergia = this->energia - energiaGastada;
  if (nuevaEnergia >= 0) {
    return true;
  }
  return false;
}

void Personaje::gastarEnergia(int energiaGastada) {
  this->energia = this->energia - energiaGastada;
}

void Personaje::daniar(int daniar) {
  if (this->escudo == 1)
    daniar = daniar * 0.9;
  else if (this->escudo == 2)
    daniar = daniar * 0.8;
  else if (this->escudo > 2)
    daniar = daniar * 0.2;
  this->vida = this->vida - daniar;
    if(this->vida < 0)
        this->vida = 0;
}

void Personaje::reseteoDefensa(){}

void Personaje::recuperarEnergia(){}

Personaje::~Personaje(){

}

