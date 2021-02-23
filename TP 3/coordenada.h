#ifndef COORDENADA_H_INCLUDED
#define COORDENADA_H_INCLUDED

#include "libraries.h"

class Coordenada {
 private:
  int fila;
  int columna;

 public:
  // recibe 2 numeros y crea esa coordenada
  // PRE: fila y columna deben ser entre 1 y 8 y caso particular ambas 0
  // POS: constructor, ambas cero se debe entender como que no est� en tablero
  Coordenada(int fila, int columna);

  // recibe un numero y crea la coordenada correspondiente
  // PRE: el numero debe estar entre 0 y 63
  // POS: constructor
  Coordenada(int coordenada);

  // devuelve la fila
  // PRE:
  // POS: devuelve la fila
  int obtenerFila();

  // devuelve la columna
  // PRE:
  // POS: devuelve la columna
  int obtenerColumna();

  // devuelve la coordenada en 1 solo numero
  // PRE:
  // POS:devuelve la coordenada en 1 solo numero siendo
  // num igual a (fila-1)/8 + (columna-1)%8 (entre 0 y 63)

  int obtenerCoordenada();

  // cambia la fila
  // PRE: fila debe ser entre 1 y 8
  // POS: cambia la fila
  void cambiarFila(int fila);

  // cambia la columna
  // PRE:columna debe ser entre 1 y 8
  // POS: cambia la columna
  void cambiarColumna(int columna);
  
  // cambia la fila y la columna
  // PRE: fila y columna debe ser entre 1 y 8
  // POS: cambia la fila y columna
  void cambiarFilaYColumna(int fila,int columna);

  // cambia la coordenada con 1 solo numero
  // PRE: coordenada debe ser entre 0 y 63
  // POS:cambia la coordenada con 1 solo numero

  void cambiarCoordenada(int coordenada);

  // compara 2 coordenadas y dice si son iguales
  // PRE:
  // POS: devuelve true si ambas coordenadas son iguales

  bool comparar(Coordenada* coor);

  ~Coordenada();
};

#endif  // COORDENADA_H_INCLUDED
