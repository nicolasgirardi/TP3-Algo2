#ifndef SUBMENUUNO_H_INCLUDED
#define SUBMENUUNO_H_INCLUDED

#include "menu.h"

class SubmenuUno : public Menu {
 public:
  SubmenuUno();

  // POST: muestra el menu por pantalla
  void mostrarMenu();

  // POST: lleva a cabo la alimentación de un personaje a elección
  void alimentarPersonaje(Personaje* personaje);


  void moverPersonaje(Mapa* mapa, Personaje* personaje, Costos* costos);

  Costos* determinarCosto(string elemento, Costos* costos[4]);

  // POST: ejecuta la opcion elegida.
  void ejecutarOpcion(Mapa* mapa, Personaje* personaje, Costos* costos[4]);

  ~SubmenuUno();
};

#endif  // SUBMENUUNO_H_INCLUDED
