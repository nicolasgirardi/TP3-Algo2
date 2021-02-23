#include "nodo_grafo.h"

nodoGrafo::nodoGrafo(casillaPtr d) {
    dato = d;
    arriba = 0;
    abajo = 0;
    derecha = 0;
    izquierda = 0;
}

void nodoGrafo::cambiarDato(casillaPtr d) {
    dato = d;
}

void nodoGrafo::cambiarArriba(nodoGrafo* s){
	arriba = s;
}

void nodoGrafo::cambiarAbajo(nodoGrafo* s){
	abajo = s;
}

void nodoGrafo::cambiarDerecha(nodoGrafo* s){
	derecha = s;
}

void nodoGrafo::cambiarIzquierda(nodoGrafo* s){
	izquierda = s;
}
casillaPtr nodoGrafo::obtenerDato() {
    return dato;
}

nodoGrafo* nodoGrafo::obtenerArriba(){
	return arriba;
}

nodoGrafo* nodoGrafo::obtenerAbajo(){
	return abajo;
}

nodoGrafo* nodoGrafo::obtenerDerecha(){
	return derecha;
}

nodoGrafo* nodoGrafo::obtenerIzquierda(){
	return izquierda;
}
