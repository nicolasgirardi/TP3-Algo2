#ifndef SUBMENUDOS_H_INCLUDED
#define SUBMENUDOS_H_INCLUDED

#include "menu.h"

class SubmenuDos: public Menu {
 public:
  SubmenuDos();

  // POST: muestra el menu por pantalla
  void mostrarMenu();

  // POST: ejecuta la opcion elegida.
  void ejecutarOpcion(Personaje* personaje, Personaje* enemigos[MAX_PERSONAJES],Personaje* aliados[MAX_PERSONAJES]);

  void moverGratis(Mapa* mapa, Personaje* personaje);

  ~SubmenuDos();
};

#endif  // SUBMENUDOS_H_INCLUDED