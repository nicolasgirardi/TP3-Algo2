#ifndef LAGO_H
#define LAGO_H
#include "casilla.h"

class Lago : public Casilla {
 private:
  string tipo;
  int costo;

 public:
  // PRE:
  // POS: construje una casilla de lago

  Lago();

  // PRE:
  // POS: devuelve el tipo de la casilla

  string Tipo();

  // PRE:
  // POS: devuelve el costo de llegar

  int obtenerCosto(string elemento);
};

#endif  // LAGO_H