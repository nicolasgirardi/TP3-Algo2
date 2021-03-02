#ifndef SUBMENUUNO_H_INCLUDED
#define SUBMENUUNO_H_INCLUDED

#include "menu.h"

class SubmenuUno : public Menu {
 public:
 
  //POST: crea el objeto submenuuno
  SubmenuUno();

  // POST: muestra el menu por pantalla
  void mostrarMenu();

  // POST: lleva a cabo la alimentación de un personaje a elección
  void alimentarPersonaje(Personaje* personaje);

  //POST: mueve un personaje en el mapa si tiene la energía suficiente
  void moverPersonaje(Mapa* mapa, Personaje* personaje, Costos* costos);

  //POST: devuelve los costos de acuerdo al elemento
  Costos* determinarCosto(string elemento, Costos* costos[4]);

  // POST: ejecuta la opcion elegida.
  void ejecutarOpcion(Mapa* mapa, Personaje* personaje, Costos* costos[4]);

  ~SubmenuUno();
};

#endif  // SUBMENUUNO_H_INCLUDED
