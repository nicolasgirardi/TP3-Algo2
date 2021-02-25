#include "coordenada.h"

Coordenada::Coordenada() {
    this->fila = 0;
    this->columna = 0;
}

Coordenada::Coordenada(int fila, int columna) {
  this->fila = fila;
  this->columna = columna;
}

Coordenada::Coordenada(int coordenada) {
  fila = 1 + (coordenada / 8);
  columna = 1 + (coordenada % 8);
}

int Coordenada::obtenerFila() { return fila; }

int Coordenada::obtenerColumna() { return columna; }

int Coordenada::obtenerCoordenada() {
  return ((fila - 1) / 8) + ((columna - 1) % 8);
}

void Coordenada::cambiarFila(int fila) { this->fila = fila; }

void Coordenada::cambiarColumna(int columna) { this->columna = columna; }

void Coordenada::cambiarFilaYColumna(int fila,int columna){
	cambiarFila(fila);
	cambiarColumna(columna);
}

void Coordenada::cambiarCoordenada(int coordenada) {
  fila = 1 + (coordenada / 8);
  columna = 1 + (coordenada % 8);
}

bool Coordenada::comparar(Coordenada* coor) {
  if (this->obtenerCoordenada() == coor->obtenerCoordenada())
    return true;
  else
    return false;
}

Coordenada::~Coordenada(){

}
