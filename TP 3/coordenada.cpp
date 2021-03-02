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

bool Coordenada::filaValida(int fila){
    return (fila >= MINIMO_TABLERO && fila <= MAXIMO_TABLERO);
}

bool Coordenada::columnaValida(int columna){
    return (columna >= MINIMO_TABLERO && columna <= MAXIMO_TABLERO);
}

void Coordenada::pedirFila(int* fila){
	cout << "Ingrese fila: ";
    cin >> *fila;
    while (!filaValida(*fila)){
        cout << "Fila ingresada en el rango incorrecto, debe ingresar una fila entre 1 y 8: ";
        cin >> *fila;
    }
}

void Coordenada::pedirColumna(int* columna){
    cout << "Ingrese columna: ";
    cin >> *columna;
    while (!columnaValida(*columna)){
        cout << "Columna ingresada en el rango incorrecto, debe ingresar una columna entre 1 y 8: ";
        cin >> *columna;
    }
}

void Coordenada::pedirCoordenada() {
    int fila, columna;
    pedirFila(&fila);
    pedirColumna(&columna);
    cambiarFilaYColumna(fila, columna);
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
