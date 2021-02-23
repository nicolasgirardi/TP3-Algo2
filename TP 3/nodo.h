#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "personaje.h"

typedef Personaje* Dato;

class Nodo {
 private:
  Dato dato;
  Nodo* derecho;
  Nodo* izquierdo;
  Nodo* padre;
  string clave;

 public:
  // POST: crea un nodo con dato = d y siguiente = 0
  Nodo(Dato d);

  // POST: cambia el dato con el pasado por parámetro
  void cambiarDato(Dato d);

  // POST: recibe un nodo y lo asigna a nodo izquierdo
  void asignarIzquierdo(Nodo* s);

  // POST: recibe un nodo y lo asigna a nodo derecho
  void asignarDerecho(Nodo* s);

  // POST: recibe un nodo y lo asigna a nodo padre
  void asignarPadre(Nodo* s);

  // POST: recibe un string y lo asigna como clave
  void asignarClave(string claveNueva);

  // POST: devuelve el dato del nodo
  Dato obtenerDato();

  // POST: devuelve el puntero que apunta al siguiente nodo
  Nodo* obtenerDerecho();

  // POST: devuelve el puntero que apunta al siguiente nodo
  Nodo* obtenerIzquierdo();

  // POST: devuelve la clave del nodo
  string obtenerClave();

  // POST: devuelve el padre del nodo
  Nodo* obtenerPadre();
};

#endif  // NODO_H_INCLUDED
