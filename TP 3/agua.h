#ifndef MAIN_CPP_AGUA_H
#define MAIN_CPP_AGUA_H
#include "personaje.h"

class Agua : public Personaje {
 private:
  string alimento;
  int vecesAlimentado;

 public:
  // PRE: escudo = 0, 1 ó 2 ;  10 <= vida <= 100
  // POST: construye un personaje de agua con el nombre, escudo, energía y vida
  // adecuados
  Agua(string nombre, int escudo, int vida);

  // POST: deja al personaje alimentado, con 10 puntos más de energía. La
  // energía no superará los 20 puntos. Solo se puede alimentar 3 veces a cada
  // personaje de agua.
  void alimentar();

  // POST: devuelve el elemento del personaje
  string obtenerElemento();
 
  bool filaValida(int fila);
 
  bool columnaValida(int columna);
  
  void pedirFila(int* fila);
   
  void pedirColumna(int* columna);

 

  // Pide un objetivo a atacar
  // PRE: debe tener energia suficiente para atacar
  // POS: carga el objetivo de ataque en un objeto de clase coordenada
  void pedirObjetivo(Coordenada* lugar);

  // Calcula el danio segun el elemento del personaje objetivo
  // POS: devuelve el da�o que le hace al objetivo
  int obtenerDanio(string elemento);

  // POST: devuelve el alimento del personaje
  string obtenerAlimento();

  // Realiza el ataque
  // PRE: debe tener energia suficiente para atacar
  // POS: ejecuta su acaque sobre el equipo enemigo
  void ataque(Personaje* enemigos[]);

  // Realiza la defensa
  // PRE: debe tener energia suficiente para atacar
  // POST: ejecuta la defensa sobre el equipo aliado y sobre si mismo.
  void defensa(Personaje* aliados[]);
  
  //dice si el personaje tiene energia suficiente para atacar
  //PRE:
  //POS: devuelve true si tiene energia para atacar
    
  bool puedeAtacar();
  
  //dice si el personaje tiene energia suficiente para defender
  //PRE:
  //POS: devuelve true si tiene energia para defender
  
  bool puedeDefender();
};

#endif  // MAIN_CPP_AGUA_H
