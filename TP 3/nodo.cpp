#include "nodo.h"

Nodo::Nodo(Dato d) {
  this->dato = d;
  this->clave = d->obtenerNombre();
  asignarIzquierdo(nullptr);
  asignarDerecho(nullptr);
  asignarPadre(nullptr);
}

void Nodo::cambiarDato(Dato d) { this->dato = d; }

void Nodo::asignarIzquierdo(Nodo* s) { this->izquierdo = s; }

void Nodo::asignarDerecho(Nodo* s) { this->derecho = s; }

void Nodo::asignarPadre(Nodo* s) { this->padre = s; }

void Nodo::asignarClave(string claveNueva) { this->clave = claveNueva; }

Dato Nodo::obtenerDato() { return dato; }

string Nodo::obtenerClave() { return clave; }

Nodo* Nodo::obtenerDerecho() { return derecho; }

Nodo* Nodo::obtenerPadre() { return padre; }

Nodo* Nodo::obtenerIzquierdo() { return izquierdo; }
