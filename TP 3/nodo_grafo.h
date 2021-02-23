#ifndef NODO_GRAFO_H_INCLUDED
#define NODO_GRAFO_H_INCLUDED

#include "casilla.h"

typedef Casilla* casillaPtr;

class nodoGrafo {
 private:
  casillaPtr dato;
  nodoGrafo* arriba;
  nodoGrafo* abajo;
  nodoGrafo* derecha;
  nodoGrafo* izquierda;

 public:
  // POST: crea un nodo con dato = d y siguiente = 0
  nodoGrafo(casillaPtr d);

  // POST: cambia el dato con el pasado por parámetro
  void cambiarDato(casillaPtr d);

  // POST: cambia el puntero arriba para que apunte a lo pasado por parámetro
  void cambiarArriba(nodoGrafo* s);

  // POST: cambia el puntero abajo para que apunte a lo pasado por parámetro
  void cambiarAbajo(nodoGrafo* s);

  // POST: cambia el puntero derecha para que apunte a lo pasado por parámetro
  void cambiarDerecha(nodoGrafo* s);

  // POST: cambia el puntero izquierda para que apunte a lo pasado por parámetro
  void cambiarIzquierda(nodoGrafo* s);

  // POST: devuelve el dato del nodo
  casillaPtr obtenerDato();

  // POST: devuelve el puntero que apunta al nodo arriba
  nodoGrafo* obtenerArriba();

  // POST: devuelve el puntero que apunta al nodo abajo
  nodoGrafo* obtenerAbajo();

  // POST: devuelve el puntero que apunta al nodo derecha
  nodoGrafo* obtenerDerecha();

  // POST: devuelve el puntero que apunta al nodo izquierda
  nodoGrafo* obtenerIzquierda();
};

#endif  // NODO_GRAFO_H_INCLUDED
