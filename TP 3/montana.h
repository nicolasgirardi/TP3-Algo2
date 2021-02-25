#ifndef MONTANA_H
#define MONTANA_H
#include "casilla.h"

class Montana : public Casilla {
 private:
  int costo;

 public:
  // PRE:
  // POS: construje una casilla de monta�a

  Montana();

  // PRE:
  // POS: devuelve el tipo de la casilla

  string Tipo();

  // PRE:
  // POS: devuelve el costo de llegar

  int obtenerCosto(string elemento);
};

#endif  // MONTANA_H
