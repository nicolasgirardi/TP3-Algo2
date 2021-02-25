#ifndef MAIN_CPP_AIRE_H
#define MAIN_CPP_AIRE_H
#include "personaje.h"

class Aire : public Personaje {
 private:
  string alimento;
  bool defensaActivada;

 public:
  // PRE: escudo = 0, 1 ó 2 ;  10 <= vida <= 100
  // POST: construye un personaje de aire con el nombre, escudo, energía y vida
  // adecuados.
  Aire(string nombre, int escudo, int vida);

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
  void ataque(Personaje* enemigos[MAX_PERSONAJES]);

  // Realiza la defensa
  // PRE: debe tener energia suficiente para atacar
  // POST: ejecuta la defensa del personaje propio.
  void defensa(Personaje* aliados[MAX_PERSONAJES]);
  
  //resetea variables relacionadas a la defensa
  //PRE:
  //POS: resetea a falso variables relacionadas con la defensa
  
  void reseteoDefensa();
  
  //dice si el personaje tiene energia suficiente para atacar
  //PRE:
  //POS: devuelve true si tiene energia para atacar
    
  bool puedeAtacar();
  
  //dice si el personaje tiene energia suficiente para defender
  //PRE:
  //POS: devuelve true si tiene energia para defender
  
  bool puedeDefender();  
};

#endif  // MAIN_CPP_AIRE_H
