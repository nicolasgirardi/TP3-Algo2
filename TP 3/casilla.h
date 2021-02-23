#ifndef CASILLA_H_INCLUDED
#define CASILLA_H_INCLUDED

#include "libraries.h"
#include "personaje.h"

class Casilla {
 protected:
  Personaje* ocupante;

 public:
  // PRE:
  // POST: construye una casilla sin ocupante
  Casilla();

  // verifica si la casilla esta ocupada o no
  // PRE:
  // pos:devuelve true si esta ocupada, false si no

  bool Ocupacion();

  // ocupa la casilla con un personaje
  // PRE: Ocupaci�n debe ser falso
  // POS: pone a un personaje que se pasa dentro de la casilla

  void Ocupar(Personaje* personaje);

  // consulta que personaje esta en la casilla
  // PRE: ocupacion debe ser true
  // POS: devuelve el puntero al personaje de la casilla

  Personaje* obtenerPersonaje();

  // vac�a la casilla de quien la ocupe
  // pre:
  // pos: ocupante pasa a apuntar a null

  void Vaciar();

  // devuelve el coste de llegar a esta casilla desde una vecina para cada
  // elemento pre: pos: devuelve el coste de llegar a esta casilla desde una
  // vecina

  virtual int obtenerCosto(string elemento) = 0;
};

#endif  // CASILLA_H_INCLUDED
