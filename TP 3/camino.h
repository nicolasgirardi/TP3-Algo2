#ifndef CAMINO_H
#define CAMINO_H
#include "casilla.h"

class Camino : public Casilla {
 private:
  int costo;

 public:
  // PRE:
  // POS: construje una casilla de camino

  Camino();

  // PRE:
  // POS: devuelve el tipo de la casilla

  string Tipo();

  // PRE:
  // POS: devuelve el costo de llegar

  int obtenerCosto(string elemento);
};

#endif  // CAMINO_H
