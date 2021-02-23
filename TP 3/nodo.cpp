#include "nodo.h"

Nodo::Nodo(Dato d) {
  dato = d;
  clave = d->obtenerNombre();
  derecho = 0;
  izquierdo = 0;
  padre = 0;
}

void Nodo::cambiarDato(Dato d) { dato = d; }

void Nodo::asignarIzquierdo(Nodo* s) { izquierdo = s; }

void Nodo::asignarDerecho(Nodo* s) { derecho = s; }

void Nodo::asignarPadre(Nodo* s) { padre = s; }

void Nodo::asignarClave(string claveNueva) { this->clave = claveNueva; }

Dato Nodo::obtenerDato() { return dato; }

string Nodo::obtenerClave() { return clave; }

Nodo* Nodo::obtenerDerecho() { return derecho; }

Nodo* Nodo::obtenerPadre() { return padre; }

Nodo* Nodo::obtenerIzquierdo() { return izquierdo; }
