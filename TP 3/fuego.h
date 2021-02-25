#ifndef MAIN_CPP_FUEGO_H
#define MAIN_CPP_FUEGO_H
#include "personaje.h"

class Fuego : public Personaje {
 private:
  string alimento;
  string elemento;

 public:
  // PRE: escudo = 0, 1 ó 2 ;  10 <= vida <= 100
  // POST: construye un personaje de fuego con el nombre, escudo, energía y vida
  // adecuados
  Fuego(string nombre, int escudo, int vida, int fila, int columna);

  // POST: deja el personaje alimentado, con 15 puntos más de vida. La vida no
  // superará los 100 puntos.
  void alimentar();

  // POST: devuelve el elemento del personaje
  string obtenerElemento();

  // POST: devuelve el alimento del personaje
  string obtenerAlimento();

  // calcula el da�o segun el elemento del personaje objetivo
  // PRE:
  // POS: devuelve el da�o que le hace al objetivo
  int obtenerDanio(string elemento);

  // Realiza el ataque
  // PRE: debe tener energia suficiente para atacar
  // POS: ejecuta su acaque sobre el equipo enemigo
  void ataque(Personaje* enemigos[]);

  // Realiza la defensa
  // PRE: debe tener energia suficiente para atacar
  // POST: ejecuta la defensa del personaje propio.
  void defensa();
  
  //dice si el personaje tiene energia suficiente para atacar
  //PRE:
  //POS: devuelve true si tiene energia para atacar
    
  bool puedeAtacar();
  
  //dice si el personaje tiene energia suficiente para defender
  //PRE:
  //POS: devuelve true si tiene energia para defender
  
  bool puedeDefender();  
};

#endif  // MAIN_CPP_FUEGO_H
