#ifndef COSTOS_H_INCLUDED
#define COSTOS_H_INCLUDED

#include "mapa.h"
#include "pila.h"

class Costos {
 private:
  int** costo;
  int** recorridos;
  string elemento;

 public:
  // POS: crea la matriz con costos y direcciones segun el elemento que va a
  // cruzar
  Costos(string elemento, Mapa* mapa);

  // POS: cambia la matriz de costo para minimizarlos y actualiza la matriz de
  // direcciones
  void minimizar();

  // Recibe 2 coordenadas, inicial y final, y devuelve el costo de ir de la
  // primera a la segunda
  // PRE: recibe 2 coordenadas validas
  // POS: devuelve el costo de ir de la primera a la segunda coordenada
  int consultarCosto(Coordenada* inicial, Coordenada* final);

  // Recibe 2 coordenadas, inicial y final, junto a un puntero a una pila vacia
  // y devuelve una pila con el camino
  // incluyendo tanto la coordenada final como inicial
  // pre: las 2 coordenadas deben ser distintas
  // POS: devuelve la pila modificada
  void consultarCaminoMinimo(Pila* camino, Coordenada* inicial,
                             Coordenada* final);

  // Destructor
  ~Costos();
};

#endif  // COSTOS_H_INCLUDED
