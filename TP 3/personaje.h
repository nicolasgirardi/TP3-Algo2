#ifndef TP2_PERSONAJE_H
#define TP2_PERSONAJE_H
#include "coordenada.h"
#include "libraries.h"

class Personaje {
 protected:
  string nombre;
  int escudo;
  int vida;
  int energia;
  Coordenada coordenada;
  bool jugando;

 public:
  // PRE: escudo = 0, 1 ó 2 ;  10 <= vida <= 100
  // POST: construye un personaje con el nombre, escudo, energía y vida
  // adecuados
  Personaje(string nombre, int escudo, int vida, int fila, int columna);

  // POST: devuelve el nombre del personaje
  string obtenerNombre();

  // POST: devuelve el valor del escudo del personaje
  int obtenerEscudo();

  // POST: devuelve el valor de vida del personaje
  int obtenerVida();

  // POST: devuelve el valor de energía del personaje
  int obtenerEnergia();

  // POST devuelve la coordenada como objeto
  Coordenada* obtenerCoordenada();

  // POST: devuelve si el personaje esta jugando o no.
  bool obtenerCondicion();

  // POST: asigna un nuevo escudo al personaje.
  void asignarEscudo(int escudoNuevo);

  // POST: asigna una nueva energia al personaje.
  void asignarEnergia(int energiaNueva);

  // POST: asigna una nueva vida al personaje.
  void asignarVida(int vidaNueva);

  // POST: asigna una nueva coordenada de la posicion del personaje en el mapa.
  void asignarCoordenada(int fila,int columna);

  // POST: asigna el valor de condicion del personaje, si es que el personaje
  // esta en juego o no.
  void asignarCondicion(bool condicion);

  // Recibe un valor de energia para gastar
  // POST: devuelve verdadero si la energia del personaje menos esa energia
  // gastada es valida.
  bool energiaValida(int energiaGastada);

  // Recibe la energia que se gasta.
  // POST: le resta la energia ingresada a la energia del propio personaje
  void gastarEnergia(int energiaGastada);

  void mover();

  virtual string obtenerElemento() = 0;

  virtual string obtenerAlimento() = 0;

  // POST: deja al personaje alimentado
  virtual void alimentar() = 0;

  // Realiza el ataque
  // PRE: debe tener energia suficiente para atacar
  // POS: ejecuta su acaque sobre el equipo enemigo
  virtual void ataque(Personaje* enemigos[]) = 0;

  // le quita la vida al personaje segun su escudo y el da�o base que recibe
  // PRE:
  // POS:le quita vida al personaje segun su escudo y el da�o base que recibe

  void daniar(int daniar);
  
  virtual void defensa() = 0;
  
  //resetea variables relacionadas a la defensa
  //PRE:
  //POS: resetea a falso variables relacionadas con la defensa
  
  virtual void reseteoDefensa();
  
  virtual void puedeAtacar() = 0;
  
  virtual void puedeDefender() = 0;

  virtual ~Personaje();
};

#endif  // TP2_PERSONAJE_H
