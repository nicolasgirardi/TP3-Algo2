#ifndef TP2_TIERRA_H
#define TP2_TIERRA_H
#include "personaje.h"

class Tierra : public Personaje {
 private:
  string alimento;
  bool defensaActivada;

 public:
  // PRE: escudo = 0, 1 ó 2 ;  10 <= vida <= 100
  // POST: construye un personaje de tierra con el nombre, escudo, energía y
  // vida adecuados
  Tierra(string nombre, int escudo, int vida);

  // POST: deja al personaje alimentado, aumentando 8 puntos de energía. La
  // energía no superará los 20 puntos.
  void alimentar();

  // POST: devuelve el elemento del personaje
  string obtenerElemento();

  // POST: devuelve el alimento del personaje
  string obtenerAlimento();

  // recibe una coordenada y devuelve la zona a la que corresponde para el
  // ataque PRE: debe tener energia suficiente para atacar POS: devuelve la zona
  // donde cae el ataque

  int zona(Coordenada* objetivo);

  // devuelve el da�o segun elemento enemigo y la zona donde se encuentra
  // PRE:
  // POS:devuelve el da�o hecho
  int obtenerDanio(string elemento, int zona);

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

#endif  // TP2_TIERRA_H
