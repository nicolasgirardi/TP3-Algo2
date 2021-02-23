#ifndef PRESIPICIO_H
#define PRESIPICIO_H
#include "casilla.h"

class Precipicio : public Casilla {
 private:
  string tipo;
  int costo;

 public:
  // PRE:
  // POS: construje una casilla de precipicio

  Precipicio();

  // PRE:
  // POS: devuelve el tipo de la casilla

  string Tipo();

  // PRE:
  // POS: devuelve el costo de llegar

  int obtenerCosto(string elemento);
};

#endif  // PRESIPICIO_H
