#ifndef VOLCAN_H
#define VOLCAN_H
#include "casilla.h"

class Volcan : public Casilla {
 private:
  string tipo;
  int costo;

 public:
  // PRE:
  // POS: construje una casilla de volcan

  Volcan();

  // PRE:
  // POS: devuelve el tipo de la casilla

  string Tipo();

  // PRE:
  // POS: devuelve el costo de llegar

  int obtenerCosto(string elemento);
};

#endif  // VOLCAN_H
