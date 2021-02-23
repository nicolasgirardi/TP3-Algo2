#ifndef VACIO_H
#define VACIO_H
#include "casilla.h"

class Vacio : public Casilla {
 private:
  string tipo;
  int costo;

 public:
  // PRE:
  // POS: construje una casilla de vacio

  Vacio();

  // PRE:
  // POS: devuelve el tipo de la casilla

  string Tipo();

  // PRE:
  // POS: devuelve el costo de llegar

  int obtenerCosto(string elemento);
};

#endif  // VACIO_H
