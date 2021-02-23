#ifndef MAIN_CPP_AIRE_H
#define MAIN_CPP_AIRE_H
#include "personaje.h"

class Aire : public Personaje {
 private:
  string elemento;
  string alimento;
  bool defensaActivada;

 public:
  // PRE: escudo = 0, 1 ó 2 ;  10 <= vida <= 100
  // POST: construye un personaje de aire con el nombre, escudo, energía y vida
  // adecuados.
  Aire(string nombre, int escudo, int vida, int fila, int columna);

  // POST: devuelve el elemento del personaje
  string obtenerElemento();

  // calcula el da�o segun el elemento del personaje objetivo
  // POS: devuelve el da�o que le hace al objetivo
  int obtenerDanio(string elemento);

  // POST: imprime un mensaje comunicando que los personajes de aire no se
  // pueden alimentar
  void alimentar();

  // POST: devuelve un string vacío porque los personajes de aire no tienen
  // alimentos
  string obtenerAlimento();

  // Realiza el ataque
  // PRE: debe tener energia suficiente para atacar
  // POS: ejecuta su acaque sobre el equipo enemigo
  void ataque(Personaje* enemigos[]);

  // Realiza la defensa
  // PRE: debe tener energia suficiente para atacar
  // POST: ejecuta la defensa del personaje propio.
  void defensa();
};

#endif  // MAIN_CPP_AIRE_H
